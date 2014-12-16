#ifndef NODE_H_
#define NODE_H_
#include "node.h"
#endif

#ifndef YYLEX_HPP_
#define YYLEX_HPP_
#include "yylex.hpp"
#endif

#ifndef YYPARSE_TAB_HPP_
#define YYPARSE_TAB_HPP_
#include "yyparse.tab.hpp"
#endif

#include <cstdio>

#include <memory>
#include <vector>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    puts("filename missing.");
    return 1;
  }
  FILE* file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "couldn't open: %s\n", argv[1]);
    return 1;
  }
  yyin = file;
  Node* root = NULL;
  yyparse(root);
  // after calling yyparse, the program has been successfully
  // parsed and the root of AST is stored in Node* root.
  Environment global;
  (root->Eval(&global));
  fclose(file);
  return 0;
}
