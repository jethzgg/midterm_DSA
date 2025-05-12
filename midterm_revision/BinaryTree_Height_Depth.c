#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

TreeNode *root;
TreeNode *Node;

TreeNode *makeNode(int u)
{
    TreeNode *new = (TreeNode*)malloc(sizeof(TreeNode));
    new->val = u;
    new->parent = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void findNode(TreeNode *root, int x)
{
    if (root == NULL) return;
    if (root->val == x)
    {
        Node = root;
        return;
    }
    findNode(root->left, x);
    findNode(root->right, x);
}

TreeNode *AddLeft(TreeNode *root, int u, int v)
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
            if (parentNode->left == NULL)
            {
                TreeNode *new = makeNode(u);
                parentNode->left = new;
                new->parent = parentNode;
            }
        }
    }
    return root;
}

TreeNode *AddRight(TreeNode *root, int u, int v)
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
            if (parentNode->right == NULL)
            {
                TreeNode *new = makeNode(u);
                parentNode->right = new;
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

int z = 1;

int Height(TreeNode *root)
{
    if (root == NULL) return 0;
    int h = 0;
    int h1 = Height(root->left);
    int h2 = Height(root->right);
    if (fabs(h1 - h2) > 1) z = 0;
    h = max1(h1, h2);
    return h + 1;
}

int main()
{
    char command[10];
    int u, v;
    while (1)
    {
        scanf("%s",command);
        if (!strcmp(command, "*")) break;
        if (!strcmp(command, "MakeRoot"))
        {
            scanf("%d%*c", &u);
            root = makeNode(u);
        }
        if (!strcmp(command, "AddLeft"))
        {
            scanf("%d %d%*c", &u, &v);
            root = AddLeft(root, u, v);
        }
        if (!strcmp(command, "AddRight"))
        {
            scanf("%d %d%*c", &u, &v);
            root = AddRight(root, u, v);
        }
    }
    int h = Height(root);
    printf("%d %d\n",z,h);
    return 0;
}

