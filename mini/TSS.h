#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char IDF[10];
    int state;
}elementIDF;

typedef struct
{
    int state;
    int type;
}strType;

typedef struct
{
    char nom[10];
    char type[10];
    char typeSynt[10];
    int state;
    values val;
}elementEXP;

typedef struct
{
    elementEXP numerateur[10];
    elementEXP denominateur[10];
    int state;
}elementDIV;

elementDIV tabDIV[1000];
elementEXP tabEXP[1000];
elementIDF tabIDF[1000];

void initialisationEXP()
{
    int i;
    for (i=0;i<1000;i++) 
        tabEXP[i].state=0;
}

int insererEXP(char idf[],values val,char typeSynt[],char type[])
{
    int i = 0;
    for (i = 0;((i<1000)&&(tabEXP[i].state==1)); i++);
    if (i<1000)
    {
        tabEXP[i].state=1;
        strcpy(tabEXP[i].nom,idf);
        tabEXP[i].val=val;
        strcpy(tabEXP[i].type,type);
        strcpy(tabEXP[i].typeSynt,typeSynt);
        return 1;
    }
    return 0;
}

int getSize()
{
    int i;
    for (i = 0;((i<1000)&&(tabEXP[i].state==1)); i++);
    return i;
}

void afficherEXP()
{
    values val;
    for (int i = 0; (i < 1000)&&(tabEXP[i].state==1); i++)
    {  
        if (!strcmp(tabEXP[i].typeSynt,"INTEGER"))
        {
            printf("%s-->%d-->%s\n",tabEXP[i].nom,tabEXP[i].val.ival,tabEXP[i].type);
        }
        if (!strcmp(tabEXP[i].typeSynt,"FLOAT"))
        {
            printf("%s-->%f\n",tabEXP[i].nom,tabEXP[i].val.fval,tabEXP[i].type);
        }
    }
}

void initialisationDIV()
{
    int i;
    for (i=0;i<1000;i++) 
        tabEXP[i].state=0;
        initialisationEXP(tabDIV[i].numerateur);
        initialisationEXP(tabDIV[i].denominateur);
}

void initialisationIDF()
{
    int i;
    for (i=0;i<1000;i++) 
        tabIDF[i].state=0;
}

int insererIDF(char idf[])
{
    int i = 0;
    for (i = 0;((i<1000)&&(tabIDF[i].state==1)); i++);
    if (i<1000)
    {
        tabIDF[i].state=1;
        strcpy(tabIDF[i].IDF,idf);
        return 1;
    }
    return 0;
}

void afficherIDF()
{
    for (int i = 0; (i < 1000)&&(tabIDF[i].state==1); i++)
    {
        printf("%s\n",tabIDF[i].IDF);
    }
}
strType tabType[1000];
void initTabType()
{
    int i;
    for (i = 0; i < 1000 ; i++)
    {
        tabType[i].state=0;
    }
}
void ajoutType(int x)
{
    int i;
    for (i = 0; (i < 1000)&&tabType[i].state ==1 ; i++);
    if (i<1000)
    {
        tabType[i].state=1;
        tabType[i].type = x;
    }
}
void affich()
{
    int i;
    for (i = 0; ((i < 1000)&& tabType[i].state); i++)
    {
        printf("type = %d\n",tabType[i].type);
    }
}
int getTypeExp()
{
    int i,j,bool = 1;
    if (tabType[0].state==1)
    {
        for (i = 1; (i < 1000)&&tabType[i].state ==1 &&bool; i++)
        {
            if (tabType[0].type!=tabType[i].type)
            {
                bool = 0;
            }
        }
    }
    else
    {
        return -1;
    }
    if (bool)
    {
        return tabType[0].type;
    }
    else
    {
        return 0;
    }
}
