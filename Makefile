default:
	bison trad5.y
	gcc trad5.tab.c -o trad5
	@echo -----------------------------------
	# @./trad5

cat:
	bison trad5.y
	gcc trad5.tab.c -o trad5
	@echo -----------------------------------
	@cat input.c | ./trad5
