%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"
#include "TSS.h"
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineo;
extern int Col;
values val;
void yyerror(const char* s);
void mise_ajour(char type[], char typeSynt[],int mode ,values val,char IDF[]);
int verifierDeclarationIDF(char IDF[]);
int verifierTypeCompatible(char IDF1[],char IDF2[]);
int verifierConst(char IDF[]);
int verifierIndex(char IDF[],int index);
int verifierTabOrVarOrConst(char IDF[]);
int semantiqueDeAff(char IDF[],char IDF2[],int choix);
%}
%union {
int ival;
float fval;
char cval;
char* sval;
}
%token T_POINT T_LET T_FINIST T_END T_PROGRAM T_BEGIN T_OU T_AFFECTATION T_DOLLAR T_AROBASE T_DIAZ T_POURCENT T_ETCOM T_RETURN T_GET T_SHOW T_ENDFOR
%token T_CROCHET_OUV T_CROCHET_FER T_PARENTHESE_OUV T_PARENTHESE_FER T_ACCOLADE_OUV T_ACCOLADE_FER T_OPERATEUR_ARITHMETIQUE  T_IF T_ENDIF T_ELSE T_FOR
%token <sval>T_IDF
%token <sval>T_INTEGER
%token <sval>T_FLOAT
%token <sval>T_CHAR
%token <sval>T_STRING
%token <sval>T_VAR
%token <fval>V_FLOAT
%token <ival>V_INTEGER
%token <cval>V_CHAR
%token <sval>V_STRING
%type <sval>LIST_IDF
%type <sval>LIST_TYPE
%left T_SUPSTRICT T_INFSTRICT T_SUPEGAL T_INFEGAL T_EGAL T_DIFF
%left T_ADD T_SUB
%left T_DIV T_MUL
%start MINI
%%
MINI:                       T_PROGRAM T_IDF {initialisationIDF();}  DECLARATION T_BEGIN BLOCK T_END {printf("execute avec succes\n");}
|                           T_PROGRAM T_IDF T_BEGIN BLOCK T_END
;
DECLARATION:                T_VAR LIST_IDF T_POINT LIST_TYPE T_FINIST {mise_ajour($1,$4,0,val,"");initialisationIDF();}
|                           T_VAR LIST_IDF T_POINT LIST_TYPE T_FINIST {mise_ajour($1,$4,0,val,"");initialisationIDF();} DECLARATION 
|                           T_VAR T_IDF T_CROCHET_OUV V_INTEGER T_CROCHET_FER T_POINT T_CROCHET_OUV LIST_TYPE T_CROCHET_FER T_FINIST {val.ival=$4; mise_ajour("VAR-TAB",$8,1,val,$2);}
|                           T_VAR T_IDF T_CROCHET_OUV V_INTEGER T_CROCHET_FER T_POINT T_CROCHET_OUV LIST_TYPE T_CROCHET_FER T_FINIST {val.ival=$4; mise_ajour("VAR-TAB",$8,1,val,$2);}DECLARATION 
|                           T_LET T_IDF LIST_TYPE T_AFFECTATION LIST_VAL T_FINIST {mise_ajour("CONST",$3,2,val,$2);}
|                           T_LET T_IDF LIST_TYPE T_AFFECTATION LIST_VAL T_FINIST {mise_ajour("CONST",$3,2,val,$2);} DECLARATION 
|                           T_LET T_IDF T_AFFECTATION LIST_VAL T_FINIST 
|                           T_LET T_IDF T_AFFECTATION LIST_VAL T_FINIST DECLARATION 
;
LIST_IDF:                   T_IDF T_OU LIST_IDF {insererIDF($1);}
|                           T_IDF {insererIDF($1);}
;
LIST_TYPE:                  T_INTEGER
|                           T_FLOAT
|                           T_CHAR
|                           T_STRING
;
LIST_VAL:                   V_INTEGER   {val.ival = $1;}
|                           V_FLOAT     {val.fval = $1;}
|                           V_CHAR      {val.cval = $1;}
|                           V_STRING    {val.sval = strdup($1);}
;
BLOCK:
|                           AFFECTATION {printf("AFFECTATION correct\n");} BLOCK
|                           ENTREE BLOCK {printf("GET correct\n");}
|                           SORTIE BLOCK {printf("SHOW correct\n");}
|                           CONDITIONIF BLOCK
|                           BOUCLE {printf("boucle correct\n");} BLOCK
;                
OPERATEUR_LOGIQUE:          T_SUPSTRICT
|                           T_INFSTRICT
|                           T_SUPEGAL
|                           T_INFEGAL
|                           T_EGAL
|                           T_DIFF
;
OPERATION_ARITHMETIQUE:     OPERATION_ARITHMETIQUE T_ADD OPERATION_ARITHMETIQUE
|                           OPERATION_ARITHMETIQUE T_SUB OPERATION_ARITHMETIQUE
|                           OPERATION_ARITHMETIQUE T_DIV OPERATION_ARITHMETIQUE
|                           OPERATION_ARITHMETIQUE T_MUL OPERATION_ARITHMETIQUE
|                           T_PARENTHESE_OUV OPERATION_ARITHMETIQUE T_PARENTHESE_FER
|                           T_SUB OPERATION_ARITHMETIQUE
|                           OPERAND
;
OPERAND:                    T_IDF {verifierDeclarationIDF($1);}
|                           V_INTEGER
|                           V_FLOAT
;
AFFECTATION:                T_IDF T_AFFECTATION EXPRESSION T_FINIST {verifierDeclarationIDF($1);if(verifierConst($1)) yyerror("const ERROR");}
|                           T_IDF T_CROCHET_OUV V_INTEGER T_CROCHET_FER T_AFFECTATION T_IDF T_FINIST {verifierDeclarationIDF($1);verifierDeclarationIDF($6);if(verifierIndex($1,$3)==0) yyerror("out of bound");}
;
EXPRESSION:                 LIST_VAL
|                           OPERATION_ARITHMETIQUE
;
LISTES:                     T_DOLLAR
|                           T_POURCENT
|                           T_DIAZ
|                           T_ETCOM
;
ENTREE:                     T_GET T_PARENTHESE_OUV LISTES T_POINT T_AROBASE T_IDF T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($6);}
;
SORTIE:                 T_SHOW T_PARENTHESE_OUV V_STRING T_PARENTHESE_FER T_FINIST
|                       T_SHOW T_PARENTHESE_OUV V_STRING T_POINT T_IDF T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($5);}
;       
CONDITIONIF:            T_IF T_PARENTHESE_OUV CONDITION T_PARENTHESE_FER T_POINT T_ACCOLADE_OUV BLOCK N_RETURN T_ACCOLADE_FER T_ENDIF {printf("IF correct\n");}
|                       T_IF T_PARENTHESE_OUV CONDITION T_PARENTHESE_FER T_POINT T_ACCOLADE_OUV BLOCK N_RETURN T_ACCOLADE_FER N_ELSE T_ENDIF {printf("IF ELSE correct\n");}
;       
N_ELSE:                 T_ELSE T_POINT T_ACCOLADE_OUV BLOCK N_RETURN T_ACCOLADE_FER
;       
N_RETURN:               T_RETURN T_PARENTHESE_OUV T_IDF T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($3);}
|                       T_RETURN T_PARENTHESE_OUV LIST_VAL T_PARENTHESE_FER T_FINIST
;       
CONDITION:              OPERAND OPERATEUR_LOGIQUE OPERAND
;       
BOUCLE:                 T_FOR T_PARENTHESE_OUV T_IDF T_POINT V_INTEGER T_POINT CONDITION T_PARENTHESE_FER BLOCK T_ENDFOR {verifierDeclarationIDF($3);}
;
%%
int main() {
    initialisation();
    yyin = fopen( "programme.txt", "r" );
    if (yyin==NULL) 
        printf("ERROR \n");
    else 
        yyparse();
    afficher();
    fclose(yyin);
    return 0;
}
void yyerror(const char* s) {
    FILE* prog =NULL;
    char ligneError[100];
    prog = fopen( "programme.txt", "r" );
    for (int i = 0; i < yylineo; i++)
    {
        fgets(ligneError,100,prog);
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
    while (Col >0)
    {
        if (ligneError[j]=='\t')
            fprintf(stderr, "\t");
        else
            fprintf(stderr, "-");
        j++;Col--;
    }
    fprintf(stderr, "^\n");
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
                    strcpy(erreur,"double declaration de l'idf ");
                    strcat(erreur,tab[j].name);
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
                char* error;
                error = strdup(IDF);
                strcat(error," n'est pas declarer");
                yyerror(error);
            }         
        }
}
int verifierTypeCompatible(char IDF1[],char IDF2[])
{
    int i;
    char temp[10];
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF1,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF1,tab[i].name))== 0)
    {
        strcpy(temp,tab[i].typeSynt);
    }
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF2,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF2,tab[i].name))== 0)
    {
        if (strcmp(temp,tab[i].typeSynt) == 0)
        {
            return 1;
        }
        return 0;
    }
}
int verifierConst(char IDF[])
{
    int i;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF,tab[i].name))== 0)
    {
        if (strcmp(tab[i].type,"CONST") == 0)
        {
            return 1;
        }
        return 0;
    }
}
int verifierIndex(char IDF[],int index)
{
    int i;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF,tab[i].name)==0) && (strcmp(tab[i].type,"VAR-TAB"))== 0)
    {
        if (tab[i].val.ival < index)
            return 0;
        return 1;
    }
}
int verifierVarOrConst(char IDF[])
{
    int i;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF,tab[i].name)) && (strcmp(tab[i].type,"CONST"))== 0)
    {
        return 1;
    }
    return 0;
}
int semantiqueDeAff(char IDF[],char IDF2[],int choix)
{
    int final = verifierDeclarationIDF(IDF);
    switch (choix)
    {
    case 0: /* VAR */
        final = final + verifierTypeCompatible(IDF,IDF2);
        break;
    case 1: /* CONST */
        final = final + verifierConst(IDF);
        break;
    }
    if (final < 2)
    {
        return 0;
    }
    return 1;
}