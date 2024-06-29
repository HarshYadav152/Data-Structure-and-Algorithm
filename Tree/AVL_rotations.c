#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return tree->height;
}

struct node *createNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

/*
        y      Right Rotation           x
       / \        ------->             / \
      x   T3                          T1  y
     / \          <--------              / \ 
    T1 T2       Left Rotation            T2 T3
*/
struct node * rightRotate(struct node *y)
{
    struct node *x = y->left;  // initial position of node x in the tree with root y
    struct node *T2 = x->right;  // initial position of node T2 in the tree with root y

    x->right = y;  // Rearrange the node of the tree after rotation 
    y->left = T2;  // Rearrange the node of the tree after rotation

    y->height = (max(getHeight(y->right), getHeight(y->left)) + 1); // it holds the height of the tree after rotation
    x->height = (max(getHeight(x->right), getHeight(x->left)) + 1); // it holds the height of the tree after rotation

    return x; // x is now root node of the AVL tree
}
struct node * leftRotate(struct node *x)
{
    struct node *y = x->right;  // initial position of node y in the tree with root x
    struct node *T2 = y->left;  // initial position of node T2 in the tree with root x

    y->left = x;  // Rearrange the node of the tree after rotation
    x->right = T2;  // Rearrange the node of the tree after rotation

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  // it holds the height of the tree after rotation
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  // it holds the height of the tree after rotation

    return y; // y is now root node of the AVL tree
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return (createNode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int BF = getBalanceFactor(node);

    // Left - Left Case
    if (BF > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // Right - Right Case
    if (BF < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // Left - Right Case
    if (BF > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right - Left Case
    if (BF < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%2d", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%2d", root->key);
        inOrder(root->right);
    }
}

void postOrder(struct node * root){
    if (root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%2d",root->key);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 0);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);

    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);

    printf("\n%d",root->height);
    return 0;
}