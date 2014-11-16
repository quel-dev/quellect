/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yyparse.ypp" /* yacc.c:339  */

#ifndef NODE_H_
#define NODE_H_
#include "node.h"
#endif

#ifndef YYLEX_HPP_
#define YYLEX_HPP_
#include "yylex.hpp"
#endif
 
#include <cstdio>

Node* root = NULL; 

void yyerror(const char* msg) {
  fprintf(stderr, "%s\n", msg);
}


#line 87 "yyparse.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.tab.hpp".  */
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
    IF = 280,
    ELSE = 281,
    SWITCH = 282,
    EVENT = 283,
    BEHAV = 284,
    RETURN = 285,
    BREAK = 286,
    CONTINUE = 287,
    IDEN = 288,
    INT_NUM = 289,
    DOUBLE_NUM = 290,
    CONST_STR = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "yyparse.ypp" /* yacc.c:355  */

  Node* node;
  IntToken* int_token;
  DoubleToken* double_token;
  StringToken* token;

#line 171 "yyparse.tab.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YYPARSE_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "yyparse.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    46,
      44,    37,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    42,    48,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   109,   110,   116,   122,   125,   132,   135,
     142,   145,   152,   155,   162,   163,   164,   165,   169,   172,
     176,   183,   186,   190,   194,   201,   204,   211,   214,   220,
     221,   222,   223,   224,   227,   231,   238,   239,   240,   241,
     242,   246,   251,   258,   267,   268,   272,   273,   280,   286,
     292,   295,   298,   301,   302,   309,   313,   321,   324,   331,
     332,   336,   337,   344,   345,   346,   347,   348,   352,   353,
     358,   365,   368,   371,   374,   380,   384,   390,   396,   397,
     404,   408,   412,   416,   423,   430,   434
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "EQ", "LT", "GT", "LE", "GE",
  "LOGOR", "LOGAND", "PLUS", "MINUS", "MULT", "DIVIDE", "MOD", "LOGNOT",
  "ALIAS", "TYPE", "INT", "DOUBLE", "STRING", "NUL", "FUNC", "FUNC_BRAC",
  "IF", "ELSE", "SWITCH", "EVENT", "BEHAV", "RETURN", "BREAK", "CONTINUE",
  "IDEN", "INT_NUM", "DOUBLE_NUM", "CONST_STR", "'='", "'['", "']'", "'('",
  "')'", "'|'", "','", "'<'", "'>'", "';'", "'{'", "'}'", "':'", "$accept",
  "start", "assignment-expression", "constant-expression",
  "logical-or-expression", "logical-and-expression", "equal-expression",
  "notequal-expression", "notequal-operator", "additive-expression",
  "multiplicative-expression", "unary-expression", "postfix-expression",
  "primary-expression", "primary-type", "newtype-definition", "type",
  "type-comma-list", "newtype-expression", "type-iden-pair", "declaration",
  "initializer", "function-literal", "parameter-pair-comma-list",
  "expression", "expression-comma-list", "statement", "compound-statement",
  "function-expression", "selection-statement", "switch-branch",
  "jump-statement", "behavior-statement", "event-statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    61,    91,    93,
      40,    41,   124,    44,    60,    62,    59,   123,   125,    58
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     124,   158,    -6,     0,  -129,  -129,  -129,  -129,  -129,    57,
      57,    57,  -129,  -129,    10,  -129,  -129,  -129,   137,    38,
      -5,    24,    49,    64,    51,  -129,    58,    95,  -129,    60,
    -129,  -129,    26,    50,  -129,     5,   124,   124,  -129,  -129,
      54,    55,    69,    75,    52,    60,   100,   122,    82,   101,
    -129,    97,     2,    57,    83,   150,  -129,    -4,   109,    71,
    -129,  -129,     9,    57,    57,    57,  -129,  -129,  -129,  -129,
      57,    57,    57,    57,    57,    57,    57,   119,  -129,  -129,
      83,  -129,  -129,  -129,  -129,  -129,  -129,  -129,     2,   129,
     124,  -129,    52,   117,  -129,  -129,    45,  -129,    16,  -129,
    -129,  -129,  -129,   125,   120,  -129,   126,  -129,  -129,   128,
      -7,   124,  -129,    64,    51,  -129,    95,    95,     7,  -129,
    -129,  -129,   136,   152,  -129,   132,  -129,   155,   133,    46,
    -129,   135,     2,   150,  -129,  -129,  -129,    98,   139,  -129,
       2,  -129,     2,   154,  -129,   140,   124,  -129,  -129,  -129,
     145,   156,   157,   153,   159,   149,     2,  -129,  -129,   124,
     124,  -129,  -129,   151,   160,  -129,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      68,     0,     0,     0,    36,    37,    38,    39,    40,     0,
       0,    83,    81,    80,    29,    30,    31,    32,     0,     0,
       0,     3,     5,     6,     8,    10,    12,    18,    21,    25,
      27,    44,     0,     0,    33,     0,    68,    68,     2,    35,
       0,     0,     0,     0,    29,    26,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,    51,    29,     0,     0,
       1,    63,     0,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    49,
       0,    53,    70,    69,    64,    67,    65,    66,     0,     0,
      68,    78,     0,     0,    45,    57,     0,    84,    29,     4,
       3,    59,    60,    61,     0,    72,     0,    34,    74,     0,
       0,    68,    85,     7,     9,    11,    19,    20,    13,    22,
      23,    24,     0,     0,    55,     0,    41,     0,     0,     0,
      52,     0,     0,     0,    48,    71,    73,     0,     0,    28,
       0,    54,     0,    75,    77,     0,    68,    58,    62,    86,
      46,     0,     0,     0,     0,     0,     0,    43,    42,    68,
      68,    56,    47,     0,     0,    76,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   -38,    -9,  -129,   138,   141,   142,  -129,   130,
       6,    62,   202,  -129,  -129,  -129,   -81,  -128,   161,   -47,
    -129,  -129,    -8,  -129,  -129,   -44,  -129,   -33,   147,  -129,
    -129,  -129,  -129,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    72,    26,
      27,    28,    29,    30,    31,    32,    33,   151,    34,    35,
      36,   125,   102,    96,   103,   106,    37,    38,    39,    40,
     129,    41,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    49,    50,    82,    83,    95,    56,   126,    80,    58,
      59,   104,     1,    51,   152,   109,    99,    52,    70,    71,
      52,     4,     5,     6,     7,     8,   137,    46,   162,    44,
      15,    16,    17,    47,    52,    94,    18,   105,    60,    53,
      55,    61,   124,   -45,    97,   100,   101,    54,   101,   110,
     101,    81,    62,    54,    55,    65,   111,   128,    63,   150,
      55,   150,     1,    66,    67,    68,    69,   122,    77,    70,
      71,   100,    78,     1,    64,   150,   116,   117,   138,    44,
      15,    16,    17,    79,   131,   147,    18,     1,   132,   148,
      44,    15,    16,    17,   144,    52,    55,    18,    76,     1,
      84,    85,    59,    88,    44,    15,    16,    17,    73,    74,
      75,    18,   108,   155,     1,    86,    98,    15,    16,    17,
     145,    87,    52,    18,   101,    89,   163,   164,   101,    90,
      92,    44,    15,    16,    17,   119,   120,   121,    18,   105,
       1,     2,     3,     4,     5,     6,     7,     8,    91,     9,
     107,    10,   123,     1,    11,    12,    13,    14,    15,    16,
      17,    52,   127,   130,    18,   134,     1,   135,   133,   136,
      57,    15,    16,    17,    52,   139,   140,    18,   141,   142,
     153,   143,   146,    44,    15,    16,    17,   149,   156,   154,
      18,    44,    15,    16,    17,   157,   158,   161,    18,   165,
     159,   113,   118,    45,     0,   114,   160,   115,   166,   112,
       0,     0,    93
};

