#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *leftMostChild;
    struct TreeNode *rightSiblings;
} TreeNode;

TreeNode *root = NULL;
TreeNode *Node = NULL;

TreeNode *makeNode(int u)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = u;
    node->leftMostChild = NULL;
    node->rightSiblings = NULL;
    return node;
}

void findNode(TreeNode *root, int v)
{
    if (root == NULL) return;
    TreeNode *cur = root;
    if (cur->val == v)
    {
        Node = cur;
        return;
    }
    cur = cur->leftMostChild;
    while (cur != NULL)
    {
        findNode(cur, v);
        cur = cur->rightSiblings;
    }
}

TreeNode *Insert(TreeNode *root, int u, int v)
{
    Node = NULL;
    findNode(root, v);
    TreeNode *parentNode = Node;
    Node = NULL;
    if (parentNode != NULL)
    {
        findNode(root, u);
        if (Node == NULL)
        {
            if (parentNode->leftMostChild == NULL)
            {
                parentNode->leftMostChild = makeNode(u);
            }
            else
            {
                parentNode = parentNode->leftMostChild;
                while (parentNode->rightSiblings != NULL)
                {
                    parentNode = parentNode->rightSiblings;
                }
                parentNode->rightSiblings = makeNode(u);
            }
        }
    }
    return root;
}

void PreOrder(TreeNode *root)
{
    if (root == NULL) return;
    TreeNode *cur = root;
    printf("%d ", root->val);
    cur = cur->leftMostChild;
    while (cur != NULL)
    {
        PreOrder(cur);
        cur = cur->rightSiblings;
    }
}

void InOrder(TreeNode *root)
{
    if (root == NULL) return;
    TreeNode *cur = root->leftMostChild;
    InOrder(cur);
    printf("%d ", root->val);
    while (cur != NULL)
    {
        cur = cur->rightSiblings;
        InOrder(cur);
    }
}

void PostOrder(TreeNode *root)
{
    if (root == NULL) return;
    TreeNode *cur = root->leftMostChild;
    while (cur != NULL)
    {
        PostOrder(cur);
        cur = cur->rightSiblings;
    }
    printf("%d ",root->val);
}

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
            root = makeNode(u);
        }
        if (!strcmp(command, "Insert"))
        {
            scanf("%d %d%*c", &u, &v);  
            root = Insert(root,u,v); 
        }
        if (!strcmp(command, "InOrder"))
        {
            InOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "PreOrder"))
        {
            PreOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "PostOrder"))
        {
            PostOrder(root);
            printf("\n");
        }
        if (!strcmp(command, "*"))
        {
            break;
        }
    }
    return 0;
}