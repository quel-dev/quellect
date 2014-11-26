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
    EQ = 258,
    LT = 259,
    GT = 260,
    LE = 261,
    GE = 262,
    LOGOR = 263,
    LOGAND = 264,
    LOGNOT = 265,
    ALIAS = 266,
    TYPE = 267,
    INT = 268,
    DOUBLE = 269,
    STRING = 270,
    NUL = 271,
    FUNC = 272,
    FUNC_BRAC = 273,
    IF = 274,
    ELSE = 275,
    SWITCH = 276,
    EVENT = 277,
    BEHAV = 278,
    RETURN = 279,
    BREAK = 280,
    CONTINUE = 281,
    IDEN = 282,
    INT_NUM = 283,
    DOUBLE_NUM = 284,
    CONST_STR = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "yyparse.ypp" /* yacc.c:1909  */

  Node* node;
  IntToken* int_token;
  DoubleToken* double_token;
  StringToken* token;

#line 92 "yyparse.tab.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YYPARSE_TAB_HPP_INCLUDED  */
