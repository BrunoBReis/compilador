# Nome do executável
EXEC = meusintatico

# Arquivos fonte
BISON_SRC = parser.y
FLEX_SRC = parser.y
BISON_HEADER = parser.tab.h

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
FLEX_LIBS = -lfl

# Regras
all: $(EXEC)

$(EXEC): parser.tab.c lex.yy.c
	$(CC) $(CFLAGS) -o $(EXEC) parser.tab.c lex.yy.c $(FLEX_LIBS)

parser.tab.c: $(BISON_SRC)
	bison -d $(BISON_SRC)

lex.yy.c: $(FLEX_SRC)
	flex $(FLEX_SRC)

clean:
	rm -f $(EXEC) parser.tab.c parser.tab.h lex.yy.c

.PHONY: all clean
