#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *makeNode(int a)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = a;
    node->next = NULL;
    return node;
}

Node *findNode(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->val == x)
        {
            return root;
        }
        root = root->next;
    }
    return NULL;
}

Node *addlast(Node *root, int k)
{
    if (!findNode(root, k))
    {
        Node *new = makeNode(k);
        Node *cur = root;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new;
    }
    return root;
}

Node *addfirst(Node *root, int k)
{
    if (!findNode(root, k))
    {
        Node *new = makeNode(k);
        new->next = root;
        root = new;
    }
    return root;
}

Node *addbefore(Node *root, int u, int v)
{
    Node *cur, *prevNode = root, *new;
    if ((cur = findNode(root, v)) && !findNode(root, u))
    {
        if (cur == root) return addfirst(root,u);
        while (prevNode -> next != cur) prevNode = prevNode->next;
        new = makeNode(u);
        prevNode->next = new;
        new->next = cur;
    }
    return root;
}

Node *addafter(Node *root, int u, int v)
{
    Node *cur, *nextNode, *new;
    if ((cur = findNode(root, v)) && !findNode(root, u))
    {
        nextNode = cur->next;
        new = makeNode(u);
        cur->next = new;
        new->next = nextNode;
    }
    return root;
}

Node *removeNode(Node *root, int k)
{
    Node *cur, *prevNode = root;
    if (cur = findNode(root, k))
    {
        if (cur == root)
        {
            root = cur->next;
            free(cur);
            return root;
        }
        while (prevNode -> next != cur) prevNode = prevNode->next;
        prevNode->next = cur->next;
        free(cur);
    }
    return root;
}

Node *reverse(Node* root)
{
    Node *cur, *prev = NULL;
    while (root != NULL)
    {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    root = prev;
    return root;
}

int main()
{
    char command[10];
    int k,u,v,n;
    scanf("%d",&n);
    Node *a = NULL;
    Node *cur = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&k);
        if (!a)
        {
            a = makeNode(k);
            cur = a;
        }
        else
        {
            cur->next = makeNode(k);
            cur = cur->next;
        }
    }
    while (1)
    {
        scanf("%s",command);
        if (!strcmp(command,"addlast\0"))
        {
            scanf("%d", &k);
            a = addlast(a,k);
        }
        if (!strcmp(command,"addfirst\0"))
        {
            scanf("%d", &k);
            a = addfirst(a,k);
        }
        if (!strcmp(command,"addbefore\0"))
        {
            scanf("%d %d", &u, &v);
            a = addbefore(a,u,v);
        }
        if (!strcmp(command,"addafter\0"))
        {
            scanf("%d %d", &u, &v);
            a = addafter(a,u,v);
        }
        if (!strcmp(command,"remove\0"))
        {
            scanf("%d", &k);
            a = removeNode(a,k);
        }
        if (!strcmp(command,"reverse\0"))
        {
            a = reverse(a);
        }
        if (!strcmp(command,"#\0")) break;
    }
    while (a != NULL)
    {
        printf("%d ",a->val);
        a = a->next;
    }
    return 0;
}