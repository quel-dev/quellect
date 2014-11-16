LEX = lex
YACC = bison -d
CC = g++

main: flex_yacc node.o lex.yy.o yyparse.tab.o main.cpp
	$(CC) -g -Wall -o $@ node.o lex.yy.o yyparse.tab.o main.cpp

flex_yacc: yylex.lpp yyparse.ypp
	$(LEX) yylex.lpp 
	$(YACC) yyparse.ypp 
	
node.o: node.cpp
	$(CC) -g -c -Wall -o $@ $^

lex.yy.o: lex.yy.c yylex.hpp
	$(CC) -g -c $<

yyparse.tab.o: yyparse.tab.cpp yyparse.tab.hpp
	$(CC) -g -c $<

.PHONY: clean
clean:
	-rm -rf *.o main main.dSYM
