/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "trad5.y"
                          // SECCION 1 Declaraciones de C-Yacc
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


#line 131 "trad5.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERO = 258,
    IDENTIF = 259,
    INTEGER = 260,
    STRING = 261,
    MAIN = 262,
    WHILE = 263,
    IF = 264,
    ELSE = 265,
    FOR = 266,
    PUTS = 267,
    PRINTF = 268,
    RETURN = 269,
    SIGNO_UNARIO = 270,
    AND = 271,
    OR = 272,
    NOTEQUAL = 273,
    EQUAL = 274,
    LESS = 275,
    LESSEQUAL = 276,
    MORE = 277,
    MOREEQUAL = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "trad5.y"
                      // El tipo de la pila tiene caracter dual
      int valor ;             // - valor numerico de un NUMERO
      char *cadena ;          // - para pasar los nombres de IDENTIFES

#line 209 "trad5.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    20,     2,     2,
      34,    35,    18,    16,    33,    17,     2,    19,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      38,    15,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      21,    22,    23,    24,    25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   116,   118,   121,   123,   125,   129,   130,
     133,   135,   138,   141,   142,   145,   146,   150,   152,   156,
     159,   162,   164,   166,   168,   170,   172,   174,   179,   180,
     183,   186,   188,   193,   196,   201,   203,   207,   209,   213,
     214,   221,   230,   231,   238,   245,   252,   259,   266,   276,
     277,   284,   291,   298,   305,   314,   315,   320,   327,   329,
     331,   332,   334,   339,   340,   344,   346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "IDENTIF", "INTEGER", "STRING",
  "MAIN", "WHILE", "IF", "ELSE", "FOR", "PUTS", "PRINTF", "RETURN", "'='",
  "'+'", "'-'", "'*'", "'/'", "'%'", "SIGNO_UNARIO", "AND", "OR",
  "NOTEQUAL", "EQUAL", "LESS", "LESSEQUAL", "MORE", "MOREEQUAL", "';'",
  "'['", "']'", "','", "'('", "')'", "'{'", "'}'", "'<'", "'>'", "$accept",
  "axioma", "Decl_Variables", "Multi_variable", "r_Multi_variable",
  "Def_Funciones", "r_Def_Funciones", "Parametros_funcion",
  "r_Parametros_funcion", "Funcion_main", "Funcion_contenido",
  "r_Funcion_contenido", "Funcion_while", "Funcion_if", "Funcion_for",
  "asignacion_variable", "for_print", "bool_expresion",
  "comparate_expresion", "expresion", "termino", "operando",
  "Parametros_funcion_llamada", "r_Parametros_funcion_llamada", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    61,    43,    45,    42,    47,
      37,   270,   271,   272,   273,   274,   275,   276,   277,   278,
      59,    91,    93,    44,    40,    41,   123,   125,    60,    62
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,    60,    54,    98,    13,    41,   -56,    31,    39,   -56,
     -56,    72,    84,    60,   -56,    35,    86,    69,    75,    81,
     -56,   -56,   105,    85,    89,   -56,    75,    94,    93,    44,
     -56,   130,   -56,    44,   -56,   -12,    60,   102,   111,   120,
     127,   128,    11,    11,     9,   147,    44,    44,    44,   155,
     150,   -56,   -56,   184,    -6,     9,     9,     9,   160,     9,
       9,     6,   194,   195,   152,   -56,   -56,    50,   -56,   -56,
     -56,   -56,   -56,    44,     9,     9,     9,     9,     9,    44,
      94,     9,    98,   176,   123,    78,   167,    44,    77,   -56,
      99,   156,    19,    60,   173,   169,   172,     9,   -56,   -56,
     179,   179,   186,   186,   -56,   -56,   -56,   157,   -56,   -56,
     192,     9,   -56,   -56,   -56,     9,     9,   174,     9,     9,
       9,     9,     9,     9,   175,     9,   178,     9,   182,     9,
     133,   177,     9,    78,     1,     1,    44,   176,   176,   176,
     176,   176,   176,    44,   140,     9,   141,    44,   180,   114,
     -56,    98,   176,   -56,   181,   183,   192,   159,   205,   -56,
     187,     9,   -56,   -56,   203,   205,   188,    44,   -56,   185,
     189,   190,   -56,    44,   191,    44,   193,    44,   196,   -56,
     197,   -56,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     8,     0,     1,     0,     0,     2,
      12,     0,     0,     0,     5,     4,    15,     0,     8,     0,
       9,     3,     0,     0,     0,     6,     8,    18,     0,     0,
       7,     0,    16,     0,    59,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    28,    28,     0,
       0,    49,    55,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,    58,    56,    57,     0,    19,    29,
      25,    26,    27,    28,     0,     0,     0,     0,     0,    28,
      18,     0,    13,    35,     0,    66,     0,    28,     0,    39,
      42,     0,     0,     0,     0,     0,     0,     0,    60,    22,
      50,    51,    52,    53,    54,    20,    17,     0,    14,    10,
      61,     0,    64,    62,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    40,    41,     0,    43,    44,    46,
      48,    45,    47,     0,     0,     0,     0,    28,     0,    37,
      61,    13,    36,    65,     0,     0,     0,     0,     0,    24,
       0,     0,    11,    30,    31,     0,     0,    28,    38,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    32,
       0,    34,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   201,    -4,    33,   216,    71,   -56,   145,   -56,
     -29,   -46,   -56,   -56,   -56,   -55,    67,   -53,   -56,   -39,
     -56,   -13,   -56,    96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,    14,   108,   109,    23,    32,    10,
      69,    70,    46,    47,    48,    49,   148,    88,    89,    50,
      51,    52,    86,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    71,    72,    55,    54,    67,    94,    91,    81,    20,
      92,    93,    34,    64,    34,    64,    83,    84,    85,    56,
      90,    90,    57,   115,   116,    42,    43,    99,    11,    65,
      66,    82,    58,   105,    55,   100,   101,   102,   103,   104,
       1,   114,   107,    44,    12,    44,    13,    34,    35,    36,
     125,    25,    37,    38,     6,    39,    40,    41,   130,    30,
      42,    43,   134,   135,     4,    16,    74,    75,    76,    77,
      78,    15,   133,    17,   146,    18,    90,    90,    44,   137,
     138,   139,   140,   141,   142,    98,   144,    19,    90,   126,
     149,    22,   157,   152,    74,    75,    76,    77,    78,   115,
     116,   159,     7,   166,    24,     8,    90,   154,    13,    27,
     170,   111,   117,    26,   155,    74,    75,    76,    77,    78,
      28,   172,   149,   118,   119,    29,   120,    31,   121,    33,
      74,    75,    76,    77,    78,    53,    59,   122,   123,    74,
      75,    76,    77,    78,   176,    60,   178,   161,   180,    74,
      75,    76,    77,    78,    61,   110,    74,    75,    76,    77,
      78,    62,    63,   115,   116,   150,    74,    75,    76,    77,
      78,   158,   156,    74,    75,    76,    77,    78,   115,   116,
      79,   115,   116,    97,    68,    73,    57,   131,    80,   165,
      87,   124,    74,    75,    76,    77,    78,    76,    77,    78,
      95,    96,   113,   127,   128,   129,    78,   132,   145,    92,
     136,   143,   147,   169,   151,   160,    21,   167,   163,     9,
     164,   173,   162,   171,   174,   106,   175,   177,   168,   153,
     179,     0,     0,   181,   182
};