static const yytype_int16 yycheck[] =
{
       9,    10,    11,    36,    37,    52,    14,    88,     3,    18,
      18,    55,    16,     3,   142,    59,    54,    24,    11,    12,
      24,    19,    20,    21,    22,    23,    33,    33,   156,    33,
      34,    35,    36,    33,    24,    33,    40,    41,     0,    29,
      44,    46,    80,    33,    53,    54,    55,    37,    57,    40,
      59,    46,    28,    37,    44,     4,    47,    90,     9,   140,
      44,   142,    16,     5,     6,     7,     8,    76,    42,    11,
      12,    80,    46,    16,    10,   156,    70,    71,   111,    33,
      34,    35,    36,    33,    39,   132,    40,    16,    43,   133,
      33,    34,    35,    36,    48,    24,    44,    40,    38,    16,
      46,    46,   110,     3,    33,    34,    35,    36,    13,    14,
      15,    40,    41,   146,    16,    46,    33,    34,    35,    36,
     129,    46,    24,    40,   133,     3,   159,   160,   137,    47,
      33,    33,    34,    35,    36,    73,    74,    75,    40,    41,
      16,    17,    18,    19,    20,    21,    22,    23,    47,    25,
      41,    27,    33,    16,    30,    31,    32,    33,    34,    35,
      36,    24,    33,    46,    40,    45,    16,    41,    43,    41,
      33,    34,    35,    36,    24,    39,    24,    40,    46,    24,
      26,    48,    47,    33,    34,    35,    36,    48,    43,    49,
      40,    33,    34,    35,    36,    39,    39,    48,    40,    48,
      47,    63,    72,     1,    -1,    64,    47,    65,    48,    62,
      -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      27,    30,    31,    32,    33,    34,    35,    36,    40,    51,
      52,    53,    54,    55,    56,    57,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    70,    76,    77,    78,
      79,    81,    82,    83,    33,    62,    33,    33,    53,    53,
      53,     3,    24,    29,    37,    44,    72,    33,    53,    72,
       0,    46,    28,     9,    10,     4,     5,     6,     7,     8,
      11,    12,    58,    13,    14,    15,    38,    42,    46,    33,
       3,    46,    77,    77,    46,    46,    46,    46,     3,     3,
      47,    47,    33,    68,    33,    69,    73,    53,    33,    52,
      53,    53,    72,    74,    75,    41,    75,    41,    41,    75,
      40,    47,    78,    55,    56,    57,    60,    60,    59,    61,
      61,    61,    53,    33,    52,    71,    66,    33,    77,    80,
      46,    39,    43,    43,    45,    41,    41,    33,    77,    39,
      24,    46,    24,    48,    48,    53,    47,    69,    75,    48,
      66,    67,    67,    26,    49,    77,    43,    39,    39,    47,
      47,    48,    67,    77,    77,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    67,    67,    68,    69,
      70,    70,    70,    70,    70,    71,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    77,    77,
      77,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      81,    81,    81,    81,    82,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     1,     4,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     7,     6,     1,     1,     1,     3,     4,     2,
       2,     2,     4,     2,     4,     1,     6,     1,     3,     1,
       1,     1,     3,     2,     2,     2,     2,     2,     0,     2,
       2,     4,     3,     4,     3,     5,     9,     5,     0,     6,
       1,     1,     2,     1,     3,     3,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 105 "yyparse.ypp" /* yacc.c:1646  */
    { root = (yyvsp[0].node);}
#line 1393 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); puts("assignment-expression");}
#line 1399 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "yyparse.ypp" /* yacc.c:1646  */
    { 
                                                          (yyval.node) = new AssignExpNode((yyvsp[-2].token), (yyvsp[0].node));
                                                        }
#line 1407 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = (yyvsp[0].node);
                                                        }
