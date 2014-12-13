BISON_MAC = /usr/local/Cellar/bison/3.0.2/bin/bison -d
BISON_LINUX = bison -d
LEX = lex
CC = g++

main: main.cpp type.o node.o util.o environment.o lex.yy.o yyparse.tab.o
	$(CC) -g -Wall -o $@ $^

node.o: node.cpp node.h environment.h type.h util.h
	$(CC) -g -c -Wall -o $@ $<

util.o: util.cpp util.h environment.h type.h
	$(CC) -g -c -Wall -o $@ $<

environment.o: environment.cpp environment.h type.h
	$(CC) -g -c -Wall -o $@ $<

type.o: type.cpp type.h environment.h
	$(CC) -g -c -Wall -o $@ $<

lex.yy.o: lex.yy.c node.h environment.h type.h yyparse.tab.hpp
	$(CC) -g -c $<

yyparse.tab.o: yyparse.tab.cpp node.h environment.h type.h yylex.hpp
	$(CC) -g -c $<

lex.yy.c: yylex.lpp
	$(LEX) $^

yylex.hpp: yylex.lpp
	$(LEX) $^

yyparse.tab.cpp: yyparse.ypp
	if [ `uname -s` == "Darwin" ]; \
	then\
		$(BISON_MAC) $^; \
	else echo "============"; \
		$(BISON_LINUX) $^; \
	fi

yyparse.tab.hpp: yyparse.ypp
	if [ `uname -s` == "Darwin" ];\
	then\
		$(BISON_MAC) $^; \
	else \
		$(BISON_LINUX) $^; \
	fi

.PHONY: clean
clean:
	git clean -X -df