static const yytype_int16 yycheck[] =
{
      29,    47,    48,    15,    33,    44,    61,    60,    14,    13,
       4,     5,     3,     4,     3,     4,    55,    56,    57,    31,
      59,    60,    34,    22,    23,    16,    17,    73,    15,    42,
      43,    37,    36,    79,    15,    74,    75,    76,    77,    78,
       5,    87,    81,    34,    31,    34,    33,     3,     4,     5,
      31,    18,     8,     9,     0,    11,    12,    13,    97,    26,
      16,    17,   115,   116,     4,    34,    16,    17,    18,    19,
      20,    30,   111,    34,   127,     3,   115,   116,    34,   118,
     119,   120,   121,   122,   123,    35,   125,     3,   127,    93,
     129,     5,   145,   132,    16,    17,    18,    19,    20,    22,
      23,   147,     4,   158,    35,     7,   145,   136,    33,     4,
     165,    33,    35,    32,   143,    16,    17,    18,    19,    20,
      35,   167,   161,    24,    25,    36,    27,    33,    29,    36,
      16,    17,    18,    19,    20,     5,    34,    38,    39,    16,
      17,    18,    19,    20,   173,    34,   175,    33,   177,    16,
      17,    18,    19,    20,    34,    32,    16,    17,    18,    19,
      20,    34,    34,    22,    23,    32,    16,    17,    18,    19,
      20,    30,    32,    16,    17,    18,    19,    20,    22,    23,
      30,    22,    23,    31,    37,    30,    34,    30,     4,    30,
      30,    35,    16,    17,    18,    19,    20,    18,    19,    20,
       6,     6,    35,    30,    35,    33,    20,    15,    30,     4,
      36,    36,    30,    10,    37,    35,    15,    30,    37,     3,
      37,    36,   151,    35,    35,    80,    36,    36,   161,   133,
      37,    -1,    -1,    37,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    41,    42,     4,    43,     0,     4,     7,    45,
      49,    15,    31,    33,    44,    30,    34,    34,     3,     3,
      43,    42,     5,    47,    35,    44,    32,     4,    35,    36,
      44,    33,    48,    36,     3,     4,     5,     8,     9,    11,
      12,    13,    16,    17,    34,    50,    52,    53,    54,    55,
      59,    60,    61,     5,    50,    15,    31,    34,    43,    34,
      34,    34,    34,    34,     4,    61,    61,    59,    37,    50,
      51,    51,    51,    30,    16,    17,    18,    19,    20,    30,
       4,    14,    37,    59,    59,    59,    62,    30,    57,    58,
      59,    57,     4,     5,    55,     6,     6,    31,    35,    51,
      59,    59,    59,    59,    59,    51,    48,    59,    45,    46,
      32,    33,    63,    35,    51,    22,    23,    35,    24,    25,
      27,    29,    38,    39,    35,    31,    43,    30,    35,    33,
      59,    30,    15,    59,    57,    57,    36,    59,    59,    59,
      59,    59,    59,    36,    59,    30,    57,    30,    56,    59,
      32,    37,    59,    63,    50,    50,    32,    57,    30,    51,
      35,    33,    46,    37,    37,    30,    55,    30,    56,    10,
      55,    35,    51,    36,    35,    36,    50,    36,    50,    37,
      50,    37,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    45,    46,    46,    47,    47,    48,    48,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    61,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     0,     2,     4,     5,     0,     2,
       8,    11,     1,     0,     1,     0,     3,     4,     0,     6,
       3,     4,     3,     8,     6,     2,     2,     2,     0,     1,
       7,     7,    11,    12,    11,     3,     6,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     2,     2,     1,     1,
       3,     4,     4,     0,     2,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 113 "trad5.y"
                                             { printf("%s%s\n",(yyvsp[-1].cadena),(yyvsp[0].cadena)); }
#line 1508 "trad5.tab.c"
    break;

  case 3:
#line 116 "trad5.y"
                                                                { sprintf (temp, "%s%s",(yyvsp[-2].cadena),(yyvsp[0].cadena)) ;
                                                                (yyval.cadena) = genera_cadena (temp) ;}
#line 1515 "trad5.tab.c"
    break;

  case 4:
#line 118 "trad5.y"
                                 { (yyval.cadena) = genera_cadena ("");}
#line 1521 "trad5.tab.c"
    break;

  case 5:
#line 121 "trad5.y"
                                                        { sprintf (temp, "(setq %s 0)\n%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1528 "trad5.tab.c"
    break;

  case 6:
#line 123 "trad5.y"
                                                        { sprintf (temp, "(setq %s %d)\n%s",(yyvsp[-3].cadena),(yyvsp[-1].valor),(yyvsp[0].cadena)) ;
                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1535 "trad5.tab.c"
    break;

  case 7:
#line 125 "trad5.y"
                                                            { sprintf (temp, "(setq %s (make-array %d))\n%s",(yyvsp[-4].cadena),(yyvsp[-2].valor),(yyvsp[0].cadena)) ;
                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1542 "trad5.tab.c"
    break;

  case 8:
#line 129 "trad5.y"
                                                        { (yyval.cadena) = genera_cadena(""); }
#line 1548 "trad5.tab.c"
    break;

  case 9:
#line 130 "trad5.y"
                                                                        { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1554 "trad5.tab.c"
    break;

  case 10:
#line 133 "trad5.y"
                                                                                            {sprintf (temp, "(defun %s (%s)\n%s)\n%s",(yyvsp[-7].cadena),(yyvsp[-5].cadena),genera_tabs((yyvsp[-2].cadena)),(yyvsp[0].cadena)) ;
                                                                          (yyval.cadena) = genera_cadena (temp) ;}
#line 1561 "trad5.tab.c"
    break;

  case 11:
#line 136 "trad5.y"
                                                                    {sprintf (temp, "(defun %s (%s)\n%s(return-from %s %s)\n)\n%s",(yyvsp[-10].cadena),(yyvsp[-8].cadena),genera_tabs((yyvsp[-5].cadena)),(yyvsp[-10].cadena),(yyvsp[-3].cadena),(yyvsp[0].cadena)) ;
                                                                          (yyval.cadena) = genera_cadena (temp) ;}
#line 1568 "trad5.tab.c"
    break;

  case 12:
#line 138 "trad5.y"
                               {(yyval.cadena) = (yyvsp[0].cadena);}
#line 1574 "trad5.tab.c"
    break;

  case 13:
#line 141 "trad5.y"
                                                                { (yyval.cadena) = genera_cadena(""); }
#line 1580 "trad5.tab.c"
    break;

  case 14:
#line 142 "trad5.y"
                                                                        {(yyval.cadena) = (yyvsp[0].cadena);}
#line 1586 "trad5.tab.c"
    break;

  case 15:
#line 145 "trad5.y"
                                                                { (yyval.cadena) = genera_cadena(""); }
#line 1592 "trad5.tab.c"
    break;

  case 16:
#line 146 "trad5.y"
                                                                  { sprintf (temp, "%s%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                                    (yyval.cadena) = genera_cadena (temp) ;}
#line 1599 "trad5.tab.c"
    break;

  case 17:
#line 150 "trad5.y"
                                                                    { sprintf (temp, " %s%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                                    (yyval.cadena) = genera_cadena (temp) ;}
#line 1606 "trad5.tab.c"
    break;

  case 18:
#line 152 "trad5.y"
                                                                { (yyval.cadena) = genera_cadena(""); }
#line 1612 "trad5.tab.c"
    break;

  case 19:
#line 156 "trad5.y"
                                                     { sprintf (temp, "(defun main () \n%s)\n",genera_tabs((yyvsp[-1].cadena))) ;
                                                       (yyval.cadena) = genera_cadena (temp) ;}
#line 1619 "trad5.tab.c"
    break;

  case 20:
#line 159 "trad5.y"
                                                                { sprintf (temp, "%s\n%s",(yyvsp[-2].cadena),(yyvsp[0].cadena)) ;
                                              (yyval.cadena) = genera_cadena (temp) ; }
#line 1626 "trad5.tab.c"
    break;

  case 21:
#line 162 "trad5.y"
                                                                            { sprintf (temp, "%s%s",(yyvsp[-2].cadena),(yyvsp[0].cadena)) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1633 "trad5.tab.c"
    break;

  case 22:
#line 164 "trad5.y"
                                                                             { sprintf (temp, "%s\n%s",(yyvsp[-2].cadena),(yyvsp[0].cadena)) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ;}
#line 1640 "trad5.tab.c"
    break;

  case 23:
#line 166 "trad5.y"
                                                                                                { sprintf (temp, "%s\n%s",(yyvsp[-3].cadena),(yyvsp[0].cadena)) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1647 "trad5.tab.c"
    break;

  case 24:
#line 168 "trad5.y"
                                                                                            { sprintf (temp, "(print \"%s\")\n%s",(yyvsp[-3].cadena),(yyvsp[0].cadena)) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1654 "trad5.tab.c"
    break;

  case 25:
#line 170 "trad5.y"
                                                                            { sprintf (temp, "%s\n%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1661 "trad5.tab.c"
    break;

  case 26:
#line 172 "trad5.y"
                                                                            { sprintf (temp, "%s\n%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1668 "trad5.tab.c"
    break;

  case 27:
#line 174 "trad5.y"
                                                                          { sprintf (temp, "%s\n%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1675 "trad5.tab.c"
    break;

  case 28:
#line 179 "trad5.y"
                                                                        { (yyval.cadena) = genera_cadena(""); }
#line 1681 "trad5.tab.c"
    break;

  case 29:
#line 180 "trad5.y"
                                                                        { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1687 "trad5.tab.c"
    break;

  case 30:
#line 183 "trad5.y"
                                                                      { sprintf (temp, "(loop while %s do \n%s)",(yyvsp[-4].cadena),genera_tabs((yyvsp[-1].cadena))) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1694 "trad5.tab.c"
    break;

  case 31:
#line 186 "trad5.y"
                                                                { sprintf (temp, "(if %s \n(progn %s)\n)",(yyvsp[-4].cadena),genera_tabs((yyvsp[-1].cadena))) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1701 "trad5.tab.c"
    break;

  case 32:
#line 189 "trad5.y"
                                                                { sprintf (temp, "(if %s \n(progn %s)\n(progn %s)\n)",(yyvsp[-8].cadena),genera_tabs((yyvsp[-5].cadena)),genera_tabs((yyvsp[-1].cadena))) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1708 "trad5.tab.c"
    break;

  case 33:
#line 194 "trad5.y"
                                                                { sprintf (temp, "%s(loop while %s do \n%s%s\n)",(yyvsp[-8].cadena),(yyvsp[-6].cadena),genera_tabs((yyvsp[-1].cadena)),genera_tabs((yyvsp[-4].cadena))) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1715 "trad5.tab.c"
    break;

  case 34:
#line 197 "trad5.y"
                                                                { sprintf (temp, "%s(loop while %s do \n%s%s\n)",(yyvsp[-8].cadena),(yyvsp[-6].cadena),genera_tabs((yyvsp[-1].cadena)),genera_tabs((yyvsp[-4].cadena))) ;
                                                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1722 "trad5.tab.c"
    break;

  case 35:
#line 201 "trad5.y"
                                           { sprintf (temp, "(setq %s %s)",(yyvsp[-2].cadena),(yyvsp[0].cadena)) ;
                                           (yyval.cadena) = genera_cadena (temp) ; }
#line 1729 "trad5.tab.c"
    break;

  case 36:
#line 203 "trad5.y"
                                                             { sprintf (temp, "(setf (aref %s %s) %s)",(yyvsp[-5].cadena),(yyvsp[-3].cadena),(yyvsp[0].cadena)) ;
                                           (yyval.cadena) = genera_cadena (temp) ; }
#line 1736 "trad5.tab.c"
    break;

  case 37:
#line 207 "trad5.y"
                                       { sprintf (temp, "(print %s)", (yyvsp[0].cadena)) ;
                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1743 "trad5.tab.c"
    break;

  case 38:
#line 209 "trad5.y"
                                       { sprintf (temp, "(print %s) %s", (yyvsp[-2].cadena),(yyvsp[0].cadena)) ;
                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1750 "trad5.tab.c"
    break;

  case 39:
#line 213 "trad5.y"
                                                        { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1756 "trad5.tab.c"
    break;

  case 40:
#line 214 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                        strcat (temp, "And ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1768 "trad5.tab.c"
    break;

  case 41:
#line 221 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                        strcat (temp, "or ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1780 "trad5.tab.c"
    break;

  case 42:
#line 230 "trad5.y"
                                                        { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1786 "trad5.tab.c"
    break;

  case 43:
#line 231 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                        strcat (temp, "/= ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1798 "trad5.tab.c"
    break;

  case 44:
#line 238 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                        strcat (temp, "= ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1810 "trad5.tab.c"
    break;

  case 45:
#line 245 "trad5.y"
                                                       { strcpy (temp, "(") ;
                                                        strcat (temp, "< ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1822 "trad5.tab.c"
    break;

  case 46:
#line 252 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                        strcat (temp, "<= ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1834 "trad5.tab.c"
    break;

  case 47:
#line 259 "trad5.y"
                                                       { strcpy (temp, "(") ;
                                                        strcat (temp, "> ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1846 "trad5.tab.c"
    break;

  case 48:
#line 266 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                        strcat (temp, ">= ") ;
                                                        strcat (temp, (yyvsp[-2].cadena)) ;
                                                        strcat (temp, " ") ;
                                                        strcat (temp, (yyvsp[0].cadena)) ;
                                                        strcat (temp, ")") ;
                                                        (yyval.cadena) = genera_cadena (temp) ; }
#line 1858 "trad5.tab.c"
    break;

  case 49:
#line 276 "trad5.y"
                                                        { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1864 "trad5.tab.c"
    break;

  case 50:
#line 277 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                strcat (temp, "+ ") ;
                                                strcat (temp, (yyvsp[-2].cadena)) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, (yyvsp[0].cadena)) ;
                                                strcat (temp, ")") ;
                                                (yyval.cadena) = genera_cadena (temp) ; }
#line 1876 "trad5.tab.c"
    break;

  case 51:
#line 284 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                strcat (temp, "- ") ;
                                                strcat (temp, (yyvsp[-2].cadena)) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, (yyvsp[0].cadena)) ;
                                                strcat (temp, ")") ;
                                                (yyval.cadena) = genera_cadena (temp) ; }
#line 1888 "trad5.tab.c"
    break;

  case 52:
#line 291 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                strcat (temp, "* ") ;
                                                strcat (temp, (yyvsp[-2].cadena)) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, (yyvsp[0].cadena)) ;
                                                strcat (temp, ")") ;
                                                (yyval.cadena) = genera_cadena (temp) ; }
#line 1900 "trad5.tab.c"
    break;

  case 53:
#line 298 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                strcat (temp, "/ ") ;
                                                strcat (temp, (yyvsp[-2].cadena)) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, (yyvsp[0].cadena)) ;
                                                strcat (temp, ")") ;
                                                (yyval.cadena) = genera_cadena (temp) ; }
#line 1912 "trad5.tab.c"
    break;

  case 54:
#line 305 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                strcat (temp, "mod ") ;
                                                strcat (temp, (yyvsp[-2].cadena)) ;
                                                strcat (temp, " ") ;
                                                strcat (temp, (yyvsp[0].cadena)) ;
                                                strcat (temp, ")") ;
                                                (yyval.cadena) = genera_cadena (temp) ; }
#line 1924 "trad5.tab.c"
    break;

  case 55:
#line 314 "trad5.y"
                                                        { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1930 "trad5.tab.c"
    break;

  case 56:
#line 315 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                    strcat (temp, "+ ") ;
                                                    strcat (temp, (yyvsp[0].cadena)) ;
                                                    strcat (temp, ")") ;
                                                    (yyval.cadena) = genera_cadena (temp) ; }
#line 1940 "trad5.tab.c"
    break;

  case 57:
#line 320 "trad5.y"
                                                        { strcpy (temp, "(") ;
                                                    strcat (temp, "- ") ;
                                                    strcat (temp, (yyvsp[0].cadena)) ;
                                                    strcat (temp, ")") ;
                                                    (yyval.cadena) = genera_cadena (temp) ; }
#line 1950 "trad5.tab.c"
    break;

  case 58:
#line 327 "trad5.y"
                                                { sprintf (temp, "%s", (yyvsp[0].cadena)) ;
                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1957 "trad5.tab.c"
    break;

  case 59:
#line 329 "trad5.y"
                                                        { sprintf (temp, "%d", (yyvsp[0].valor)) ;
                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1964 "trad5.tab.c"
    break;

  case 60:
#line 331 "trad5.y"
                                                        { (yyval.cadena) = (yyvsp[-1].cadena); }
#line 1970 "trad5.tab.c"
    break;

  case 61:
#line 332 "trad5.y"
                                         { sprintf (temp, "(aref %s %s)", (yyvsp[-3].cadena),(yyvsp[-1].cadena)) ;
                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1977 "trad5.tab.c"
    break;

  case 62:
#line 334 "trad5.y"
                                                                   { sprintf (temp, "(%s %s)", (yyvsp[-3].cadena),(yyvsp[-1].cadena)) ;
                                            (yyval.cadena) = genera_cadena (temp) ; }
#line 1984 "trad5.tab.c"
    break;

  case 63:
#line 339 "trad5.y"
                                                                        { (yyval.cadena) = genera_cadena(""); }
#line 1990 "trad5.tab.c"
    break;

  case 64:
#line 340 "trad5.y"
                                                                    { sprintf (temp, "%s%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                                    (yyval.cadena) = genera_cadena (temp) ;}
#line 1997 "trad5.tab.c"
    break;

  case 65:
#line 344 "trad5.y"
                                                                              { sprintf (temp, " %s%s",(yyvsp[-1].cadena),(yyvsp[0].cadena)) ;
                                                                    (yyval.cadena) = genera_cadena (temp) ;}
#line 2004 "trad5.tab.c"
    break;

  case 66:
#line 346 "trad5.y"
                                                                { (yyval.cadena) = genera_cadena(""); }
#line 2010 "trad5.tab.c"
    break;


#line 2014 "trad5.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 351 "trad5.y"

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