#line 1415 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 122 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = (yyvsp[0].node);
                                                        }
#line 1423 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "||");
                                                          delete((yyvsp[-1].token));
                                                        }
#line 1432 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 132 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = (yyvsp[0].node);
                                                        }
#line 1440 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "&&");
                                                          delete((yyvsp[-1].token));
                                                        }
#line 1449 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 142 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = (yyvsp[0].node);
                                                        }
#line 1457 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "==");
                                                          delete((yyvsp[-1].token));
                                                        }
#line 1466 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                          (yyval.node) = (yyvsp[0].node);
                                                        }
#line 1474 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 155 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                 (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "!=");
                                                                 delete((yyvsp[-1].node));
                                                               }
#line 1483 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token);}
#line 1489 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 163 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token);}
#line 1495 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 164 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token);}
#line 1501 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 165 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token);}
#line 1507 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[0].node);
                                                              }
#line 1515 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "+");
                                                                delete((yyvsp[-1].token));
                                                              }
#line 1524 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "-");
                                                                delete((yyvsp[-1].token));
                                                              }
#line 1533 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 183 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[0].node);
                                                              }
#line 1541 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "*");
                                                                delete((yyvsp[-1].token));
                                                              }
#line 1550 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 190 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "/");
                                                                delete((yyvsp[-1].token));
                                                              }
