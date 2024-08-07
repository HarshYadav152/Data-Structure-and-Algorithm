#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;  // for left child
    struct node *right; // for right child
};

struct node* createNode(int item){
    struct node *n=(struct node*)malloc(sizeof(struct node)); // creating th enew node and allocating the memory to it
    n->data=item; // setting the data to the new created node
    n->left=NULL; // setting th left child to NULL
    n->right=NULL; // setting th right child to NULL
    return n;
} 

void preOrder(struct node * root){
    if (root!=NULL)
    {
        printf("%2d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    // tree look like this 
    /* 
           7
          / \
         2   1
        / \
       0   4
          / \
         3   5

       we have to traverse this tree in preOrder [7 2 0 4 3 5 1]
    */

    struct node* p=createNode(7);
    struct node* p1=createNode(2);
    struct node* p2=createNode(1);
    struct node* p3=createNode(0);
    struct node* p4=createNode(4);
    struct node* p5=createNode(3);
    struct node* p6=createNode(5);
    // linking the root node p to the child p1 and p2 
    p->left=p1;
    p->right=p2;

    // second level
    p1->left=p3;
    p1->right=p4;

    // third level
    p4->left=p5;
    p4->right=p6;

    printf("PreOrder Traversal of the given tree is : ");
    preOrder(p);
    
    return 0;
}