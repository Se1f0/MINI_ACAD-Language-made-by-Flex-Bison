%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "m.tab.h"
typedef struct
{
    int ival;
    float fval;
    char cval;
    char* sval;
}values;
extern void yyerror(const char* s);
extern void recherche (char entite[ ], char type [ ],char typeSynt[], values val, int y);
int nbSausLigne(char ch[]);
values val;
int yylineo=1;
int Col=1;
%}
LETTRE-MAJ [A-Z]
LETTRE-MIN [a-z]
CHIFFRE [0-9]
IDF {LETTRE-MAJ}({LETTRE-MIN}|{CHIFFRE})*
ENTIER ("("("-"|"+"){CHIFFRE}+")")|{CHIFFRE}+
REAL ("("("-"|"+"){CHIFFRE}+"."{CHIFFRE}*")")|({CHIFFRE}+"."{CHIFFRE}*)
CHAINE "\""[^\"]*"\""
CAR "'"[^']?"'"
BLANC [ \t]
Sl [ \n]
PLUS "+"
MOINS "-"
MUL "*"
DIV "/"
AFECTATION "="
PARENTHES-OUV "("
PARENTHES-FER ")" 
%%
"{" {
    Col = Col + strlen(yytext);
    recherche (yytext,"ACCOLADE_OUV","",val,2);
    return T_ACCOLADE_OUV;
}
"}" {
    Col = Col + strlen(yytext);
    recherche (yytext,"ACCOLADE_FER","",val,2);
    return T_ACCOLADE_FER;
}
">>" {
    Col = Col + strlen(yytext);
    recherche (yytext,"SUPSTRICT","",val,2);
    return T_SUPSTRICT;
}
">>=" {
    Col = Col + strlen(yytext);
    recherche (yytext,"SUPEGAL","",val,2);
    return T_SUPEGAL;
}
"<<" {
    Col = Col + strlen(yytext);
    recherche (yytext,"INFSTRICT","",val,2);
    return T_INFSTRICT;
}
"<<=" {
    Col = Col + strlen(yytext);
    recherche (yytext,"INFEGAL","",val,2);
    return T_INFEGAL;
}
"==" {
    Col = Col + strlen(yytext);
    recherche (yytext,"EGAL","",val,2);
    return T_EGAL;
}
"<<>>" {
    Col = Col + strlen(yytext);
    recherche (yytext,"DIFF","",val,2);
    return T_DIFF;
}
":" {
    Col = Col + strlen(yytext);
    recherche (yytext,"DEUX POINT","",val,2);
    return T_POINT;
}
"=" {
    Col = Col + strlen(yytext);
    recherche (yytext,"AFFECTATION","",val,2);
    return T_AFFECTATION;
}
"+" {
    Col = Col + strlen(yytext);
    recherche (yytext,"ADD","",val,2);
    return T_ADD;
}
"-" {
    Col = Col + strlen(yytext);
    recherche (yytext,"SUB","",val,2);
    return T_SUB;
}
"*" {
    Col = Col + strlen(yytext);
    recherche (yytext,"MUL","",val,2);
    return T_MUL;
}
"/" {
    Col = Col + strlen(yytext);
    recherche (yytext,"DIV","",val,2);
    return T_DIV;
}
"[" {
    Col = Col + strlen(yytext);
    recherche (yytext,"CROCHET_OUV","",val,2);
    return T_CROCHET_OUV;
}
"]" {
    Col = Col + strlen(yytext);
    recherche (yytext,"CROCHET_FER","",val,2);
    return T_CROCHET_FER;
}
"||" {
    Col = Col + strlen(yytext);
    recherche (yytext,"OU PIPE","",val,2);
    return T_OU;
}
"(" {
    Col = Col + strlen(yytext);
    recherche (yytext,"PARENTHESE_OUV","",val,2);
    return T_PARENTHESE_OUV;
}
")" {
    Col = Col + strlen(yytext);
    recherche (yytext,"PARENTHESE_FER","",val,2);
    return T_PARENTHESE_FER;
}
"//"[^//]+"//" {
    Col = Col + strlen(yytext);
    yylineo+= nbSausLigne(yytext);
}
@ {
    Col = Col + strlen(yytext);
    recherche (yytext,"AROBASE","",val,2);
    return T_AROBASE;
}
LET {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_LET;
}
GET {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_GET;
}
PROGRAM {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_PROGRAM;
}
BEGIN {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_BEGIN;
}
END {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_END;
}
VAR {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    yylval.sval  = strdup(yytext);
    return T_VAR;
}
SHOW {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_SHOW;
}
IF {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_IF;
}
RETURN {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_RETURN;
}
ENDIF {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_ENDIF;
}
ELSE {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_ELSE;
}
FOR {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_FOR;
}
END_FOR {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    return T_ENDFOR;
}
{IDF} {
    Col = Col + strlen(yytext);
    if(yyleng<=8)
    {
        recherche(yytext,"IDF","",val,0);
        yylval.sval  = strdup(yytext);
        return T_IDF;
    }
    
}
{REAL} {
    Col = Col + strlen(yytext);
    if(yytext[0]=='(')
    {
        char *intg = malloc(yyleng-2 * sizeof(char));
        for(int i = 0;i<yyleng-2;i++)
            intg[i]=yytext[i+1];
        yylval.fval = atof(intg);
        val.fval    = atof(intg);
        recherche(yytext,"CONST","FLOAT",val,3);
        return V_FLOAT;
    }
    else
    {
        yylval.fval = atof(yytext); 
        val.fval    = atof(yytext);
        recherche(yytext,"CONST","FLOAT",val,3);
        return V_FLOAT;
    }
}
{ENTIER} {
    Col = Col + strlen(yytext);
    if(yytext[0]=='(')
    {
        char *intg = malloc(yyleng-2 * sizeof(char));
        for(int i = 0;i<yyleng-2;i++)
            intg[i]=yytext[i+1];
        if(atoi(intg)>=-32768 && atoi(intg)<=32767){
                yylval.ival = atoi(intg);
                val.ival    = atoi(intg);
                recherche(yytext,"CONST","INTEGER",val,3);
                return V_INTEGER;
            }
        else
            printf("erreur\n");
    }
    else
    {
        if(atoi(yytext)>=-32768 && atoi(yytext)<=32767){
            yylval.ival = atoi(yytext);
            val.ival    = atoi(yytext);
            recherche(yytext,"CONST","INTEGER",val,3);
            return V_INTEGER;
        }
        else
            printf("erreur\n");
    }
}
{CAR} {
    Col = Col + strlen(yytext);
    yylval.cval = yytext[1];
    val.cval    = yytext[1];
    recherche(yytext,"CONST","CHAR",val,3);
    return V_CHAR;
}
{CHAINE} {
    Col = Col + strlen(yytext);
    if(!strcmp(yytext,"\"$\""))
    {
        recherche ("$","DOLLAR","",val,2);
        return T_DOLLAR;
    }
    if(!strcmp(yytext,"\"%\""))
    {
        recherche ("%","POURCENT","",val,2);
        return T_POURCENT;
    }
    if(!strcmp(yytext,"\"#\""))
    {
        recherche ("#","DIAZ","",val,2);
        return T_DIAZ;
    }
    if(!strcmp(yytext,"\"&\""))
    {
        recherche ("&","ETCOM","",val,2);
        return T_ETCOM;
    }
    char intg[yyleng-2];int j=0;
    for(int i=1;i<yyleng-1;i++)
    {
        intg[j]=yytext[i];j++;
    }
    yylval.sval = strdup(intg);
    val.sval    = strdup(intg);
    recherche(yytext,"CONST","STRING",val,3);
    return V_STRING;
}
£ {
    Col = Col + strlen(yytext);
    recherche (yytext,"FINIST","",val,2);
    return T_FINIST;
} 
\n {yylineo++;Col=1;
}
[ \t] ;
INTEGER {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    yylval.sval  = strdup(yytext);
    return T_INTEGER;
}
FLOAT {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    yylval.sval  = strdup(yytext);
    return T_FLOAT;
}
CHAR {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    yylval.sval  = strdup(yytext);
    return T_CHAR;
}
STRING {
    Col = Col + strlen(yytext);
    recherche (yytext,"MOT-CLET","",val,1);
    yylval.sval  = strdup(yytext);
    return T_STRING;
}
. { 
    Col = Col + strlen(yytext);    
    yyerror("lexecal");
}
%%
int nbSausLigne(char ch[]){
    int i,j,nb=0;
    for (i = 0; i < strlen(ch); i++)
    {
        if (ch[i]=='\n')
        {
            nb++;
        }
    }
    return nb;
}