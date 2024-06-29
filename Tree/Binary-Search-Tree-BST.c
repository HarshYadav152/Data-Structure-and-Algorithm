#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;  // for left child
    struct node *right; // for right child
};

struct node *createNode(int item)
{
    struct node *n = (struct node *)malloc(sizeof(struct node)); // creating the new node and allocating the memory to it
    n->data = item;                                              // setting the data to the new created node
    n->left = NULL;                                              // setting the left child to NULL
    n->right = NULL;                                             // setting the right child to NULL
    return n;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%2d", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{

    struct node *p = createNode(7);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(8);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(9);
    struct node *p6 = createNode(3);
    struct node *p7 = createNode(5);
    // tree look like this
    /*
           7
          / \
         2   8
        / \   \
       1   4   9
          / \
         3   5

    it is a Binary Search Tree BST
    */
    // linking the root node p to the child p1 and p2

    p->left = p1;
    p->right = p2;

    // second level
    p1->left = p3;
    p1->right = p4;

    p2->left = NULL;
    p2->right = p5;

    p4->left = p6;
    p4->right = p7;

    inOrder(p);

    printf("\n%d", isBST(p));

    if(isBST)
        printf("\nThis tree is Binary Search Tree : ");
    else
        printf("This is not BST : ");

    return 0;
}