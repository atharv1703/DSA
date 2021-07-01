#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int detectstart( struct Node* list)
{
   
    struct Node *slow_p=list, *fast_p=list;
    while(slow_p && fast_p && fast_p->next)
    {
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p)
        {
            break;
        }
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
    }
    if(slow_p!=fast_p)
    return NULL;
    
    slow_p=list;
    while(slow_p!=fast_p)
    {
       slow_p = slow_p->next;
       fast_p = fast_p->next; 
    }
    return slow_p;
}
void printlist(struct Node *node)
{
    struct node *temp;
    temp=node;
    while(node != NULL){
    printf("%d ", node->data);
    node=node->next;
    }
}
struct Node* newNode(int key)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->next=NULL;
    return temp;

}
int main()
{
    
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next = head->next->next;
    struct Node* res= detectstart(head);

    if(res==NULL){
    printf("Loop does not exist \n");
    }
    else
    printf("Loop starting node is");
    
    return 0;
}
