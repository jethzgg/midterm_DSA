#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int power;
    int coefficient;
    struct poly *next;
} poly;

poly *newNode(int a, int b)
{
    poly *new = (poly*)malloc(sizeof(poly));
    new -> coefficient = a;
    new -> power = b;
    new -> next = NULL;
    return new;
}

poly *addNode(poly* head, int a, int b)
{
    poly *prev = NULL;
    poly *cur = head;
    if (head == NULL)
    {
        poly *new = newNode(a,b);
        return new;
    }
    while (cur != NULL)
    {
        if (cur -> power < b)
        {
            poly *new = newNode(a,b);
            new -> next = cur;
            if (prev == NULL) return new;
            prev -> next = new;
            return head;
        }
        if (cur -> power == b)
        {
            cur -> coefficient += a;
            return head;
        }
        prev = cur;
        cur = cur -> next;
        if (cur == NULL) 
        {
            poly *new = newNode(a,b);
            prev -> next = new;
            return head;
        }
    }
}

int evaluate(poly *head, int x)
{
    poly *cur = head;
    int sum = 0;
    while (cur != NULL)
    {
        sum += cur -> coefficient * (int)pow(x,cur -> power);
        cur = cur -> next;
    }
    return sum;
}

poly *addPoly(poly *p1, poly *p2)
{
    if (p1 == NULL || p2 == NULL)
    {
        return NULL;
    }
    if (p1 == NULL)
    {
        return p2;
    }
    if (p2 == NULL)
    {
        return p1;
    }
    poly *head = NULL;
    int a;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1 -> power == p2 -> power)
        {
            a = p1 -> coefficient + p2 -> coefficient;
            head = addNode(head,a,p1 -> power);
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        else if (p1 -> power > p2 -> power)
        {
            head = addNode(head,p1 -> coefficient,p1 -> power);
            p1 = p1 -> next;
        }
        else if (p1 -> power < p2 -> power)
        {
            head = addNode(head,p2 -> coefficient, p2 -> power);
            p2 = p2 -> next;
        }
    }
    if (p1 == NULL && p2 != NULL)
    {
        while (p2 != NULL)
        {
            head = addNode(head,p2 -> coefficient, p2 -> power);
            p2 = p2 -> next;
        }
    }
    if (p1 != NULL && p2 == NULL)
    {
        while (p1 != NULL)
        {
            head = addNode(head,p1 -> coefficient,p1 -> power);
            p1 = p1 -> next;
        }
    }
    return head;
}

void destroy(poly *head)
{
    poly *cur = head;
    while (head != NULL)
    {
        head = head -> next;
        free(cur);
        cur = head;
    }
}

void createID(int i, int *hhh)
{
    if (hhh[i - 1] == 1)
    {
        return;
    }
    else
    {
        hhh[i - 1] = 1;
        return;
    }
}

int main()
{
    poly *list[50];
    int *hhh = (int*)calloc(50,sizeof(int));
    char s[10] = {'\0'};
    int id, coef, exp, id1, id2, var;
    do
    {
        scanf("%s",s);
        if (strcmp(s,"*\0") == 0)
        {
            break;
        }
        if (strcmp(s,"Create\0") == 0)
        {
            scanf("%d",&id);
            createID(id,hhh);
        }
        if (strcmp(s,"AddTerm\0") == 0)
        {
            scanf("%d %d %d",&id,&coef,&exp);
            if (hhh[id - 1] == 0)
            {
                list[id - 1] = NULL;
                hhh[id - 1] = 1;
            }
            list[id - 1] = addNode(list[id - 1], coef, exp);
        }
        if (strcmp(s,"EvaluatePoly\0") == 0)
        {
            scanf("%d %d",&id,&var);
            printf("%d\n",evaluate(list[id - 1], var));
        }
        if (strcmp(s,"AddPoly\0") == 0)
        {
            scanf("%d %d %d",&id1,&id2,&id);
            list[id - 1] = addPoly(list[id1 - 1], list[id2 - 1]);
            if (hhh[id - 1] == 0)
            {
                if (list[id - 1] == NULL) hhh[id - 1] = 0;
                else hhh[id - 1] = 1;
            }
        }
        if (strcmp(s,"PrintPoly\0") == 0)
        {
            scanf("%d",&id);
            if (hhh[id - 1] == 1)
            {
                poly *cur = list[id - 1];
                while (cur != NULL)
                {
                    printf("%d %d ",cur -> coefficient, cur -> power);
                    cur = cur -> next;
                }
                printf("\n");
            }
        }
        if (strcmp(s,"Destroy\0") == 0)
        {
            scanf("%d",&id);
            if (hhh[id - 1] == 1)
            {
                destroy(list[id - 1]);
            }
        }
    } while (strcmp(s,"*\0") != 0);
}
