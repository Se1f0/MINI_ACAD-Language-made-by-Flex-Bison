#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int ival;
    float fval;
    char cval;
    char* sval;
}values;

typedef struct
{
    int state;
    char name[20];
    char type[20];
    char typeSynt[20];
    values val;
    int sub;
}element;

typedef struct
{
    int state;
    char name[20];
    char type[20];
}elt;


element tab[1000];
element tabc[1000];
elt tabs[40],tabm[40];


void inserer(char entite[], char type[],char typeSynt[], values val, int i, int y)
{
    switch (y)
    {
    case 0: /*insertion dans la table des IDF et CONST*/
        tab[i].state=1;
        strcpy (tab[i].name, entite);
        strcpy (tab[i].type, type);
        strcpy (tab[i].typeSynt, typeSynt);
        if (!strcmp("CONST",type))
        {
            if (!strcmp("STRING",typeSynt))
                tab[i].val.sval = strdup (val.sval);
            else if (!strcmp("CHAR",typeSynt))
                tab[i].val.cval = val.cval;
            else if (!strcmp("INTEGER",typeSynt))
                tab[i].val.ival = val.ival;
            else if (!strcmp("FLOAT",typeSynt))
                tab[i].val.fval = val.fval;
        }
        break;
    case 1: /*insertion dans la table des mots clés*/
        tabm[i].state=1;
        strcpy (tabm[i].name,entite);
        strcpy (tabm[i].type,type);
        break;
    case 2: /*insertion dans la table des séparateurs*/
        tabs[i].state=1;
        strcpy (tabs[i].name,entite);
        strcpy (tabs[i].type,type);
        break;
    case 3: /*insertion dans la table des IDF et CONST*/
        tabc[i].state=1;
        strcpy (tabc[i].name, entite);
        strcpy (tabc[i].type, type);
        strcpy (tabc[i].typeSynt, typeSynt);
        if (!strcmp("CONST",type))
        {
            if (!strcmp("STRING",typeSynt))
                tabc[i].val.sval = strdup (val.sval);
            else if (!strcmp("CHAR",typeSynt))
                tabc[i].val.cval = val.cval;
            else if (!strcmp("INTEGER",typeSynt))
                tabc[i].val.ival = val.ival;
            else if (!strcmp("FLOAT",typeSynt))
                tabc[i].val.fval = val.fval;
        }
        break;
    }
}

void recherche (char entite[ ], char type [ ],char typeSynt[], values val, int y)
{
    int j,i;
    switch (y)
    {
    case 0: /*verifier si la case dans la tables des IDF et CONST est libre*/
        for(i=0;((i<1000)&&(tab[i].state==1))&&(strcmp(entite,tab[i].name)!=0);i++);
        if((i<1000)&&(strcmp(entite,tab[i].name)!=0))
            inserer(entite, type,typeSynt, val, i, 0);
        break;
    case 1: /*verifer si la case dans la tables des mots clés est libre*/
        for(i=0; ((i<40)&&(tabm[i].state==1))&&(strcmp(entite,tabm[i].name)!=0);i++);
        if((i<40)&&(strcmp(entite,tabm[i].name)!=0))
            inserer(entite,type,typeSynt,val,i,1);
        break;
    case 2: /*verifer si la case dans la tables des séparateurs est libre*/
        for(i=0;((i<40)&&(tabs[i].state==1))&&(strcmp(entite,tabs[i].name)!=0);i++);
        if((i<40)&&(strcmp(entite,tabs[i].name)!=0))
            inserer(entite,type,typeSynt,val,i,2);
        break;
    case 3: /*verifer si la case dans la tables des séparateurs est libre*/
        for(i=0;((i<40)&&(tabc[i].state==1))&&(strcmp(entite,tabc[i].name)!=0);i++);
        if((i<40)&&(strcmp(entite,tabc[i].name)!=0))
            inserer(entite,type,typeSynt,val,i,3);
        break;
    } /* fn switch*/
} /* fn recherche*/


void initialisation()
{
    int i;
    for (i=0;i<1000;i++) tab[i].state=0;
    for (i=0;i<1000;i++) tabc[i].state=0;
    for (i=0;i<40;i++)
    {
        tabs[i].state=0;
        tabm[i].state=0;
    }
}
void afficher()
{
    int i;
    printf("\n\nla table des IDF \n");
    for(i = 0;i<1000;i++)
    {
        if(tab[i].state==1)
        {
            if(!strcmp(tab[i].typeSynt,"CHAINE"))
                printf("Entite :%s\t\t",tab[i].name);
            else
                printf("Entite :%s\t\t\t\t",tab[i].name);
            printf("Type :%s\t\t",tab[i].type);
            printf("TypeSynt :%s\t\t",tab[i].typeSynt);
            if(tab[i].sub!=0)
                printf("SUB : %d\t\t",tab[i].sub);
            if (!strcmp(tab[i].type,"VAR-TAB"))
            {
                if (!strcmp(tab[i].typeSynt,"CHAR")||!strcmp(tab[i].typeSynt,"FLOAT"))
                    printf("\tTaille-MAX : %d",tab[i].val.ival);
                else
                printf("Taille-MAX : %d",tab[i].val.ival);
            }
            else if (!strcmp("STRING",tab[i].typeSynt))
                printf ("VAL : %s",tab[i].val.sval);
            else if (!strcmp("CHAR",tab[i].typeSynt))
                printf("\tVAL : %c",tab[i].val.cval);
            else if (!strcmp("INTEGER",tab[i].typeSynt))
                printf("VAL : %d",tab[i].val.ival);
            else if (!strcmp("FLOAT",tab[i].typeSynt))
                printf("\tVAL : %f",tab[i].val.fval);
            printf("\n");
            
        }
    }
    printf("\n\nla table des CONST \n");
    for(i = 0;i<1000;i++)
    {
        if(tabc[i].state==1)
        {
            if(!strcmp(tabc[i].typeSynt,"CHAINE"))
                printf("Entite :%s\t\t",tabc[i].name);
            else
                printf("Entite :%s\t\t\t\t",tabc[i].name);
            printf("Type :%s\t\t",tabc[i].type);
            printf("TypeSynt :%s\t\t",tabc[i].typeSynt);
            if(tabc[i].sub!=0)
                printf("SUB : %d\t\t",tabc[i].sub);
            if (!strcmp(tabc[i].type,"VAR-TAB"))
            {
                printf("Taille-MAX : %d\t\t",tabc[i].val.ival);
            }
            else if (!strcmp("STRING",tabc[i].typeSynt))
                printf ("VAL : %s\t\t",tabc[i].val.sval);
            else if (!strcmp("CHAR",tabc[i].typeSynt))
                printf("VAL : %c\t\t",tabc[i].val.cval);
            else if (!strcmp("INTEGER",tabc[i].typeSynt))
                printf("VAL : %d\t\t",tabc[i].val.ival);
            else if (!strcmp("FLOAT",tabc[i].typeSynt))
                printf("VAL : %f\t\t",tabc[i].val.fval);
            printf("\n");
            
        }
    }
    printf("\nla table des mots cles\n");
    for(i=0;(i<40);i++)
    {
        if(tabm[i].state==1)
        {
            printf("Entite %s\t\t",tabm[i].name);
            printf("Type %s\n",tabm[i].type);
        }
    }
    printf("\nla table des separateurs\n");
    for(i=0;i<40;i++) 
    {
        if(tabs[i].state==1)
        {
            printf("Entite %s\t\t",tabs[i].name);
            printf("Type %s\n",tabs[i].type);
        }
    }
}
