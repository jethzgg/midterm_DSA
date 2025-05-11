#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define modulo 1000000007

typedef struct data
{
    int val;
    struct data *next;
    struct data *prev;
} data;
 
typedef struct Deque
{
    data *head;
    data *tail;
    int numsItems;
} Deque;
 
data *makenewNode(int x)
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
 
void push_front(Deque *d, int x)
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
 
void push_back(Deque *d, int x)
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
 
int front(Deque *d)
{
    if (!isEmpty(d)) return d->head->val;
    return -1;
}
 
int back(Deque *d)
{
    if (!isEmpty(d)) return d->tail->val;
    return -1;
}
 
int pop_front(Deque *d)
{
    if (!isEmpty(d))
    {
        int a = front(d);
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
    return -1;
}
 
int pop_back(Deque *d)
{
    if (!isEmpty(d))
    {
        int a = back(d);
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
    return -1;
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

// implementing a character deque with the same structure as above
typedef struct char_data
{
    char val;
    struct char_data *next;
    struct char_data *prev;
} char_data;

typedef struct char_Deque
{
    char_data *head;
    char_data *tail;
    int numsItems;
} char_Deque;

char_Deque *Init_char_Deque() {
    char_Deque *d = (char_Deque *)malloc(sizeof(char_Deque));
    d->head = NULL;
    d->tail = NULL;
    d->numsItems = 0;
    return d;
}

char_data *makenewCharNode(char x) {
    char_data *newNode = (char_data *)malloc(sizeof(char_data));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = x;
    return newNode;
}

//pop_front function for char deque
char pop_front_char(char_Deque *d) {
    if (!isEmpty(d)) {
        char a = d->head->val;
        if (d->head == d->tail) {
            d->tail = NULL;
            free(d->head);
            d->head = NULL;
        } else {
            char_data *del = d->head;
            d->head = d->head->next;
            d->head->prev = NULL;
            free(del);
        }
        d->numsItems -= 1;
        return a;
    }
    return -1;
}

//pop_back_char function for char deque
char pop_back_char(char_Deque *d) {
    if (!isEmpty(d)) {
        char a = d->tail->val;
        if (d->head == d->tail) {
            d->head = NULL;
            free(d->tail);
            d->tail = NULL;
        } else {
            char_data *del = d->tail;
            d->tail = d->tail->prev;
            d->tail->next = NULL;
            free(del);
        }
        d->numsItems -= 1;
        return a;
    }
    return -1;
}

//push_front function for char deque
void push_front_char(char_Deque *d, char x) {
    char_data *newNode = makenewCharNode(x);
    if (d->head == NULL) {
        d->head = newNode;
        d->tail = newNode;
    } else if (d->head == d->tail) {
        d->head = newNode;
        d->head->next = d->tail;
        d->tail->prev = d->head;
    } else {
        newNode->next = d->head;
        d->head->prev = newNode;
        d->head = newNode;
    }
    d->numsItems += 1;
}

//push_back function for char deque
void push_back_char(char_Deque *d, char x) {
    char_data *newNode = makenewCharNode(x);
    if (d->head == NULL) {
        d->head = newNode;
        d->tail = newNode;
    } else if (d->head == d->tail) {
        d->tail = newNode;
        d->head->next = d->tail;
        d->tail->prev = d->head;
    } else {
        newNode->prev = d->tail;
        d->tail->next = newNode;
        d->tail = newNode;
    }
    d->numsItems += 1;
}

//back function for char deque
char back_char(char_Deque *d) {
    if (!isEmpty(d)) return d->tail->val;
    return -1;
}

//front function for char deque
char front_char(char_Deque *d) {
    if (!isEmpty(d)) return d->head->val;
    return -1;
}

//isEmpty function for char deque
int isEmpty_char(char_Deque *d) {
    return d->numsItems == 0;
}

//destroy function for char deque
void destroy_char(char_Deque *d) {
    if (!isEmpty(d)) {
        char_data *del = d->head;
        while (d->head != NULL) {
            d->head = d->head->next;
            free(del);
            del = d->head;
        }
    }
}

int main()
{
    char_Deque *operands = Init_char_Deque();
    Deque *operators = Init();
    char s[20000];
    int a,b;
    char c;
    scanf("%s",s);
    for (int i = 0; i < (strlen(s) - 1); i++)
    {
        if (!('0' <= s[i] && s[i] <= '9') && !('0' <= s[i + 1] && s[i + 1] <= '9'))
        {
            printf("NOT_CORRECT");
            return 0;
        }
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            if (i > 0)
            {
                if (!('0' <= s[i - 1] && s[i - 1] <= '9'))
                push_back(operators,atoi(s + i) % modulo);    
            }
            else
            {
                push_back(operators,atoi(s + i) % modulo);     
            }
        }
        else if (s[i] == '+' && back_char(operands) == '*')
        {
            while (!isEmpty_char(operands) && back_char(operands) != '+')
            {
                a = pop_back(operators) % modulo;
                b = pop_back(operators) % modulo;
                c = pop_back_char(operands);
                printf("%d %d %c\n",a,b,c);
                push_back(operators,(b * a) % modulo);
            }
            push_back_char(operands,s[i]);
        }
        else
        {
            push_back_char(operands,s[i]);
        }
    }
    int result = 0;
    while (!isEmpty(operators))
    {
        a = pop_back(operators) % modulo;
        b = pop_back(operators) % modulo;
        c = pop_back_char(operands);
        if (isEmpty(operators)) 
        {
            if (c == '*') printf("%d\n",(b * a) % modulo);
            if (c == '+') printf("%d\n",(b + a) % modulo);
            return 0;
        }
        if (c == '*') push_back(operators,(b * a) % modulo);
        if (c == '+') push_back(operators,(b + a) % modulo);
    }
    return 0;
}