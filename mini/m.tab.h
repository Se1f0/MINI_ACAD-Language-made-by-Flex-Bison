
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 24 "m.y"

int ival;
float fval;
char cval;
char* sval;



/* Line 1676 of yacc.c  */
#line 111 "m.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


