g++ -g -c node.cpp
flex yylex.lpp
bison yyparse.ypp -d
g++ -g -c lex.yy.c
g++ -g -c yyparse.tab.cpp
g++ -g -o main *.o main.cpp
