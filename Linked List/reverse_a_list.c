#include<stdio.h>
#include<stdlib.h>
struct node
{
    /* data */
    int data;
    struct node* next;
};

static void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while(current!=NULL){
    next= current->next;
    current->next=prev;

    prev=current;
    current=next;
    }
    *head_ref=prev;

}
void push(struct node** head_ref,int new_data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;

}
void printList(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
 
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed Linked list \n");
    printList(head);
    getchar();
}
