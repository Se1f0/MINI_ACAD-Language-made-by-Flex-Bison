#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char IDF[10];
    int state;
}elementIDF;

elementIDF tabIDF[1000];

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
void initialisationIDF()
{
    int i;
    for (i=0;i<1000;i++) 
        tabIDF[i].state=0;
}