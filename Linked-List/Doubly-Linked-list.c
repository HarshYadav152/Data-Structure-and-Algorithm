#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* previous;
};
void DoublyLinkedlist(struct node * head)
{
    while (head!=NULL)
    {
        printf("Element is %d \n",head->data);
        head=head->next;
    }// At this point head points the third node
    // printf("%d",head->data);
    // printf("Accesed by previous pointer \n");
    // while (head!=NULL)
    // {
    //     printf("Element is %d \n",head->data);
    //     head=head->previous;
    // }
}
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));

    head->previous=NULL;
    head->data=10;
    head->next=second;

    second->previous=head;
    second->data=20;
    second->next=third;

    third->previous=second;
    third->data=30;
    third->next=fourth;

    fourth->previous=third;
    fourth->data=40;
    fourth->next=NULL;

    DoublyLinkedlist(head);
    return 0;
}