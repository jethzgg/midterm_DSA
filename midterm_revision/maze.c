#include <stdio.h>
#include <stdlib.h>

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

int n,m,r,c,a[500][500], visited[500][500], distance[500][500];

int min1(int a, int b)
{
    return ((a < b) ? a : b);
}

int main()
{
	Deque *di = Init();
    Deque *dj = Init();
    scanf("%d %d %d %d", &n, &m, &r ,&c);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&a[i][j]);
            visited[i][j] = 0;
            distance[i][j] = 0;
        }
    }

    if (a[r - 1][c - 1]) 
    {
        printf("-1");
        destroy(di);
        destroy(dj);
        return 0;
    }

    push_back(di,r - 1);
    push_back(dj,c - 1);
    distance[r - 1][c - 1] = 0;
    int i1[4] = {-1, 0, 1, 0};
    int j1[4] = {0, -1, 0, 1};
    int i, j;
    while (!isEmpty(di) && !isEmpty(dj))
    {
        i = pop_front(di);
        j = pop_front(dj);
        if (i != -1 && j != - 1)
        {
            visited[i][j] = 1;
            if (i == (n - 1) || i == 0 && a[i][j] != 1)
            {
                printf("%d\n",distance[i][j] + 1);
                destroy(di);
                destroy(dj);
                return 0;
            }
            if (j == (m - 1) || j == 0 && a[i][j] != 1)
            {
                printf("%d\n",distance[i][j] + 1);
                destroy(di);
                destroy(dj);
                return 0;
            }
            for (int t = 0; t < 4; t++)
            {
                if ((i + i1[t]) >= 0 && (i + i1[t]) < n && (j + j1[t]) >= 0 && (j + j1[t]) < m)
                {
                    if (a[i + i1[t]][j + j1[t]] == 0 && visited[i + i1[t]][j + j1[t]] == 0)
                    {
                        push_back(di, i + i1[t]);
                        push_back(dj, j + j1[t]);
                        distance[i + i1[t]][j + j1[t]] = 1 + distance[i][j];
                    }
                }
            }
        }
    }
    printf("-1");
    destroy(di);
    destroy(dj);
    return 0;
}