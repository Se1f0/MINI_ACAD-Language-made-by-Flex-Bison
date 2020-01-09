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
char* idf;
int type,myIndex,mode,option;
int TabOrIdf = 0;
void yyerror(const char* s);
void mise_ajour(char type[], char typeSynt[],int mode ,values val,char IDF[]);
int verifierDeclarationIDF(char IDF[]);
int verifierTypeCompatible(char IDF1[],char IDF2[],int type);
int verifierConst(char IDF[]);
int verifierIndex(char IDF[],int myIndex);
int verifierTabOrVarOrConst(char IDF[]);
int semantiqueDeAff(char IDF[],char IDF2[],int choix);
int getVal(char IDF[]);
void get(char IDF[],int type);
void miseAjourIDF(char IDF1[],char IDF2[],values value,int type,int mode);
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
%type <ival>INDEX
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
LIST_VAL:                   V_INTEGER   {val.ival = $1;type = 0}
|                           V_FLOAT     {val.fval = $1;type = 1}
|                           V_CHAR      {val.cval = $1;type = 2}
|                           V_STRING    {val.sval = strdup($1);type = 3;}
;
LIST_VAL2:                  V_CHAR      {val.cval = $1;type = 2}
|                           V_STRING    {val.sval = strdup($1);type = 3;}
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
|                           T_IDF VAR {
                                        verifierDeclarationIDF($1);
                                        if (TabOrIdf)
                                        {
                                            verifierIndex($1,myIndex);
                                        }
                                        option=0;
                                        idf = strdup($1);
                                      }
|                           V_INTEGER {val.ival=$1;option=1;type=0;}
|                           V_FLOAT   {val.fval=$1;option=1;type=1;}
;
OPERAND:                    T_IDF VAR
|                           V_INTEGER
|                           V_FLOAT
;
EXPRESSION:                 LIST_VAL2 {mode=0;}
|                           OPERATION_ARITHMETIQUE{mode=1;}
;
VAR:                        T_CROCHET_OUV INDEX T_CROCHET_FER {TabOrIdf=1;}
|
;
AFFECTATION:                T_IDF VAR T_AFFECTATION EXPRESSION T_FINIST {
                                                                            verifierDeclarationIDF($1);
                                                                            if(!TabOrIdf)
                                                                            {
                                                                                verifierConst($1);
                                                                            }
                                                                            else
                                                                            {
                                                                                verifierIndex($1,myIndex);
                                                                            }
                                                                            if (!mode)
                                                                            {
                                                                                verifierTypeCompatible($1,"",type);
                                                                                miseAjourIDF($1,"",val,type,1);
                                                                            }
                                                                            if (mode)
                                                                            {
                                                                                switch (option)
                                                                                {
                                                                                    case 0:
                                                                                    {
                                                                                        verifierTypeCompatible($1,idf,-1);
                                                                                        miseAjourIDF($1,idf,val,type,0);
                                                                                        break;
                                                                                    }
                                                                                    case 1:
                                                                                    {
                                                                                        verifierTypeCompatible($1,"",type);
                                                                                        miseAjourIDF($1,"",val,type,1);
                                                                                        break;
                                                                                    }
                                                                                }  
                                                                            }                                                                           
                                                                        }
