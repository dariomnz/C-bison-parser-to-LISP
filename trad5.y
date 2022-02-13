// Ruben Martin Jimenez, Dario Muñoz Muñoz, g83, grupo practicas 14
%{                          // SECCION 1 Declaraciones de C-Yacc
#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

char temp [2048] ;

#define FF fflush(stdout);    // para forzar la impresion inmediata
char *mi_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
         fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
         fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
         exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}
char *genera_cadena (char *nombre)     // copia el argumento a un
{                                      // string en memoria dinamica
      char *p ;
      int l ;

      l = strlen (nombre)+1 ;
      p = (char *) mi_malloc (l) ;
      strcpy (p, nombre) ;

      return p ;
}

char *genera_tabs(char *texto)
{
    char* temp_tab = malloc(2048);
    int index_result = 0;
    for (int i = 0; i < strlen(texto); i++)
    {   
        if(i==0){
            temp_tab[i] = '\t';
            index_result++;
        }
        temp_tab[index_result] = texto[i]; 
        if(i!= 0 && i!=strlen(texto)-1 && texto[i] == '\n')
        {
            index_result ++;
            temp_tab[index_result] = '\t';
        }
        index_result++;
    }
    return temp_tab;
}

%}

%union {                      // El tipo de la pila tiene caracter dual
      int valor ;             // - valor numerico de un NUMERO
      char *cadena ;          // - para pasar los nombres de IDENTIFES
}

%token <valor> NUMERO         // Todos los token tienen un tipo para la pila
%token <cadena> IDENTIF       // Identificador=variable
%token <cadena> INTEGER       // identifica la definicion de un entero
%token <cadena> STRING
%token <cadena> MAIN          // identifica el comienzo del proc. main
%token <cadena> WHILE         // identifica el bucle while
%token <cadena> IF            // identifica la funcion if
%token <cadena> ELSE          // identifica la funcion else
%token <cadena> FOR           // identifica la funcion for
%token <cadena> PUTS
%token <cadena> PRINTF
%token <cadena> RETURN


%type <cadena> expresion termino operando for_print Decl_Variables Multi_variable 
r_Multi_variable Def_Funciones r_Def_Funciones Funcion_main Funcion_contenido 
r_Funcion_contenido bool_expresion comparate_expresion Funcion_while Funcion_if Funcion_for
asignacion_variable Parametros_funcion r_Parametros_funcion
Parametros_funcion_llamada r_Parametros_funcion_llamada

%right '='                    // es la ultima operacion que se debe realizar
%left '+' '-'                 // menor orden de precedencia
%left '*' '/'                 // orden de precedencia intermedio
%left '%'
%left SIGNO_UNARIO            // mayor orden de precedencia


%token <cadena> AND
%token <cadena> OR
%token <cadena> NOTEQUAL
%token <cadena> EQUAL
%token <cadena> LESS
%token <cadena> LESSEQUAL
%token <cadena> MORE
%token <cadena> MOREEQUAL

%right AND OR                    // es la ultima operacion que se debe realizar
%left EQUAL NOTEQUAL                 // menor orden de precedencia
%left LESS LESSEQUAL MORE MOREEQUAL                 // orden de precedencia intermedio


// Seccion 3 Gramatica - Semantico
%%

axioma:         Decl_Variables Def_Funciones { printf("%s%s\n",$1,$2); }
            ;

Decl_Variables: INTEGER Multi_variable ';' Decl_Variables       { sprintf (temp, "%s%s",$2,$4) ;
                                                                $$ = genera_cadena (temp) ;}
            |   /* lambda */     { $$ = genera_cadena ("");}
            ;
            
Multi_variable: IDENTIF r_Multi_variable                { sprintf (temp, "(setq %s 0)\n%s",$1,$2) ;
                                                            $$ = genera_cadena (temp) ;}
            |   IDENTIF '=' NUMERO r_Multi_variable     { sprintf (temp, "(setq %s %d)\n%s",$1,$3,$4) ;
                                                            $$ = genera_cadena (temp) ;}
            |   IDENTIF '[' NUMERO ']' r_Multi_variable     { sprintf (temp, "(setq %s (make-array %d))\n%s",$1,$3,$5) ;
                                                            $$ = genera_cadena (temp) ;}
            ;

r_Multi_variable: /* lambda */				{ $$ = genera_cadena(""); }
            |   ',' Multi_variable					{ $$ = $2; }
            ;

