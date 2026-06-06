#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void *create();
void ins_beg();
void ins_last();
void del_beg();
void del_last();
void display();
int main(){
    node (*head) = NULL;
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
void *create(){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printf("Enter Value :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
void ins_beg(node **head){
    node *temp;
    temp = create();
    if(*head==NULL){
        *head = temp;
        temp->next=(*head);
    }
    else{
        temp->next=(*head);
        *head = temp;
    }
}
void ins_last(node **head){
    node *temp;
    temp = create();
    if(*head==NULL){
    *head = temp;
    temp->next=(*head);
    }
    else{
        node *ptr;
        ptr = *head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next= temp;
        temp->next=(*head);
    }
}
void del_beg(node **head){
    node *temp;//=create();
    if(*head==NULL){
        printf("empty");
    } 
    else{
        temp=*head;
        if(*head==(*head)->next){
            printf("Deleted item is :%d",(*head)->data);
            free(temp);
        }
        else{
            temp = *head;
            *head = (*head)->next;
            free(temp);
        }
    }
}
void del_last(node **head){
    node *temp;//=create();
    if(*head==NULL){
        printf("Node is Empty ");
    }
    else if(*head==(*head)->next){
        temp = *head;
        *head = NULL;
        free(temp);
    }
    else{
        node *ptr=*head;
        node *preptr = *head;
        while(ptr->next!=NULL){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = (*head);
        free(ptr);
    }
}
void display(node **head){
    node *temp;
    if(temp==NULL)
    printf("Empty");
    else{
        temp = (*head)->next;
        do{
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp->next!=(*head));
    }
}