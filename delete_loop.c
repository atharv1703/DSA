#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void removeloop(struct Node*, struct Node*);
int detectandremoveloop(struct Node* list)
{
    struct Node *slow_p=list, *fast_p=list;
    while(slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p)
        {
            removeloop(slow_p,list);
            return 1;
        }

    }
    return 0;
}
void removeloop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1;
    struct Node* ptr2;

    ptr1=head;
    while(1)
    {
        ptr2=loop_node;
        while(ptr2 -> next != loop_node && ptr2 -> next != ptr1)
        ptr2=ptr2->next;

        if(ptr2->next==ptr1)
        break;

        ptr1= ptr1->next;
    }
    ptr2->next=NULL;

}

void printlist(struct Node *node)
{
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
 
    detectandremoveloop(head);
 
    printf("Linked List after removing loop \n");
    printlist(head);
    return 0;
}