Def_Funciones: IDENTIF '(' Parametros_funcion ')' '{' Funcion_contenido '}' r_Def_Funciones {sprintf (temp, "(defun %s (%s)\n%s)\n%s",$1,$3,genera_tabs($6),$8) ;
                                                                          $$ = genera_cadena (temp) ;}
               | IDENTIF '(' Parametros_funcion ')' '{' Funcion_contenido  RETURN expresion ';' '}' r_Def_Funciones 
                                                                    {sprintf (temp, "(defun %s (%s)\n%s(return-from %s %s)\n)\n%s",$1,$3,genera_tabs($6),$1,$8,$11) ;
                                                                          $$ = genera_cadena (temp) ;}
                | Funcion_main {$$ = $1;}
                ;

r_Def_Funciones:    /* lambda */				{ $$ = genera_cadena(""); }
                |   Def_Funciones					{$$ = $1;}
                ;

Parametros_funcion: /* lambda */				{ $$ = genera_cadena(""); }
                |   INTEGER IDENTIF r_Parametros_funcion          { sprintf (temp, "%s%s",$2,$3) ;
                                                                    $$ = genera_cadena (temp) ;}
                ;

r_Parametros_funcion: ',' INTEGER IDENTIF r_Parametros_funcion      { sprintf (temp, " %s%s",$3,$4) ;
                                                                    $$ = genera_cadena (temp) ;}
                |   /* lambda */				{ $$ = genera_cadena(""); }
                ;


Funcion_main: MAIN '(' ')' '{' Funcion_contenido '}' { sprintf (temp, "(defun main () \n%s)\n",genera_tabs($5)) ;
                                                       $$ = genera_cadena (temp) ;};

Funcion_contenido:    expresion ';' r_Funcion_contenido		{ sprintf (temp, "%s\n%s",$1,$3) ;
                                              $$ = genera_cadena (temp) ; }
            
            |   INTEGER Multi_variable ';' r_Funcion_contenido              { sprintf (temp, "%s%s",$2,$4) ;
                                                                            $$ = genera_cadena (temp) ;}
            |   asignacion_variable ';' r_Funcion_contenido                  { sprintf (temp, "%s\n%s",$1,$3) ;
                                                                            $$ = genera_cadena (temp) ;}
            |   PRINTF '(' STRING ',' for_print ')' ';' r_Funcion_contenido			{ sprintf (temp, "%s\n%s",$5,$8) ;
                                                                            $$ = genera_cadena (temp) ; }                //funcion print
            |   PUTS '(' STRING ')' ';' r_Funcion_contenido				    { sprintf (temp, "(print \"%s\")\n%s",$3,$6) ;
                                                                            $$ = genera_cadena (temp) ; }                //funcion print literal
            |   Funcion_while r_Funcion_contenido                           { sprintf (temp, "%s\n%s",$1,$2) ;
                                                                            $$ = genera_cadena (temp) ; }
            |   Funcion_if r_Funcion_contenido                              { sprintf (temp, "%s\n%s",$1,$2) ;
                                                                            $$ = genera_cadena (temp) ; }
            |   Funcion_for r_Funcion_contenido                           { sprintf (temp, "%s\n%s",$1,$2) ;
                                                                            $$ = genera_cadena (temp) ; }
            ;


r_Funcion_contenido:         /* lambda */				{ $$ = genera_cadena(""); }
            |   Funcion_contenido					{ $$ = $1; }
            ;

Funcion_while: WHILE '(' bool_expresion ')' '{' Funcion_contenido '}' { sprintf (temp, "(loop while %s do \n%s)",$3,genera_tabs($6)) ;
                                                                            $$ = genera_cadena (temp) ; };

Funcion_if: IF '(' bool_expresion ')' '{' Funcion_contenido '}' { sprintf (temp, "(if %s \n(progn %s)\n)",$3,genera_tabs($6)) ;
                                                                            $$ = genera_cadena (temp) ; }
            | IF '(' bool_expresion ')' '{' Funcion_contenido '}' 
              ELSE '{' Funcion_contenido '}'                    { sprintf (temp, "(if %s \n(progn %s)\n(progn %s)\n)",$3,genera_tabs($6),genera_tabs($10)) ;
                                                                            $$ = genera_cadena (temp) ; }
            ;

Funcion_for: FOR '(' INTEGER Multi_variable ';' bool_expresion ';' asignacion_variable ')' '{' Funcion_contenido '}' 
                                                                { sprintf (temp, "%s(loop while %s do \n%s%s\n)",$4,$6,genera_tabs($11),genera_tabs($8)) ;
                                                                            $$ = genera_cadena (temp) ; }
            | FOR '(' asignacion_variable ';' bool_expresion ';' asignacion_variable ')' '{' Funcion_contenido '}' 
                                                                { sprintf (temp, "%s(loop while %s do \n%s%s\n)",$3,$5,genera_tabs($10),genera_tabs($7)) ;
                                                                            $$ = genera_cadena (temp) ; }
            ;

