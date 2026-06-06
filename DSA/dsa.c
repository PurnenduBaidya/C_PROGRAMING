#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void *create(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter value :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
void ins_beg(node **head){
    node *temp=create();
    if(*head==NULL)
    *head=temp;
    else{
        temp->next=(*head);
        (*head)=temp;
    }
}
void ins_last(node **head){
    node *temp= create();
    if(*head==NULL)
    *head=temp;
    else{
        node *ptr=*head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void del_beg(node **head){
    node *temp;
    if(*head==NULL)
    printf("Linked list is empty");
    else{
        temp=*head;
        *head=temp->next;
        free(temp);
    }
}
void del_last(node **head){
    node *temp;
    if(*head==NULL)
    printf("Linked list is empty");
    else if((*head)->next==NULL){
        temp=*head;
        *head=NULL;
        free(temp);
    }
    else{
        node *ptr;
        node *preptr;
        ptr=*head;
        preptr=*head;
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr = ptr->next;
        }
        preptr->next=NULL;
        free(ptr);
    }
}
void display(node **head){
    node *temp;
    temp=(*head);
    if(temp==NULL)
    printf("Empty");
    else{
        while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        }
    }
}
int main(){
    node *head = NULL;
    int ch;
    do{
        printf("\n1.insert begining\n2.insert last\n3.delete begining\n4.delete last\n5.display\n6.EXIT");
        printf("\nEnter Choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                ins_beg(&head);
                break;
            }
            case 2:{
                ins_last(&head);
                break;
            }
            case 3:{
                del_beg(&head);
                break;
            }
            case 4:{
                del_last(&head);
                break;
            }
            case 5:{
                display(&head);
                break;
            }
            case 6:{
                printf("EXIT");
                break;
            }
        }
    }while(ch!=6);
    return 0;
}