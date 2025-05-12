#include <stdio.h>
#include <stdlib.h>

typedef struct Deque
{
    char *array;
    int front_id;
    int back_id;
    int numsSize;
    int capacity;
} Deque;

Deque *Init(int capa)
{
    Deque *new = (Deque*)malloc(sizeof(Deque));
    new->array = (char*)malloc(sizeof(char) * capa);
    new->front_id = -1;
    new->back_id = 0;
    new->numsSize = 0;
    new->capacity = capa;
    return new;
}

int isEmpty(Deque *d)
{
    if (d == NULL) return 1;
    return d->numsSize == 0;
}

int isFull(Deque *d)
{
    if (d == NULL) return 0;
    return d->numsSize == d->capacity;
}

char front(Deque *d)
{
    if (d == NULL || isEmpty(d)) return -1;
    return (d->array)[d->front_id];
}

char back(Deque *d)
{
    if (d == NULL || isEmpty(d)) return -1;
    return (d->array)[d->back_id];
}

void push_front(Deque *d, char x)
{
    if (d == NULL || isFull(d))
    {
        return;
    }
    if (isEmpty(d))
    {
        d->front_id = 0;
        d->back_id = 0;
    }
    else if (d->front_id == 0)
    {
        d->front_id = d->capacity - 1;
    }
    else
    {
        d->front_id--;
    }
    (d->array)[d->front_id] = x;
    d->numsSize++;
}

void push_back(Deque *d, char x)
{
    if (d == NULL || isFull(d))
    {
        return;
    }
    if (isEmpty(d))
    {
        d->front_id = 0;
        d->back_id = 0;
    }
    else if (d->back_id == (d->capacity - 1))
    {
        d->back_id = 0;
    }
    else
    {
        d->back_id++;
    }
    (d->array)[d->back_id] = x;
    d->numsSize++;
}

char pop_front(Deque *d)
{
    if (d == NULL || isEmpty(d))
    {
        return "\0";
    }
    char value = front(d);
    d->numsSize--;
    if (isEmpty(d))
    {
        d->front_id = -1;
        d->back_id = 0;
    }
    else if (d->front_id == (d->capacity - 1))
    {
        d->front_id = 0;
    }
    else
    {
        d->front_id++;
    }
    return value;
}

char pop_back(Deque *d)
{
    if (d == NULL || isEmpty(d))
    {
        return -1;
    }
    char value = back(d);
    d->numsSize--;
    if (isEmpty(d))
    {
        d->front_id = -1;
        d->back_id = 0;
    }
    else if (d->back_id == 0)
    {
        d->back_id = d->capacity - 1;
    }
    else
    {
        d->back_id--;
    }
    return value;
}

void destroy(Deque *d)
{
    free(d);
}