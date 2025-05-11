#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    char val;
    struct data *next;
    struct data *prev;
} data;
 
typedef struct Deque
{
    data *head;
    data *tail;
    int numsItems;
} Deque;
 
data *makenewNode(char x)
{
    data *newNode = (data*)malloc(sizeof(data));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = x;
    return newNode;
}
 
Deque *Init()
{
    Deque *d = (Deque*)malloc(sizeof(Deque));
    d->head = NULL;
    d->tail = NULL;
    d->numsItems = 0;
    return d;
}
 
int isEmpty(Deque *d)
{
    return d->numsItems == 0;
}
 
void push_front(Deque *d, char x)
{
    data *newNode = makenewNode(x);
    if (d->head == NULL)
    {
        d->head = newNode;
        d->tail = newNode;
    }
    else if (d->head == d->tail)
    {
        d->head = newNode;
        d->head->next = d->tail;
        d->tail->prev = d->head;
    }
    else
    {
        newNode->next = d->head;
        d->head->prev = newNode;
        d->head = newNode;
    }
    d->numsItems += 1;
}
 
void push_back(Deque *d, char x)
{
    data *newNode = makenewNode(x);
    if (d->head == NULL)
    {
        d->head = newNode;
        d->tail = newNode;
    }
    else if (d->head == d->tail)
    {
        d->tail = newNode;
        d->head->next = d->tail;
        d->tail->prev = d->head;
    }
    else
    {
        newNode->prev = d->tail;
        d->tail->next = newNode;
        d->tail = newNode;
    }
    d->numsItems += 1;
}
 
char front(Deque *d)
{
    if (!isEmpty(d)) return d->head->val;
    return -1;
}
 
char back(Deque *d)
{
    if (!isEmpty(d)) return d->tail->val;
    return -1;
}
 
char pop_front(Deque *d)
{
    if (!isEmpty(d))
    {
        char a = front(d);
        if (d->head == d->tail)
        {
            d->tail = NULL;
            free(d->head);
            d->head = NULL;
        }
        else
        {
            data *del = d->head;
            d->head = d->head->next;
            d->head->prev = NULL;
            free(del);
        }
        d->numsItems -= 1;
        return a;
    }
    return '\0';
}
 
char pop_back(Deque *d)
{
    if (!isEmpty(d))
    {
        char a = back(d);
        if (d->head == d->tail)
        {
            d->head = NULL;
            free(d->tail);
            d->tail = NULL;
        }
        else
        {
            data *del = d->tail;
            d->tail = d->tail->prev;
            d->tail->next = NULL;
            free(del);
        }
        d->numsItems -= 1;
        return a;
    }
    return '\0';
}
 
void destroy(Deque *d)
{
    if (!isEmpty(d))
    {
        data *del = d->head;
        while (d->head != NULL)
        {
            d->head = d->head->next;
            free(del);
            del = d->head;
        }
    }
}
 
char a[1000000];

int check(char *a)
{
    Deque *q1 = Init();
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == ')')
        {
            if (isEmpty(q1)) return 0;
            if (back(q1) != '(') return 0;
            pop_back(q1);
        }
        else if (a[i] == '}')
        {
            if (isEmpty(q1)) return 0;
            if (back(q1) != '{') return 0;
            pop_back(q1);
        }
        else if (a[i] == ']')
        {
            if (isEmpty(q1)) return 0;
            if (back(q1) != '[') return 0;
            pop_back(q1);
        }
        else
        {
            push_back(q1,a[i]);
        }
    }
    return isEmpty(q1);
}

int main()
{
	
    scanf("%s",a);
    printf("%d\n",check(a));
    return 0;
}