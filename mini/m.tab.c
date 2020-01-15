
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "m.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"
#include "TSS.h"
#include "pgm.h"
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineo;
extern int Col;
values val;
int tabPile[1000];
int indexPile=-1;
int qc=0,typeExp;
int tmpQc = 1;
int Fin_if=0;
char tmp [20];
char idf [20];
int type,myIndex,mode;
int TabOrIdf = 0;
void yyerror(const char* s);
void mise_ajour(char type[], char typeSynt[],int mode ,values val,char IDF[]);
int verifierDeclarationIDF(char IDF[]);
int verifierConst(char IDF[]);
int verifierIndex(char IDF[],int myIndex);
int getVal(char IDF[]);
int getTypeSynt(char IDF[]);
values getVal2(char IDF[]);
void get(char IDF[],int type);
void miseAjourIDF(char IDF1[],char IDF2[],values value,int type,int mode);
int divPar0(char IDF[]);
int depilerCh();
void empilerCh(int x);


/* Line 189 of yacc.c  */
#line 111 "m.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_POINT = 258,
     T_LET = 259,
     T_FINIST = 260,
     T_END = 261,
     T_PROGRAM = 262,
     T_BEGIN = 263,
     T_OU = 264,
     T_AFFECTATION = 265,
     T_DOLLAR = 266,
     T_AROBASE = 267,
     T_DIAZ = 268,
     T_POURCENT = 269,
     T_ETCOM = 270,
     T_RETURN = 271,
     T_GET = 272,
     T_SHOW = 273,
     T_ENDFOR = 274,
     T_CROCHET_OUV = 275,
     T_CROCHET_FER = 276,
     T_PARENTHESE_OUV = 277,
     T_PARENTHESE_FER = 278,
     T_ACCOLADE_OUV = 279,
     T_ACCOLADE_FER = 280,
     T_OPERATEUR_ARITHMETIQUE = 281,
     T_IF = 282,
     T_ENDIF = 283,
     T_ELSE = 284,
     T_FOR = 285,
     T_IDF = 286,
     T_INTEGER = 287,
     T_FLOAT = 288,
     T_CHAR = 289,
     T_STRING = 290,
     T_VAR = 291,
     V_FLOAT = 292,
     V_INTEGER = 293,
     V_CHAR = 294,
     V_STRING = 295,
     T_DIFF = 296,
     T_EGAL = 297,
     T_INFEGAL = 298,
     T_SUPEGAL = 299,
     T_INFSTRICT = 300,
     T_SUPSTRICT = 301,
     T_SUB = 302,
     T_ADD = 303,
     T_MUL = 304,
     T_DIV = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 37 "m.y"

int ival;
float fval;
char cval;
char* sval;



