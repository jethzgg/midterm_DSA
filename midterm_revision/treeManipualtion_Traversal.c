#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree
{
    int val;
    struct Tree *leftmostChild;
    struct Tree *rightSiblings;
} Tree;

Tree *makeRoot(int u)
{
    Tree *root = (Tree*)malloc(sizeof(Tree));
    root->val = u;
    root->leftmostChild = NULL;
    root->rightSiblings = NULL;
    return root;
}

Tree *Node = NULL;

void findNode(Tree *root, int v)
{
    if (root == NULL) return;
    if (root->val == v) 
    {
        Node = root;
        return;
    }
    Tree *cur = root->leftmostChild;
    while (cur != NULL)
    {
        findNode(cur, v);
        cur = cur->rightSiblings;
    }
}

Tree *makeNode(int u)
{
    Tree *node = (Tree*)malloc(sizeof(Tree));
    node->val = u;
    node->leftmostChild = NULL;
    node->rightSiblings = NULL;
    return node;
}

Tree *insertNode(Tree *root, int u, int v)
{
    Node = NULL;
    findNode(root, v);
    if (Node != NULL)
    {
        if (Node->leftmostChild == NULL)
        {
            Node->leftmostChild = makeNode(u);
        }
        else
        {
            Node = Node->leftmostChild;
            while (Node->rightSiblings != NULL)
            {
                Node = Node->rightSiblings;
            }
            Node->rightSiblings = makeNode(u);
        }
    }
    return root;
}

void inOrder(Tree *root)
{
    if (root == NULL) return;
    Tree *cur = root;
    cur = cur->leftmostChild;
    inOrder(cur);
    printf("%d ",root->val);
    while (cur != NULL)
    {
        cur = cur->rightSiblings;
        inOrder(cur);
    }
}

void preOrder(Tree *root)
{
    if (root == NULL) return;
    printf("%d ", root->val);
    Tree *cur = root->leftmostChild;
    while (cur != NULL)
    {
        preOrder(cur);
        cur = cur->rightSiblings;
    }
}

void postOrder(Tree *root)
{
    if (root == NULL) return;
    Tree *cur = root;
    cur = cur->leftmostChild;
    while (cur != NULL)
    {
        postOrder(cur);
        cur = cur->rightSiblings;
    }
    printf("%d ",root->val);
}

Tree *root = NULL;

int main()
{
    char command[9];
    int u, v;
    while (1)
    {
        scanf("%s",command);
        if (!strcmp(command, "MakeRoot"))
        {
            scanf("%d%*c", &u);
            root = makeRoot(u);
        }
        if (!strcmp(command, "Insert"))
        {
            scanf("%d %d%*c", &u, &v);  
            root = insertNode(root,u,v); 
        }
        if (!strcmp(command, "InOrder"))
        {
            inOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "PreOrder"))
        {
            preOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "PostOrder"))
        {
            postOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "*"))
        {
            break;
        }
    }
    return 0;
}