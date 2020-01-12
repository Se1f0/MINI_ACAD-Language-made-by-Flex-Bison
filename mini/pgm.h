#include<string.h>
#include<stdio.h>
typedef struct qdr
{
    char oper[100];
    char op1[100];
    char op2[100];
    char res[100];
}qdr;
typedef struct cellule *pileCh;
    typedef struct cellule
    {
        int val;
        pileCh svt;
    }cellule;
qdr quad[1000];
extern int qc;
void quadr(char opr[],char op1[],char op2[],char res[])
{
    strcpy(quad[qc].oper , opr);
    strcpy(quad[qc].op1 , op1);
    strcpy(quad[qc].op2 , op2);
    strcpy(quad[qc].res , res);
}
void ajour_quad(int num_quad, int colon_quad, char val [])
{
    switch (colon_quad)
    {
    case 0:
        strcpy(quad[num_quad].oper , val);
        break;
    case 1:
        strcpy(quad[num_quad].op1 , val);
        break;
    case 2:
        strcpy(quad[num_quad].op2 , val);
        break;
    case 3:
        strcpy(quad[num_quad].res , val);
        break;
    default:
        break;
    }
}

void afficher_qdr()
{
    printf("*********************Les quadruplets***********************\n");
    int i;
    for(i=0;i<qc;i++)
    {
        printf("\n %d - ( %s , %s , %s ,%s)",i,quad[i].oper,quad[i].op1,quad[i].op2,quad[i].res);
        printf("\n---------------------------------------------------\n");
    }
}
void empilerCh(pileCh *p,int x)
{
    pileCh temp;
    temp = malloc(sizeof(pileCh));
    temp->val = x;
    if(p==NULL)
    {
        temp->svt = NULL;
        *p = temp;
    }
    else
    {
        temp->svt = *p;
        *p = temp;
    }
    
}
int depilerCh(pileCh *p)
{
    if (*p!=NULL)
    {
        pileCh temp;
        int x;
        x = (*p)->val;
        temp = *p;
        *p=(*p)->svt;
        free(temp);
        return x;
    }
    else
    {
        return EXIT_FAILURE;
    }
    
}