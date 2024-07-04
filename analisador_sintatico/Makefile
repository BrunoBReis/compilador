blah:
	flex lexico.l
	bison -d parser.y
	gcc parser.tab.c lex.yy.c -o meusintatico
run:
	./meusintatico arquivo.pas