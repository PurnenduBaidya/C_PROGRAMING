#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *create(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter value :");
    scanf("%d",&temp->data);
    temp->next=NULL;
}
void enqueue(node **rear,node **front){
    node *temp=create();
    if(temp==NULL){
        printf("Queue is overflowed");
    }
    else{
        if(*front==NULL){
            *rear=*front=temp;
    }
        else{
            (*rear)->next=temp;
            (*rear)=temp;
        }
    } 
}
void dequeue(node **rear,node **front){
    node *temp;
    temp=*front;
    if(*front==NULL){
        printf("Queue is empty");
    }
    else{
        *front = (*front)->next;
        printf("dequeued item is %d",temp->data);
        free(temp);
    }
}
void display(node **rear,node **front){
    if(*front==NULL){
        printf("Queue is empty");
    }
    else{
        node *temp;
        temp=*front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    node *front=NULL;
    node *rear=NULL;
    int ch;
    do{
        printf("\n1.enqueue\n2.dequeue\n3.Display\n4.EXIT");
        printf("\nEnter choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            enqueue(&rear,&front);
        }
            break;
        case 2:{
            dequeue(&rear,&front);
            break;
        }
        case 3:{
            display(&rear,&front);
            break;
        }
        case 4:{
            printf("Exit");
            break;
        }
        }
    }while(ch!=4);
    return 0;
}