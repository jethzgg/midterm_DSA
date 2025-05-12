#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *parent;
    struct TreeNode *leftMostChild;
    struct TreeNode *rightSiblings;
} TreeNode;

TreeNode *root = NULL;
TreeNode *Node = NULL;

TreeNode *makeNode(int u)
{
    TreeNode *new = (TreeNode*)malloc(sizeof(TreeNode));
    new->val = u;
    new->parent = NULL;
    new->leftMostChild = NULL;
    new->rightSiblings = NULL;
    return new;
}

void findNode(TreeNode *root, int x)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val == x)
    {
        Node = root;
        return;
    }
    TreeNode *cur = root->leftMostChild;
    while (cur != NULL)
    {
        findNode(cur, x);
        cur = cur->rightSiblings;
    }
}

TreeNode *Insert(TreeNode *root, int u, int v)
{
    Node = NULL;
    findNode(root, v);
    if (Node != NULL)
    {
        TreeNode *parentNode = Node;
        Node = NULL;
        findNode(root, u);
        if (Node == NULL)
        {
            TreeNode *new = makeNode(u);
            if (parentNode->leftMostChild == NULL)
            {
                parentNode->leftMostChild = new;
                new->parent = parentNode;
            }
            else
            {
                TreeNode *cur = parentNode->leftMostChild;
                while (cur->rightSiblings != NULL)
                {
                    cur = cur->rightSiblings;
                }
                cur->rightSiblings = new;
                new->parent = parentNode;
            }
        }
    }
    return root;
}

int max1(int a, int b)
{
    return ((a > b) ? a : b);
}

int Height(TreeNode *node)
{
    if (node == NULL) 
    {
        return 0;
    }
    int h = 0;
    node = node->leftMostChild;
    while (node != NULL)
    {
        h = max1(h, Height(node));
        node = node->rightSiblings;
    }
    return h + 1;
}

int Depth(TreeNode *root, TreeNode *node)
{
    int d = 1;
    while (node != root)
    {
        node = node->parent;
        d++;
    }
    return d;
}

int main()
{
    char command[10];
    int u,v;
    while (1)
    {
        scanf("%s",command);
        if (!strcmp(command,"*")) break;
        if (!strcmp(command,"MakeRoot"))
        {
            scanf("%d%*c", &u);
            root = makeNode(u);
        }
        if (!strcmp(command,"Insert"))
        {
            scanf("%d %d%*c", &u, &v);
            root = Insert(root, u, v);
        }
        if (!strcmp(command,"Height"))
        {
            scanf("%d%*c",&u);
            Node = NULL;
            findNode(root, u);
            printf("%d\n",Height(Node));
        }
        if (!strcmp(command,"Depth"))
        {
            scanf("%d%*c",&u);
            Node = NULL;
            findNode(root, u);
            printf("%d\n",Depth(root, Node));
        }
    }
    return 0;
}