/* Line 214 of yacc.c  */
#line 206 "m.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 218 "m.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    12,    18,    24,    25,    33,    44,
      45,    58,    65,    66,    75,    81,    88,    92,    94,    96,
      98,   100,   102,   104,   106,   108,   110,   112,   114,   115,
     118,   121,   124,   127,   130,   132,   134,   136,   138,   140,
     142,   146,   150,   154,   158,   162,   165,   167,   169,   172,
     174,   176,   178,   180,   184,   185,   186,   193,   195,   197,
     199,   201,   203,   205,   215,   221,   230,   239,   242,   249,
     254,   261,   267,   271
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,     7,    31,    53,    54,     8,    62,
       6,    -1,     7,    31,     8,    62,     6,    -1,    36,    58,
       3,    59,     5,    -1,    -1,    36,    58,     3,    59,     5,
      55,    54,    -1,    36,    31,    20,    38,    21,     3,    20,
      59,    21,     5,    -1,    -1,    36,    31,    20,    38,    21,
       3,    20,    59,    21,     5,    56,    54,    -1,     4,    31,
      59,    10,    60,     5,    -1,    -1,     4,    31,    59,    10,
      60,     5,    57,    54,    -1,     4,    31,    10,    60,     5,
      -1,     4,    31,    10,    60,     5,    54,    -1,    31,     9,
      58,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    38,    -1,    37,    -1,    39,    -1,    40,    -1,
      39,    -1,    40,    -1,    -1,    68,    62,    -1,    72,    62,
      -1,    73,    62,    -1,    74,    62,    -1,    79,    62,    -1,
      46,    -1,    45,    -1,    44,    -1,    43,    -1,    42,    -1,
      41,    -1,    64,    48,    64,    -1,    64,    47,    64,    -1,
      64,    50,    64,    -1,    64,    49,    64,    -1,    22,    64,
      23,    -1,    31,    67,    -1,    38,    -1,    37,    -1,    31,
      67,    -1,    38,    -1,    37,    -1,    61,    -1,    64,    -1,
      20,    70,    21,    -1,    -1,    -1,    31,    67,    10,    69,
      66,     5,    -1,    31,    -1,    38,    -1,    11,    -1,    14,
      -1,    13,    -1,    15,    -1,    17,    22,    71,     3,    12,
      31,    67,    23,     5,    -1,    18,    22,    40,    23,     5,
      -1,    18,    22,    40,     3,    31,    67,    23,     5,    -1,
      75,    29,     3,    24,    62,    77,    25,    28,    -1,    75,
      28,    -1,    76,     3,    24,    62,    77,    25,    -1,    27,
      22,    78,    23,    -1,    16,    22,    31,    67,    23,     5,
      -1,    16,    22,    60,    23,     5,    -1,    65,    63,    65,
      -1,    30,    22,    31,     3,    38,     3,    78,    23,    62,
      19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    64,    65,    67,    68,    68,    69,    70,
      70,    71,    72,    72,    73,    74,    76,    77,    79,    80,
      81,    82,    84,    85,    86,    87,    89,    90,    92,    93,
      94,    95,    96,    97,    99,   100,   101,   102,   103,   104,
     106,   107,   108,   109,   110,   111,   122,   123,   125,   126,
     127,   129,   130,   132,   133,   135,   135,   189,   190,   192,
     193,   194,   195,   197,   199,   200,   202,   206,   211,   220,
     226,   227,   229,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_POINT", "T_LET", "T_FINIST", "T_END",
  "T_PROGRAM", "T_BEGIN", "T_OU", "T_AFFECTATION", "T_DOLLAR", "T_AROBASE",
  "T_DIAZ", "T_POURCENT", "T_ETCOM", "T_RETURN", "T_GET", "T_SHOW",
  "T_ENDFOR", "T_CROCHET_OUV", "T_CROCHET_FER", "T_PARENTHESE_OUV",
  "T_PARENTHESE_FER", "T_ACCOLADE_OUV", "T_ACCOLADE_FER",
  "T_OPERATEUR_ARITHMETIQUE", "T_IF", "T_ENDIF", "T_ELSE", "T_FOR",
  "T_IDF", "T_INTEGER", "T_FLOAT", "T_CHAR", "T_STRING", "T_VAR",
  "V_FLOAT", "V_INTEGER", "V_CHAR", "V_STRING", "T_DIFF", "T_EGAL",
  "T_INFEGAL", "T_SUPEGAL", "T_INFSTRICT", "T_SUPSTRICT", "T_SUB", "T_ADD",
  "T_MUL", "T_DIV", "$accept", "MINI", "$@1", "DECLARATION", "$@2", "$@3",
  "$@4", "LIST_IDF", "LIST_TYPE", "LIST_VAL", "LIST_VAL2", "BLOCK",
  "OPERATEUR_LOGIQUE", "OPERATION_ARITHMETIQUE", "OPERAND", "EXPRESSION",
  "VAR", "AFFECTATION", "$@5", "INDEX", "LISTES", "ENTREE", "SORTIE",
  "CONDITIONIF", "BLOCKIF", "CONDITIONI", "N_RETURN", "CONDITION",
  "BOUCLE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    52,    54,    55,    54,    54,    56,
      54,    54,    57,    54,    54,    54,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    67,    67,    69,    68,    70,    70,    71,
      71,    71,    71,    72,    73,    73,    74,    74,    75,    76,
      77,    77,    78,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     5,     5,     0,     7,    10,     0,
      12,     6,     0,     8,     5,     6,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     2,     1,     1,     2,     1,
       1,     1,     1,     3,     0,     0,     6,     1,     1,     1,
       1,     1,     1,     9,     5,     8,     8,     2,     6,     4,
       6,     5,     3,    10
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,    28,     0,     0,     0,     0,
       0,    54,     0,    28,    28,    28,    28,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
      29,    30,    31,    32,    67,     0,     0,    33,     0,    17,
       0,    28,    59,    61,    60,    62,     0,     0,    54,    50,
      49,     0,     0,     0,    57,    58,     0,    55,     0,    28,
       0,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    39,    38,    37,    36,    35,    34,
       0,    69,     0,    53,     0,    28,     0,    23,    22,    24,
      25,     0,     0,    17,    16,     0,     0,     3,     0,    54,
      64,    72,     0,     0,    54,    47,    46,    26,    27,    51,
      52,     0,     0,     0,     0,    14,     0,     0,     6,    54,
       0,     0,     0,    45,     0,     0,     0,     0,    56,     0,
       0,    68,    15,    12,     0,     0,     0,     0,     0,    44,
      41,    40,    43,    42,     0,    54,     0,     0,     0,     7,
       0,    65,    28,    66,     0,     0,    13,     0,    63,     0,
       0,    71,     0,    73,    70,     9,     0,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    22,   135,   166,   147,    40,    65,    91,
     109,    12,    80,   110,    51,   111,    28,    13,    84,    56,
      46,    14,    15,    16,    17,    18,   114,    52,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -109
