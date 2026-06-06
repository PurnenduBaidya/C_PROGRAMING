#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void *create(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("enter value :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
void ins_beg(node **head){
    node *temp;
    temp=create();
    if(*head==NULL){
        *head=temp;
        temp->next=(*head);
    }
    else{
        node *ptr;
        ptr=*head;
        temp->next=*head;
        while(ptr->next!=(*head)){
            ptr=ptr->next;
        }
        ptr->next=temp;
        *head=temp;
    }
}
void ins_last(node **head){
    node *temp;
    temp=create();
    if(*head==NULL){
        *head=temp;
        temp->next=(*head);
    }
    else{
        node *ptr;
        ptr=*head;
        while(ptr->next!=(*head)){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=(*head);
    }
}
void del_beg(node **head){
    node *temp;
    if(*head==NULL){
        printf("circular linked list is empty");
    }
    else{
        if((*head)->next==(*head)){
            temp=*head;
            *head=NULL;
            printf("deleted data is %d",temp->data);
            free(temp);

        }
        else{
            node *ptr;
            temp=*head;
            *head=temp->next;
            ptr=*head;
            while(ptr->next!=temp){
                ptr=ptr->next;
            }
            ptr->next=(*head);
            printf("deleted data is %d",temp->data);
            free(temp);
        }
    }
}
void del_last(node **head){
    node *temp;
    if(*head==NULL){
        printf("circular linked list is empty");
    }
    else if((*head)->next==*head){
        temp=*head;
        *head=NULL;
        printf("deleted data is %d",temp->data);
        free(temp);
    }
    else{
        node *ptr;
        node *preptr;
        ptr=*head;
        while(ptr->next!=(*head)){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=*head;
        printf("Deleted data is %d",ptr->data);
        free(ptr);
    }
}
void display(node **head){
    node *temp;
    temp=(*head);
    if(*head==NULL){
        printf("circular linked list is empty");
    }
    else{
        while(temp->next!=(*head)){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
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