#line 1559 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new BinaryOpExpNode((yyvsp[-2].node), (yyvsp[0].node), "%");
                                                                delete((yyvsp[-1].token));
                                                              }
#line 1568 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 201 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[0].node);
                                                              }
#line 1576 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 204 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new UnaryOpExpNode((yyvsp[0].node), "!");
                                                                delete((yyvsp[-1].token));
                                                              }
#line 1585 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 211 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[0].node);
                                                              }
#line 1593 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 214 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new PropertyIndexNode((yyvsp[-3].node), (yyvsp[-1].node));
                                                              }
#line 1601 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 220 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token); puts("primary-expression");}
#line 1607 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 221 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].int_token);}
#line 1613 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].double_token);}
#line 1619 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token);}
#line 1625 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[0].node);
                                                              }
#line 1633 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[-1].node);
                                                                puts("constant-expression");
                                                              }
#line 1642 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[0].node);
                                                                puts("function-expression");
                                                              }
#line 1651 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 238 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token); }
#line 1657 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 239 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token); }
#line 1663 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token); }
#line 1669 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 241 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token); }
#line 1675 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 242 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token); }
#line 1681 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 246 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new TypeDefNode(((yyvsp[-2].token))->GetStrTok(), (yyvsp[0].node));
                                                                delete((yyvsp[-3].token));
                                                                delete((yyvsp[-1].token));
                                                              }
#line 1691 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 251 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                Node* cons = new ConsDefNode(((yyvsp[-3].token))->GetStrTok(), (yyvsp[-1].node));
                                                                (yyval.node) = new TypeDefNode(((yyvsp[-5].token))->GetStrTok(), cons);
                                                                delete((yyvsp[-6].token));  // token 'type'
                                                                delete((yyvsp[-4].token));  // token '='
                                                                delete((yyvsp[-2].token));  // token FUNC_BRAC
                                                              }
#line 1703 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 258 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[-5].node);
                                                                Node* cons = new ConsDefNode(((yyvsp[-3].token))->GetStrTok(), (yyvsp[-1].node));
                                                                ((yyval.node))->Add(cons);
                                                                delete((yyvsp[-2].token));  // token FUNC_BRAC
                                                              }
#line 1714 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1720 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].token);}
#line 1726 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 272 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = new ListNode("type_list", (yyvsp[0].node)); }
#line 1732 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 273 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[0].node);
                                                                ((yyval.node))->Add((yyvsp[-2].node));
                                                              }
#line 1741 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 280 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new NewTypeExpNode(((yyvsp[-3].token))->GetStrTok(), (yyvsp[-1].node));
                                                              }
#line 1749 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 286 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new TypeIdenPair((yyvsp[-1].node), ((yyvsp[0].token))->GetStrTok());
                                                              }
#line 1757 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 292 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = (yyvsp[-1].node);
                                                              }
#line 1765 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 295 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new FuncDef(((yyvsp[-1].token))->GetStrTok(), (yyvsp[0].node));
                                                              }
#line 1773 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 298 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new VarDef(((yyvsp[-3].token))->GetStrTok(), (yyvsp[-1].node));
                                                              }
#line 1781 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 301 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = new VarDef((yyvsp[-1].node), NULL);}
#line 1787 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 302 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.node) = new VarDef((yyvsp[-3].node), (yyvsp[-1].node));
                                                                puts("declaration");
                                                              }