static const yytype_int16 yypact[] =
{
       5,   -15,    24,    48,  -109,    50,     4,    37,    39,    40,
      47,    53,    64,    50,    50,    50,    50,   -11,    68,    50,
      43,    45,    70,    83,    44,    55,    52,   -18,    69,  -109,
    -109,  -109,  -109,  -109,  -109,    84,    71,  -109,     9,     6,
      96,    50,  -109,  -109,  -109,  -109,    97,    22,    53,  -109,
    -109,     8,    91,   112,  -109,  -109,    95,  -109,    93,    50,
      65,  -109,  -109,  -109,  -109,   108,    88,    82,    74,   115,
     110,    92,   119,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
      55,  -109,    87,  -109,    26,    50,   111,  -109,  -109,  -109,
    -109,   121,    65,   120,  -109,   107,   125,  -109,   100,    53,
    -109,  -109,   129,    -8,    53,  -109,  -109,  -109,  -109,  -109,
      63,   128,   111,   113,   109,     4,   131,   134,   130,    53,
     117,    55,   -12,  -109,    -8,    -8,    -8,    -8,  -109,   116,
      51,  -109,  -109,   135,   122,     4,   123,   139,   124,  -109,
     -28,   -28,  -109,  -109,   126,    53,   127,     4,    74,  -109,
     140,  -109,    50,  -109,   132,   143,  -109,   136,  -109,   133,
     144,  -109,   146,  -109,  -109,   145,     4,  -109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -108,  -109,  -109,  -109,    90,   -63,   -83,
    -109,   -13,  -109,   -93,    78,  -109,   -44,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,    49,    38,  -109
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -12
static const yytype_int16 yytable[] =
{
      30,    31,    32,    33,    73,    96,    37,   132,    20,   116,
     122,   139,     1,    54,   103,    66,     3,    34,    35,    60,
      55,   126,   127,   104,     4,    71,    67,   149,    69,   105,
     106,   140,   141,   142,   143,   124,   125,   126,   127,   156,
      21,    61,    62,    63,    64,    72,    86,   146,   103,    74,
      75,    76,    77,    78,    79,   120,     5,   104,   167,    23,
     123,    24,    25,   105,   106,   107,   108,     7,     8,    26,
      29,    36,   112,    27,    38,   136,    39,     9,    41,    57,
      10,    11,   145,    53,    47,   157,    48,    58,    87,    88,
      89,    90,    49,    50,    42,    59,    43,    44,    45,    68,
      70,   154,    87,    88,    89,    90,    61,    62,    63,    64,
     124,   125,   126,   127,    81,    82,    83,    85,    92,    93,
      95,    97,    98,    99,   100,   102,   115,   113,   117,    66,
     118,   119,   121,   128,   131,   130,   133,   134,    -5,   159,
     137,   144,   148,   -11,   151,   158,   150,   152,   161,   164,
     155,   165,   163,    -8,   153,   160,    94,   162,   101,   138,
       0,   129
};

static const yytype_int16 yycheck[] =
{
      13,    14,    15,    16,    48,    68,    19,   115,     4,    92,
     103,    23,     7,    31,    22,     9,    31,    28,    29,    10,
      38,    49,    50,    31,     0,     3,    20,   135,    41,    37,
      38,   124,   125,   126,   127,    47,    48,    49,    50,   147,
      36,    32,    33,    34,    35,    23,    59,   130,    22,    41,
      42,    43,    44,    45,    46,    99,     8,    31,   166,    22,
     104,    22,    22,    37,    38,    39,    40,    17,    18,    22,
       6,     3,    85,    20,    31,   119,    31,    27,     8,    10,
      30,    31,    31,    31,    40,   148,    31,     3,    37,    38,
      39,    40,    37,    38,    11,    24,    13,    14,    15,     3,
       3,   145,    37,    38,    39,    40,    32,    33,    34,    35,
      47,    48,    49,    50,    23,     3,    21,    24,    10,    31,
      38,     6,    12,    31,     5,    38,     5,    16,    21,     9,
       5,    31,     3,     5,    25,    22,     5,     3,     8,   152,
      23,    25,    20,     8,     5,     5,    23,    23,     5,     5,
      23,     5,    19,     8,    28,    23,    66,    21,    80,   121,
      -1,   112
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    52,    31,     0,     8,    53,    17,    18,    27,
      30,    31,    62,    68,    72,    73,    74,    75,    76,    79,
       4,    36,    54,    22,    22,    22,    22,    20,    67,     6,
      62,    62,    62,    62,    28,    29,     3,    62,    31,    31,
      58,     8,    11,    13,    14,    15,    71,    40,    31,    37,
      38,    65,    78,    31,    31,    38,    70,    10,     3,    24,
      10,    32,    33,    34,    35,    59,     9,    20,     3,    62,
       3,     3,    23,    67,    41,    42,    43,    44,    45,    46,
      63,    23,     3,    21,    69,    24,    62,    37,    38,    39,
      40,    60,    10,    31,    58,    38,    59,     6,    12,    31,
       5,    65,    38,    22,    31,    37,    38,    39,    40,    61,
      64,    66,    62,    16,    77,     5,    60,    21,     5,    31,
      67,     3,    64,    67,    47,    48,    49,    50,     5,    77,
      22,    25,    54,     5,     3,    55,    67,    23,    78,    23,
      64,    64,    64,    64,    25,    31,    60,    57,    20,    54,
      23,     5,    23,    28,    67,    23,    54,    59,     5,    62,
      23,     5,    21,    19,     5,     5,    56,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 64 "m.y"
    {initialisationIDF();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 64 "m.y"
    {printf("execute avec succes\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 67 "m.y"
    {mise_ajour((yyvsp[(1) - (5)].sval),(yyvsp[(4) - (5)].sval),0,val,"");initialisationIDF();;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 68 "m.y"
    {mise_ajour((yyvsp[(1) - (5)].sval),(yyvsp[(4) - (5)].sval),0,val,"");initialisationIDF();;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 69 "m.y"
    {val.ival=(yyvsp[(4) - (10)].ival); mise_ajour("VAR-TAB",(yyvsp[(8) - (10)].sval),1,val,(yyvsp[(2) - (10)].sval));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 70 "m.y"
    {val.ival=(yyvsp[(4) - (10)].ival); mise_ajour("VAR-TAB",(yyvsp[(8) - (10)].sval),1,val,(yyvsp[(2) - (10)].sval));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 71 "m.y"
    {mise_ajour("CONST",(yyvsp[(3) - (6)].sval),2,val,(yyvsp[(2) - (6)].sval));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 72 "m.y"
    {mise_ajour("CONST",(yyvsp[(3) - (6)].sval),2,val,(yyvsp[(2) - (6)].sval));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 76 "m.y"
    {insererIDF((yyvsp[(1) - (3)].sval));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 77 "m.y"
    {insererIDF((yyvsp[(1) - (1)].sval));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 84 "m.y"
    {val.ival = (yyvsp[(1) - (1)].ival);type = 0;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 85 "m.y"
    {val.fval = (yyvsp[(1) - (1)].fval);type = 1;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 86 "m.y"
    {val.cval = (yyvsp[(1) - (1)].cval);type = 2;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 87 "m.y"
    {val.sval = strdup((yyvsp[(1) - (1)].sval));type = 3;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 89 "m.y"
    {val.cval = (yyvsp[(1) - (1)].cval);type = 2;sprintf(tmp,"'%c'",(yyvsp[(1) - (1)].cval)); ajoutType(3);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 90 "m.y"
    {val.sval = strdup((yyvsp[(1) - (1)].sval));type = 3;sprintf(tmp,"\"%s\"",(yyvsp[(1) - (1)].sval));ajoutType(4);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 99 "m.y"
    {(yyval.sval) = strdup("BP");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 100 "m.y"
    {(yyval.sval) = strdup("BM");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 101 "m.y"
    {(yyval.sval) = strdup("BPZ");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 102 "m.y"
    {(yyval.sval) = strdup("BMZ");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 103 "m.y"
    {(yyval.sval) = strdup("BZ");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 104 "m.y"
    {(yyval.sval) = strdup("BNZ");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 106 "m.y"
    {sprintf(tmp,"t%d",tmpQc++); quadr("+",(yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].sval),tmp);qc++;(yyval.sval)=strdup(tmp);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 107 "m.y"
    {sprintf(tmp,"t%d",tmpQc++);quadr("-",(yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].sval),tmp);qc++;(yyval.sval)=strdup(tmp);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 108 "m.y"
    {if(divPar0((yyvsp[(3) - (3)].sval))) yyerror("Division par 0");sprintf(tmp,"t%d",tmpQc++);quadr("/",(yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].sval),tmp);qc++;(yyval.sval)=strdup(tmp);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 109 "m.y"
    {sprintf(tmp,"t%d",tmpQc++);quadr("*",(yyvsp[(1) - (3)].sval),(yyvsp[(3) - (3)].sval),tmp);qc++;(yyval.sval)=strdup(tmp);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 110 "m.y"
    {(yyval.sval)= strdup((yyvsp[(2) - (3)].sval));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 111 "m.y"
    {
                                        verifierDeclarationIDF((yyvsp[(1) - (2)].sval));
                                        if (TabOrIdf)
                                        {
                                            verifierIndex((yyvsp[(1) - (2)].sval),myIndex);
                                        }
                                        sprintf(idf,"%s",(yyvsp[(1) - (2)].sval));
                                        val = getVal2((yyvsp[(1) - (2)].sval));
                                        ajoutType(getTypeSynt((yyvsp[(1) - (2)].sval)));
                                        strcpy(tmp,(yyvsp[(1) - (2)].sval));
                                      ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 122 "m.y"
    {val.ival=(yyvsp[(1) - (1)].ival);type=0;sprintf(tmp,"%d",(yyvsp[(1) - (1)].ival));(yyval.sval)=strdup(tmp);ajoutType(1);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 123 "m.y"
    {val.fval=(yyvsp[(1) - (1)].fval);type=1;sprintf(tmp,"%f",(yyvsp[(1) - (1)].fval));(yyval.sval)=strdup(tmp);ajoutType(2);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 125 "m.y"
    {verifierDeclarationIDF((yyvsp[(1) - (2)].sval));if(TabOrIdf)verifierIndex((yyvsp[(1) - (2)].sval),myIndex);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 129 "m.y"
    {mode=0;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 130 "m.y"
    {mode=1;tmpQc=1;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 132 "m.y"
    {TabOrIdf=1;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 135 "m.y"
    {initTabType();;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 135 "m.y"
    {                                                                            
                                                                                                    verifierDeclarationIDF((yyvsp[(1) - (6)].sval));
                                                                                                    if(!TabOrIdf)
                                                                                                    {
                                                                                                        verifierConst((yyvsp[(1) - (6)].sval));
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        verifierIndex((yyvsp[(1) - (6)].sval),myIndex);
                                                                                                    }
                                                                                                    typeExp = getTypeExp();
                                                                                                        switch(typeExp)
                                                                                                        {
                                                                                                            case 1:
                                                                                                                if(getTypeSynt((yyvsp[(1) - (6)].sval))!=1)
                                                                                                                    yyerror("Incompatiblite de type!") ;
                                                                                                                break;
                                                                                                            case 2:
                                                                                                                if(getTypeSynt((yyvsp[(1) - (6)].sval))!=2)
                                                                                                                    yyerror("Incompatiblite de type!") ;
                                                                                                                break;
                                                                                                            case 3:
                                                                                                                if(getTypeSynt((yyvsp[(1) - (6)].sval))!=3)
                                                                                                                    yyerror("Incompatiblite de type!") ;
                                                                                                                break;
                                                                                                            case 4:
                                                                                                                if(getTypeSynt((yyvsp[(1) - (6)].sval))!=4)
                                                                                                                    yyerror("Incompatiblite de type!") ;
                                                                                                                break;
                                                                                                            case 0:
                                                                                                                yyerror("Incompatiblite de type!");
                                                                                                                break;
                                                                                                        }
                                                                                                    if (!mode)
                                                                                                    {
                                                                                                        miseAjourIDF((yyvsp[(1) - (6)].sval),"",val,type,1);
                                                                                                        if(type==2)
                                                                                                        {
                                                                                                            quadr("=",tmp,"",(yyvsp[(1) - (6)].sval));
                                                                                                            qc++;
                                                                                                        }
                                                                                                        else if(type==3)
                                                                                                        {
                                                                                                            quadr("=",tmp,"",(yyvsp[(1) - (6)].sval));
                                                                                                            qc++;
                                                                                                        }
                                                                                                    }
                                                                                                    if (mode)
                                                                                                    {
                                                                                                        quadr("=",tmp,"",(yyvsp[(1) - (6)].sval));
                                                                                                        qc++;
                                                                                                    }
                                                                                                ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 189 "m.y"
    {verifierDeclarationIDF((yyvsp[(1) - (1)].sval));if(getTypeSynt((yyvsp[(1) - (1)].sval))!=1) yyerror("l'index dois etre un entier");myIndex=getVal((yyvsp[(1) - (1)].sval));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 190 "m.y"
    {myIndex = (yyvsp[(1) - (1)].ival);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 192 "m.y"
    {type = 1;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 193 "m.y"
    {type = 2;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 194 "m.y"
    {type = 3;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 195 "m.y"
    {type = 4;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 197 "m.y"
    {verifierDeclarationIDF((yyvsp[(6) - (9)].sval));if(TabOrIdf)verifierIndex((yyvsp[(6) - (9)].sval),myIndex);get((yyvsp[(6) - (9)].sval),type);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 199 "m.y"
    {show1((yyvsp[(3) - (5)].sval),"");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 200 "m.y"
    {verifierDeclarationIDF((yyvsp[(5) - (8)].sval));if(TabOrIdf)verifierIndex((yyvsp[(5) - (8)].sval),myIndex);show1((yyvsp[(3) - (8)].sval),(yyvsp[(5) - (8)].sval));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 202 "m.y"
    {
                                                                                                            sprintf(tmp,"%d",qc);
                                                                                                            ajour_quad(Fin_if,1,tmp);
                                                                                                        ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 206 "m.y"
    {
                                                sprintf(tmp,"%d",qc);
                                                ajour_quad(Fin_if,1,tmp);
                                            ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 211 "m.y"
    {
                                                                                                quadr("BR", "", "vide", "vide");
                                                                                                Fin_if = qc;
                                                                                                qc++;
                                                                                                sprintf(tmp,"%d",qc);
                                                                                                if (indexPile>-1)
                                                                                                    ajour_quad(depilerCh(), 1, tmp);
                                                                                            ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 220 "m.y"
    {
                                                                                        quadr((yyvsp[(3) - (4)].sval), "","temp_cond", "vide");
                                                                                        empilerCh(qc);
                                                                                        qc++;
                                                                                    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 226 "m.y"
    {verifierDeclarationIDF((yyvsp[(3) - (6)].sval));if(TabOrIdf)verifierIndex((yyvsp[(3) - (6)].sval),myIndex);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 229 "m.y"
    {(yyval.sval) = strdup((yyvsp[(2) - (3)].sval));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 231 "m.y"
    {verifierDeclarationIDF((yyvsp[(3) - (10)].sval));;}
    break;



/* Line 1455 of yacc.c  */
#line 2001 "m.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 233 "m.y"

int main() {
    initialisation();
    yyin = fopen( "programme.txt", "r" );
    if (yyin==NULL) 
        printf("ERROR \n");
    else 
        yyparse();
    afficher();
    afficher_qdr();
    fclose(yyin);
    return 0;
}
void yyerror(const char* s) {
    FILE* prog =NULL;
    char ligneError[10000];
    prog = fopen( "programme.txt", "r" );
    for (int i = 0; i < yylineo; i++)
    {
        fgets(ligneError,10000,prog);
    }
    fprintf(stderr, "erreur a la ligne %d  collone %d : %s\n",yylineo,Col, s);
    int i =0;
    while (i < strlen(ligneError))
    {
        if ((ligneError[i]!='\t')&&(ligneError[i]!=' '))
            break;
        i++;
    }
    int j = i;
    while (i < strlen(ligneError))
    {
       fprintf(stderr, "%c",ligneError[i]);i++;
    }
    fclose(prog);
    exit(1);
}

void mise_ajour(char type[], char typeSynt[],int mode,values val,char IDF[])
{
    int i,j;
    switch (mode)
    {
    case 0:
        for (i = 0;((i<1000)&&(tabIDF[i].state==1)); i++)
        {
            for(j=0;((j<1000)&&(tab[j].state==1))&&(strcmp(tabIDF[i].IDF,tab[j].name)!=0);j++);
            if((j<1000)&&(strcmp(tabIDF[i].IDF,tab[j].name)==0))
            {
                if (!strcmp("",tab[j].typeSynt))
                {
                    strcpy (tab[j].typeSynt, typeSynt);
                    strcpy (tab[j].type, type);
                }
                else
                {
                    char erreur[50] ;
                    strcpy(erreur,"double declaration de l'idf ");
                    strcat(erreur,tab[j].name);
                    yyerror(erreur);
                }            
            }
        }
        break;
    case 1:
        if (val.ival>0)
        {
            for(j=0;((j<1000)&&(tab[j].state==1))&&(strcmp(IDF,tab[j].name)!=0);j++);
            if((j<1000)&&(strcmp(IDF,tab[j].name)==0))
            {
                if (!strcmp("",tab[j].typeSynt))
                {
                    strcpy (tab[j].typeSynt, typeSynt);
                    strcpy (tab[j].type, type);
                    tab[j].val.ival=val.ival;
                }
                else
                {
                    char erreur[50] ;
                    strcpy(erreur,"double declaration de l'idf ");
                    strcat(erreur,tab[j].name);
                    yyerror(erreur);
                }
            }
        }
        else
        {
            yyerror("the size can't be negatif");
        }
        break;
    case 2:
        for(j=0;((j<1000)&&(tab[j].state==1))&&(strcmp(IDF,tab[j].name)!=0);j++);
            if((j<1000)&&(strcmp(IDF,tab[j].name)==0))
            {
                if (!strcmp("",tab[j].typeSynt))
                {
                    strcpy (tab[j].typeSynt, typeSynt);
                    strcpy (tab[j].type, type);
                    if (!strcmp("STRING",typeSynt))
                        tab[j].val.sval = strdup (val.sval);
                    else if (!strcmp("CHAR",typeSynt))
                        tab[j].val.cval = val.cval;
                    else if (!strcmp("INTEGER",typeSynt))
                        tab[j].val.ival = val.ival;
                    else if (!strcmp("FLOAT",typeSynt))
                        tab[j].val.fval = val.fval;
                }
                else
                {
                    char erreur[50] ;
                    sprintf(erreur,"double declaration de l'idf %s",tab[j].name);
                    yyerror(erreur);
                }            
            }
        break;
    default:
        break;
    }
}

int verifierDeclarationIDF(char IDF[])
{
    int i;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
        if ((i<1000)&&(strcmp(IDF,tab[i].name))== 0)
        {
            if(!strcmp(tab[i].typeSynt,"")){
                char error[50];
                sprintf(error,"%s est utilise mais n'est pas declarer",IDF);
                yyerror(error);
            }         
        }
}

int verifierConst(char IDF[])
{
    char* error;
    int i;
    error = strdup(IDF);
    strcat(error," est une constante!");
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF,tab[i].name))== 0)
    {
        if (strcmp(tab[i].type,"CONST") == 0)
        {
            yyerror(error);
        }
        return 0;
    }
}

values getVal2(char IDF[])
{
    int i;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF,tab[i].name)==0) && (strcmp(tab[i].typeSynt,"INTEGER")) == 0)
    {
        return tab[i].val;
    }
}

int getVal(char IDF[])
{
    int i;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF,tab[i].name)==0) && (strcmp(tab[i].typeSynt,"INTEGER")) == 0)
    {
        return (int) tab[i].val.ival;
    }
}

int verifierIndex(char IDF[],int myIndex)
{
    int i,j;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF,tab[i].name)==0) && (strcmp(tab[i].type,"VAR-TAB"))== 0)
    {
        if (myIndex >= 0 && myIndex < tab[i].val.ival)
        {
            return 1;   
        }
        yyerror("Index error");
    }
}

void get(char IDF[],int type)
{
    int i;
    switch(type)
    {
        case 1:
            for(i=0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0);i++);
            if((i<1000)&&(strcmp(IDF,tab[i].name)==0))
            {
                if(!strcmp("INTEGER",tab[i].typeSynt))
                    scanf("%d",&tab[i].val.ival);
                else
                {
                    yyerror("incompatibilite type");
                }
            }
            break;
        case 2:
            for(i=0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0);i++);
            if((i<1000)&&(strcmp(IDF,tab[i].name)==0))
            {
                if(!strcmp("FLOAT",tab[i].typeSynt))
                {
                    scanf("%f",&tab[i].val.fval);
                }
                else
                {
                    yyerror("incompatibilite type");
                }
            }
            break;
        case 3:
            if(!strcmp("STRING",tab[i].typeSynt))
                {
                    scanf("%s",&tab[i].val.sval);
                }
                else
                {
                    yyerror("incompatibilite type");
                }
            break;
        case 4:
            if(!strcmp("CHAR",tab[i].typeSynt))
                {
                    scanf("%c",&tab[i].val.cval);
                }
                else
                {
                    yyerror("incompatibilite type");
                }
            break;
    }
}

void miseAjourIDF(char IDF1[],char IDF2[],values value,int type,int mode)
{
    int i,j;
    for(i=0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF1,tab[i].name)!=0);i++);
    if((i<1000)&&(strcmp(IDF1,tab[i].name)==0))
    {
        switch (mode)
        {
            case 0:
            {
                for(j=0;((j<1000)&&(tab[j].state==1))&&(strcmp(IDF2,tab[j].name)!=0);j++);
                if((j<1000)&&(strcmp(IDF2,tab[j].name)==0))
                {   
                    if (!strcmp(tab[j].typeSynt,"INTEGER"))
                    {
                        tab[i].val.ival = tab[j].val.ival;
                        return;
                    }
                    if (!strcmp(tab[j].typeSynt,"FLOAT"))
                    {
                        tab[i].val.fval = tab[j].val.fval;
                        return;
                    }
                    if (!strcmp(tab[j].typeSynt,"CHAR"))
                    {
                        tab[i].val.cval = tab[j].val.cval;
                        return;
                    }
                    if (!strcmp(tab[j].typeSynt,"STRING"))
                    {
                        tab[i].val.sval = strdup (tab[j].val.sval);
                        return;
                    }
                }
                break;
            }
            case 1:
            {
                switch (type)
                {
                    case 0:
                    {
                        for(j=0;((j<1000)&&(tabc[j].state==1))&&(tabc[j].val.ival!=value.ival);j++);
                        if((j<1000)&&(tabc[j].val.ival==value.ival))
                        {
                            tab[i].val.ival = tabc[j].val.ival;
                        }
                        break;
                    }
                    case 1:
                    {
                        for(j=0;((j<1000)&&(tabc[j].state==1))&&(tabc[j].val.fval!=value.fval);j++);
                        if((j<1000)&&(tabc[j].val.fval==value.fval))
                        {
                            tab[i].val.fval = tabc[j].val.fval;
                        }
                        break;
                    }
                    case 2:
                    {
                        for(j=0;((j<1000)&&(tabc[j].state==1))&&(tabc[j].val.cval!=value.cval);j++);
                        if((j<1000)&&(tabc[j].val.cval==value.cval))
                        {
                            tab[i].val.cval = tabc[j].val.cval;
                        }
                        break;
                    }
                    case 3:
                    {
                        tab[i].val.sval = strdup (value.sval);
                        break;
                    }
                }
                break;
            }
        }
    }
}

int getTypeSynt(char IDF[])
{
    int i;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(!strcmp(IDF,tab[i].name)))
    {
        if (!strcmp(tab[i].typeSynt,"INTEGER"))
        {
            return 1;
        }
        if (!strcmp(tab[i].typeSynt,"FLOAT"))
        {
            return 2;
        }
        if (!strcmp(tab[i].typeSynt,"CHAR"))
        {
            return 3;
        }
        if (!strcmp(tab[i].typeSynt,"STRING"))
        {
            return 4;
        }

    }
}

int divPar0(char IDF[])
{
    int i;
    for(i=0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0);i++);
    if((i<1000)&&(strcmp(IDF,tab[i].name)==0))
    {
        if(!strcmp(tab[i].type,"CONST"))
        {
            if(!strcmp(tab[i].typeSynt,"INTEGER"))
            {
                if(tab[i].val.ival==0)
                    return 1;
            }
            else if(!strcmp(tab[i].typeSynt,"FLOAT"))
            {
                if(tab[i].val.fval==0.0)
                    return 1;
            } 
        }
    }
    else if(IDF[0]!='t')
    {
        if(atof(IDF)==0.0)
            return 1;
    }
    return 0;
}

void empilerCh(int x)
{
    indexPile++;
    tabPile[indexPile]=x;
}

int depilerCh()
{
    int x;
    x = tabPile[indexPile];
    indexPile--;
    return x;
}