asignacion_variable: IDENTIF '=' expresion { sprintf (temp, "(setq %s %s)",$1,$3) ;
                                           $$ = genera_cadena (temp) ; }
                   | IDENTIF '[' expresion ']' '=' expresion { sprintf (temp, "(setf (aref %s %s) %s)",$1,$3,$6) ;
                                           $$ = genera_cadena (temp) ; }
            ;

for_print:  expresion                  { sprintf (temp, "(print %s)", $1) ;
                                            $$ = genera_cadena (temp) ; }
            | expresion ',' for_print  { sprintf (temp, "(print %s) %s", $1,$3) ;
                                            $$ = genera_cadena (temp) ; }
            ;

bool_expresion: comparate_expresion                     { $$ = $1; }
            |   bool_expresion AND bool_expresion       { strcpy (temp, "(") ;
                                                        strcat (temp, "And ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            |   bool_expresion OR bool_expresion        { strcpy (temp, "(") ;
                                                        strcat (temp, "or ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            ;

comparate_expresion:  expresion                         { $$ = $1; }
            |         expresion NOTEQUAL expresion      { strcpy (temp, "(") ;
                                                        strcat (temp, "/= ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            |         expresion EQUAL expresion         { strcpy (temp, "(") ;
                                                        strcat (temp, "= ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            |         expresion '<' expresion          { strcpy (temp, "(") ;
                                                        strcat (temp, "< ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            |         expresion LESSEQUAL expresion     { strcpy (temp, "(") ;
                                                        strcat (temp, "<= ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            |         expresion '>' expresion          { strcpy (temp, "(") ;
                                                        strcat (temp, "> ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            |         expresion MOREEQUAL expresion     { strcpy (temp, "(") ;
                                                        strcat (temp, ">= ") ;
                                                        strcat (temp, $1) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, $3) ;
                                                        strcat (temp, ")") ;
                                                        $$ = genera_cadena (temp) ; }
            ;


expresion:      termino					{ $$ = $1; }
            |   expresion '+' expresion   		{ strcpy (temp, "(") ;
                                                strcat (temp, "+ ") ;
                                                strcat (temp, $1) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, $3) ;
                                                strcat (temp, ")") ;
                                                $$ = genera_cadena (temp) ; }
            |   expresion '-' expresion   		{ strcpy (temp, "(") ;
                                                strcat (temp, "- ") ;
                                                strcat (temp, $1) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, $3) ;
                                                strcat (temp, ")") ;
                                                $$ = genera_cadena (temp) ; }
            |   expresion '*' expresion   		{ strcpy (temp, "(") ;
                                                strcat (temp, "* ") ;
                                                strcat (temp, $1) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, $3) ;
                                                strcat (temp, ")") ;
                                                $$ = genera_cadena (temp) ; }
            |   expresion '/' expresion   		{ strcpy (temp, "(") ;
                                                strcat (temp, "/ ") ;
                                                strcat (temp, $1) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, $3) ;
                                                strcat (temp, ")") ;
                                                $$ = genera_cadena (temp) ; }
            |   expresion '%' expresion   		{ strcpy (temp, "(") ;
                                                strcat (temp, "mod ") ;
                                                strcat (temp, $1) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, $3) ;
                                                strcat (temp, ")") ;
                                                $$ = genera_cadena (temp) ; }
            ;

termino:        operando				{ $$ = $1; }                          
            |   '+' operando %prec SIGNO_UNARIO		{ strcpy (temp, "(") ;
                                                    strcat (temp, "+ ") ;
                                                    strcat (temp, $2) ;
                                                    strcat (temp, ")") ;
                                                    $$ = genera_cadena (temp) ; }
            |   '-' operando %prec SIGNO_UNARIO		{ strcpy (temp, "(") ;
                                                    strcat (temp, "- ") ;
                                                    strcat (temp, $2) ;
                                                    strcat (temp, ")") ;
                                                    $$ = genera_cadena (temp) ; }                    
            ;

operando:       IDENTIF				{ sprintf (temp, "%s", $1) ;
                                            $$ = genera_cadena (temp) ; }
            |   NUMERO					{ sprintf (temp, "%d", $1) ;
                                            $$ = genera_cadena (temp) ; }
            |   '(' expresion ')'			{ $$ = $2; }
            |   IDENTIF '[' expresion ']'{ sprintf (temp, "(aref %s %s)", $1,$3) ;
                                            $$ = genera_cadena (temp) ; }
            |   IDENTIF '(' Parametros_funcion_llamada ')'         { sprintf (temp, "(%s %s)", $1,$3) ;
                                            $$ = genera_cadena (temp) ; }
            ;


Parametros_funcion_llamada: /* lambda */				{ $$ = genera_cadena(""); }
                |   expresion r_Parametros_funcion_llamada          { sprintf (temp, "%s%s",$1,$2) ;
                                                                    $$ = genera_cadena (temp) ;}
                ;

r_Parametros_funcion_llamada: ',' expresion r_Parametros_funcion_llamada      { sprintf (temp, " %s%s",$2,$3) ;
                                                                    $$ = genera_cadena (temp) ;}
                |   /* lambda */				{ $$ = genera_cadena(""); }
                ;



%%
                            // SECCION 4    Codigo en C
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
    printf ( "\n") ;	// bye
}




/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_pal_reservadas { // para las palabras reservadas de C
    char *nombre ;
    int token ;
} t_reservada ;

t_reservada pal_reservadas [] = { // define las palabras reservadas
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "while",       WHILE,
    "if",          IF,
    "else",        ELSE,
    "for",         FOR,
    "puts",        PUTS,
    "printf",      PRINTF,
    "return",      RETURN,
    "&&",          AND,
    "||",          OR,
    "!=",          NOTEQUAL,
    "==",          EQUAL,
    "<=",          LESSEQUAL,
    ">=",          MOREEQUAL,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_reservada *busca_pal_reservada (char *nombre_simbolo)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_reservada *sim ;

    i = 0 ;
    sim = pal_reservadas ;
    while (sim [i].nombre != NULL) {
           if (strcmp (sim [i].nombre, nombre_simbolo) == 0) {
                                         // strcmp(a, b) devuelve == 0 si a==b
                 return &(sim [i]) ;
             }
           i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/




int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=>|%&+-/*" ;
    char cadena [256] ;
    t_reservada *simbolo ;

    do {
    	c = getchar () ;

		if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
			do {		//	OJO que puede funcionar mal si una linea contiene #
			 c = getchar () ;	
			} while (c != '\n') ;
		}
		
		if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
			cc = getchar () ;
			if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
				ungetc (cc, stdin) ;
		 } else {
		     c = getchar () ;	// ...
		     if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
		          do {		// Se trata de codigo inline (Codigo embebido en C)
		              c = getchar () ;
		              putchar (c) ;
		          } while (c != '\n') ;
		     } else {		// ==> comentario, ignorar la linea
		          while (c != '\n') {
		              c = getchar () ;
		          }
		     }
		 }
		}
		
		if (c == '\n')
		 n_linea++ ;
		
    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
         i = 0 ;
         do {
             c = getchar () ;
             cadena [i++] = c ;
         } while (c != '\"' && i < 255) ;
         if (i == 256) {
              printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_linea) ;
         }		 	// habria que leer hasta el siguiente " , pero, y si falta?
         cadena [--i] = '\0' ;
         yylval.cadena = genera_cadena (cadena) ;
         return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
//         printf ("\nDEV: NUMERO %d\n", yylval.valor) ;        // PARA DEPURAR
         return NUMERO ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
         i = 0 ;
         while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                 (c >= '0' && c <= '9') || c == '_') && i < 255) {
             cadena [i++] = tolower (c) ;
             c = getchar () ;
         }
         cadena [i] = '\0' ;
         ungetc (c, stdin) ;

         yylval.cadena = genera_cadena (cadena) ;
         simbolo = busca_pal_reservada (yylval.cadena) ;
         if (simbolo == NULL) {    // no es palabra reservada -> identificador 
//               printf ("\nDEV: IDENTIF %s\n", yylval.cadena) ;    // PARA DEPURAR
               return (IDENTIF) ;
         } else {
//               printf ("\nDEV: OTRO %s\n", yylval.cadena) ;       // PARA DEPURAR
               return (simbolo->token) ;
         }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
         cc = getchar () ;
         sprintf (cadena, "%c%c", (char) c, (char) cc) ;
         simbolo = busca_pal_reservada (cadena) ;
         if (simbolo == NULL) {
              ungetc (cc, stdin) ;
              yylval.cadena = NULL ;
              return (c) ;
         } else {
              yylval.cadena = genera_cadena (cadena) ; // aunque no se use
              return (simbolo->token) ;
         }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
         return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}

