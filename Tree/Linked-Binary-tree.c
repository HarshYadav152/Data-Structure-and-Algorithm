#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;  // for left child
    struct node *right; // for right child
};

struct node* createNode(int item){
    struct node *n=(struct node*)malloc(sizeof(struct node)); // creating the new node and allocating the memory to it
    n->data=item; // setting the data to the new created node
    n->left=NULL; // setting th left child to NULL
    n->right=NULL; // setting th right child to NULL
    return n;
}
int main()
{

    /*// constructing the first node ( root node )
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    // first left child of the root node
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data=3;
    p1->left=NULL;
    p1->right=NULL;

    // first right child of the root node
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data=1;
    p2->left=NULL;
    p2->right=NULL;

    // Link the left and right child p1 and p2 to the root node
    ptr->data=2;
    ptr->left=p1;
    ptr->right=p2; */

    struct node* p=createNode(2);
    struct node* p1=createNode(1);
    struct node* p2=createNode(4);
    struct node* p3=createNode(11);
    struct node* p4=createNode(12);
    struct node* p5=createNode(3);
    // linking the root node p to the child p1 and p2 
    p->left=p1;
    p->right=p2;

    // second level
    p1->left=p3;
    p1->right=p4;

    p2->left=NULL;
    p2->right=p5;

    
    return 0;
}