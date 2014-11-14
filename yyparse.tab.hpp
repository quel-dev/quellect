/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_YYPARSE_TAB_HPP_INCLUDED
# define YY_YY_YYPARSE_TAB_HPP_INCLUDED
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
    ASSIGN = 258,
    EQ = 259,
    LT = 260,
    GT = 261,
    LE = 262,
    GE = 263,
    LOGOR = 264,
    LOGAND = 265,
    PLUS = 266,
    MINUS = 267,
    MULT = 268,
    DIVIDE = 269,
    MOD = 270,
    LOGNOT = 271,
    ALIAS = 272,
    TYPE = 273,
    INT = 274,
    DOUBLE = 275,
    STRING = 276,
    NUL = 277,
    FUNC = 278,
    FUNC_BRAC = 279,
    COMMA = 280,
    SEMICOLON = 281,
    COLON = 282,
    IF = 283,
    ELSE = 284,
    SWITCH = 285,
    EVENT = 286,
    BEHAV = 287,
    RETURN = 288,
    BREAK = 289,
    CONTINUE = 290,
    IDEN = 291,
    INT_NUM = 292,
    DOUBLE_NUM = 293,
    CONST_STR = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 23 "yyparse.ypp" /* yacc.c:1909  */

  Node* node;
  IntToken* int_token;
  DoubleToken* double_token;
  StringToken* token;

#line 101 "yyparse.tab.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YYPARSE_TAB_HPP_INCLUDED  */
