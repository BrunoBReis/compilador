blah:
	bison -d -o parser.tab.c parser.y
	flex -o lex.yy.c lexico.l
	cat parser.tab.c lex.yy.c > parser_combined.c
	gcc -E parser_combined.c > moj.c
	gcc moj.c
run:
	./a.out arquivo.pas