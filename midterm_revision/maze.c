#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
    int *arr;
    int front_idx;
    int rear_idx;
    int numsItems;
    int capacity;
} Deque;

Deque* Init(int cap) {
    if (cap <= 0) {
        return NULL;
    }
    Deque* d = (Deque*)malloc(sizeof(Deque));
    if (!d) {
        return NULL;
    }
    d->arr = (int*)malloc(cap * sizeof(int));
    if (!d->arr) {
        free(d);
        return NULL;
    }
    d->capacity = cap;
    d->front_idx = -1;
    d->rear_idx = 0;
    d->numsItems = 0;
    return d;
}

int isFull(Deque* d) {
    if (!d) return 0;
    return (d->numsItems == d->capacity);
}

int isEmpty(Deque* d) {
    if (!d) return 1;
    return (d->numsItems == 0);
}

void push_front(Deque* d, int x) {
    if (!d || isFull(d)) {
        return;
    }
    if (isEmpty(d)) {
        d->front_idx = 0;
        d->rear_idx = 0;
    } else if (d->front_idx == 0) {
        d->front_idx = d->capacity - 1;
    } else {
        d->front_idx = d->front_idx - 1;
    }
    d->arr[d->front_idx] = x;
    d->numsItems = d->numsItems + 1;
}

void push_back(Deque* d, int x) {
    if (!d || isFull(d)) {
        return;
    }
    if (isEmpty(d)) {
        d->front_idx = 0;
        d->rear_idx = 0;
    } else if (d->rear_idx == d->capacity - 1) {
        d->rear_idx = 0;
    } else {
        d->rear_idx = d->rear_idx + 1;
    }
    d->arr[d->rear_idx] = x;
    d->numsItems = d->numsItems + 1;
}

int pop_front(Deque* d) {
    if (!d || isEmpty(d)) {
        return -1;
    }
    int item = d->arr[d->front_idx];
    d->numsItems = d->numsItems - 1;
    if (isEmpty(d)) {
        d->front_idx = -1;
        d->rear_idx = 0;
    } else if (d->front_idx == d->capacity - 1) {
        d->front_idx = 0;
    } else {
        d->front_idx = d->front_idx + 1;
    }
    return item;
}

int pop_back(Deque* d) {
    if (!d || isEmpty(d)) {
        return -1;
    }
    int item = d->arr[d->rear_idx];
    d->numsItems = d->numsItems - 1;
    if (isEmpty(d)) {
        d->front_idx = -1;
        d->rear_idx = 0;
    } else if (d->rear_idx == 0) {
        d->rear_idx = d->capacity - 1;
    } else {
        d->rear_idx = d->rear_idx - 1;
    }
    return item;
}

int front(Deque* d) {
    if (!d || isEmpty(d)) {
        return -1;
    }
    return d->arr[d->front_idx];
}

int back(Deque* d) {
    if (!d || isEmpty(d)) {
        return -1;
    }
    return d->arr[d->rear_idx];
}

void destroy(Deque* d) {
    if (d) {
        if (d->arr) {
            free(d->arr);
        }
        free(d);
    }
}

int n,m,r,c,a[1000][1000], visited[1000][1000], distance[1000][1000];


int main()
{
	Deque *di = Init(1000);
    Deque *dj = Init(1000);
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
    visited[r - 1][c - 1] = 1;
    int i1[4] = {-1, 0, 1, 0};
    int j1[4] = {0, -1, 0, 1};
    int i, j;
    while (!isEmpty(di) && !isEmpty(dj))
    {
        i = pop_front(di);
        j = pop_front(dj);
        if (i != -1 && j != - 1)
        {
            
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
                        visited[i + i1[t]][j + j1[t]] = 1;
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
