#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;
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

void PreOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

void PostOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
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
        if (!strcmp(command, "PreOrder"))
        {
            PreOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "InOrder"))
        {
            InOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "PostOrder"))
        {
            PostOrder(root);
            printf("\n");
        }
    }
    return 0;
}