#line 1796 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 309 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1802 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 313 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new FuncLiteral((yyvsp[-4].node), (yyvsp[-1].node));
                                                                          delete((yyvsp[-5].token));
                                                                        }
#line 1811 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 321 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new ListNode("para_list", (yyvsp[0].node));
                                                                        }
#line 1819 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 324 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = (yyvsp[-2].node);
                                                                          ((yyval.node))->Add((yyvsp[0].node));
                                                                        }
#line 1828 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 331 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1834 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 332 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1840 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 336 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = new ListNode("exp_list", (yyvsp[0].node));}
#line 1846 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 337 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = (yyvsp[0].node);
                                                                          ((yyval.node))->Add((yyvsp[-2].node));
                                                                        }
#line 1855 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 344 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); puts("assignment");}
#line 1861 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 345 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);}
#line 1867 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 346 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);}
#line 1873 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 347 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);}
#line 1879 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 348 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);}
#line 1885 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 352 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = new ListNode("statement_list");}
#line 1891 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 353 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = (yyvsp[0].node);
                                                                          ((yyval.node))->Add((yyvsp[-1].node)); 
                                                                          puts("compound-statement");
                                                                        }
#line 1901 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 358 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = (yyvsp[0].node);
                                                                          ((yyval.node))->Add((yyvsp[-1].node));
                                                                        }
#line 1910 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 365 "yyparse.ypp" /* yacc.c:1646  */
    { 
                                                                          (yyval.node) = new FuncExp(((yyvsp[-2].token))->GetStrTok(), (yyvsp[-1].node));
                                                                        }
#line 1918 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 368 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new FuncExp(((yyvsp[-1].token))->GetStrTok(), NULL);
                                                                        }
#line 1926 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 371 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new FuncExp((yyvsp[-2].node), (yyvsp[-1].node));
                                                                        }
#line 1934 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 374 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new FuncExp(((yyvsp[-1].node))->GetStrTok(), NULL);
                                                                        }
#line 1942 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 380 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new IfNode((yyvsp[-3].node), (yyvsp[-1].node), NULL);
                                                                          delete((yyvsp[-4].token));
                                                                        }
#line 1951 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 385 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new IfNode((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-1].node));
                                                                          delete((yyvsp[-8].token));
                                                                          delete((yyvsp[-3].token));
                                                                        }
#line 1961 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 390 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new SwitchNode((yyvsp[-3].node), (yyvsp[-1].node));
                                                                        }
#line 1969 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 396 "yyparse.ypp" /* yacc.c:1646  */
    { (yyval.node) = new SwitchBranch();}
#line 1975 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 397 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = (yyvsp[-5].node);
                                                                          ((yyval.node))->AddBranch((yyvsp[-4].node), (yyvsp[-1].node));
                                                                        }
#line 1984 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 404 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new JumpNode("continue", NULL);
                                                                          delete((yyvsp[0].token));
                                                                        }
#line 1993 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 408 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new JumpNode("break", NULL);
                                                                          delete((yyvsp[0].token));
                                                                        }
#line 2002 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 412 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new JumpNode("return", (yyvsp[0].node));
                                                                          delete((yyvsp[-1].token));
                                                                        }
#line 2011 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 416 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new JumpNode("return", NULL);
                                                                          delete((yyvsp[0].token));
                                                                        }
#line 2020 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 423 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new BehaviorNode(((yyvsp[-2].token))->GetStrTok(), (yyvsp[0].node));
                                                                          delete((yyvsp[-1].token));
                                                                        }
#line 2029 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 430 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new EventNode((yyvsp[-2].node), (yyvsp[0].node)); 
                                                                          delete((yyvsp[-1].token));
                                                                        }
#line 2038 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 434 "yyparse.ypp" /* yacc.c:1646  */
    {
                                                                          (yyval.node) = new EventNode((yyvsp[-4].node), (yyvsp[-1].node));
                                                                          delete((yyvsp[-3].token));
                                                                        }
#line 2047 "yyparse.tab.cpp" /* yacc.c:1646  */
    break;


#line 2051 "yyparse.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
