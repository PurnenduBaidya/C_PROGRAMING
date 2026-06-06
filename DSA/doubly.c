#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;
void *create();
void ins_beg();
void ins_last();
void del_beg();
void del_last();
void display();
void displayReverse();
int main(){
    node *head = NULL;
    int ch;
    do{
        printf("\n1.insert begining\n2.insert last\n3.delete begining\n4.delete last\n5.display\n6.displayReverse\n7.EXIT");
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
                displayReverse(&head);
                break;
            }
            case 7:{
                printf("EXIT");
                break;
            }
        }
    }while(ch!=7);
    return 0;
}
void *create(){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printf("Enter Value :");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void ins_beg(node **head){
    node *temp;
    temp = create();
    if(*head==NULL){
        *head = temp;
    }
    else{
        temp->next=(*head);
        (*head)->prev=temp;
        *head = temp;
    }
}
void ins_last(node **head){
    node *temp;
    temp = create();
    if(*head==NULL){
    *head = temp;
    }
    else{
        node *ptr;
        ptr = *head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next= temp;
        temp->prev=ptr;
    }
}
void del_beg(node **head){
    node *temp;//=create();
    if(*head==NULL){
        *head = temp;
    } 
    else{
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}
void del_last(node **head){
    node *temp;//=create();
    if(*head==NULL){
        printf("Node is Empty ");
    }
    else if((*head)->next==NULL){
        temp = *head;
        head = NULL;
        free(temp);
    }
    else{
        node *ptr=*head;
        node *preptr = *head;
        while(ptr->next!=NULL){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
}
void display(node **head){
    node *temp;
    temp = (*head);
    if(temp==NULL)
    printf("Empty");
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
void displayReverse(node **head){
    node *temp;
    temp = (*head);
    if(temp==NULL)
    printf("Empty");
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->prev;
        }
    }
}