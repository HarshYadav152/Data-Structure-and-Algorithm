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

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode_BST(struct node *root, int value)
{

    struct node *inPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);  // free leaf node which to be deleted
        return NULL;
    }

    // search for the node to be deleted
    if (value < root->data) // if value is less than root->data to run deleteNode_BST for left subtree
    {
        root->left = deleteNode_BST(root->left, value);
    }
    else if (value > root->data) // if value is greater than root->data to run deleteNode_BST for right subtree
    {
        root->right = deleteNode_BST(root->right, value);
    }

    // Deletion strategy when the node is found
    else  // when the node is found then delete this node and when we reached out the NULL free this dynamic allocated memory location 
    {
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deleteNode_BST(root->left, inPre->data);
    }
    return root;
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
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p4->left = p6;
    p4->right = p7;

    inOrder(p);

    deleteNode_BST(p, 2);
    printf("\n");
    printf("7 deleted from the BST : \n");
    inOrder(p);
    return 0;
    
}