;
INDEX:                      T_IDF {verifierDeclarationIDF($1);verifierTypeCompatible($1,"",0);myIndex=getVal($1);}
|                           V_INTEGER {myIndex = $1;}
;
LISTES:                     T_DOLLAR {type = 1;}
|                           T_POURCENT {type = 2;}
|                           T_DIAZ {type = 3;}
|                           T_ETCOM {type = 4;}
;
ENTREE:                     T_GET T_PARENTHESE_OUV LISTES T_POINT T_AROBASE T_IDF T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($6);get($6,type);}
|                           T_GET T_PARENTHESE_OUV LISTES T_POINT T_AROBASE T_IDF T_CROCHET_OUV INDEX T_CROCHET_FER T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($6);}
;
SORTIE:                 T_SHOW T_PARENTHESE_OUV V_STRING T_PARENTHESE_FER T_FINIST {show1($3,"");}
|                       T_SHOW T_PARENTHESE_OUV V_STRING T_POINT T_IDF T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($5);show1($3,$5);}
|                       T_SHOW T_PARENTHESE_OUV V_STRING T_POINT T_IDF T_CROCHET_OUV INDEX T_CROCHET_FER T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($5);show1($3,$5);}
;       
CONDITIONIF:            T_IF T_PARENTHESE_OUV CONDITION T_PARENTHESE_FER T_POINT T_ACCOLADE_OUV BLOCK N_RETURN T_ACCOLADE_FER T_ENDIF {printf("IF correct\n");}
|                       T_IF T_PARENTHESE_OUV CONDITION T_PARENTHESE_FER T_POINT T_ACCOLADE_OUV BLOCK N_RETURN T_ACCOLADE_FER N_ELSE T_ENDIF {printf("IF ELSE correct\n");}
;       
N_ELSE:                 T_ELSE T_POINT T_ACCOLADE_OUV BLOCK N_RETURN T_ACCOLADE_FER
;       
N_RETURN:               T_RETURN T_PARENTHESE_OUV T_IDF T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($3);}
|                       T_RETURN T_PARENTHESE_OUV T_IDF T_CROCHET_OUV INDEX T_CROCHET_FER T_PARENTHESE_FER T_FINIST {verifierDeclarationIDF($3);}
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
int verifierTypeCompatible(char IDF1[],char IDF2[],int type)
{
    int i;
    char temp[10];
    char* error;
    for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF1,tab[i].name)!=0); i++);
    if ((i<1000)&&(strcmp(IDF1,tab[i].name))== 0)
    {
        strcpy(temp,tab[i].typeSynt);
    }

    switch (type)
    {
        case 0:{
            if (strcmp(temp,"INTEGER") != 0)
            {
                yyerror("Incompatibilite de type!");
            }
            return 0;
        } break;

        case 1:{
            if (strcmp(temp,"FLOAT") != 0)
            {
                yyerror("Incompatibilite de type!");
            }
            return 0;
        } break;

        case 2:{
            if (strcmp(temp,"CHAR") != 0)
            {
                yyerror("Incompatibilite de type!");
            }
            return 0;
        } break;

        case 3:{
            if (strcmp(temp,"STRING") != 0)
            {
                yyerror("Incompatibilite de type!");
            }
            return 0;
        } break;

        default:{
            for (i = 0;((i<1000)&&(tab[i].state==1))&&(strcmp(IDF2,tab[i].name)!=0); i++);
            if ((i<1000)&&(strcmp(IDF2,tab[i].name))== 0)
            {
                if (strcmp(temp,tab[i].typeSynt) != 0)
                {
                    yyerror("Incompatibilite de type!");
                }
                return 0;
            } 
        } break;
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
        ////////////////////////////////////////////////////////////////////////////////////////

        /* if (type == 0)
        {
            for (j = 0;((j<1000)&&(tab[j].state==1))&&(strcmp(index,tab[j].name)!=0); j++);
            if ((j<1000)&&(strcmp(index,tab[j].name)==0)&&(!strcmp(tab[j].typeSynt,"INTEGER")))
            {
                if (tab[j].val.ival < tab[i].val.ival)
                {
                    return 1;
                }
            }
            return 0;
        }
        if (type == 1)
        {
            for (j = 0;((j<1000)&&(tabc[j].state==1))&&(strcmp(index,tabc[j].name)!=0); j++);
            if ((j<1000)&&(strcmp(index,tabc[j].name)==0))
            {
                if (tabc[j].val.ival < tab[i].val.ival)
                {
                    return 1;
                }
            }
            return 0;
        } */
    }
}

/* int verifierVarOrConst(char IDF[])
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
    case 0: 
        final = final + verifierTypeCompatible(IDF,IDF2);
        break;
    case 1:
        final = final + verifierConst(IDF);
        break;
    }
    if (final < 2)
    {
        return 0;
    }
    return 1;
}
*/
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
                        printf("    Zabi\n");
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