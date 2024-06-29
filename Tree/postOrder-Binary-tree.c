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

void postOrder(struct node * root){
    if (root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%2d",root->data);
    }
}
int main()
{
    // tree look like this 
    /* 
           4
          / \
         1   6
        / \
       5   2

       we have to traverse this tree in postOrder [5 2 1 6 4]
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
    


    printf("PostOrder Traversal of the given tree is : ");
    postOrder(p);
    
    return 0;
}