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

elementIDF tabIDF[1000];

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
