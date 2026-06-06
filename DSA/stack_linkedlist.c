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
    return temp;
}
void push(node **top){
    node *temp=create();
    if(temp==NULL)
    printf("stack is overflow");
    else{
        temp->next=*top;
        *top=temp;
    }
}
void pop(node **top){
    node *temp;
    if(*top==NULL)
    printf("stack is empty");
    else{
        temp=*top;
        *top=(*top)->next;
        printf("poped item is %d",temp->data);
        free(temp);
    }
}
void display(node **top){
    node *temp;
    if(*top==NULL)
    printf("Stack is empty");
    else{
        temp=*top;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    node *top = NULL;
    int ch;
    do{
        printf("\n1.push \n2.pop \n3.display\n4.EXIT");
        printf("\nEnter Choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                push(&top);
                break;
            }
            case 2:{
                pop(&top);
                break;
            }
            case 3:{
                display(&top);
                break;
            }
            case 4:{
                printf("EXIT");
                break;
            }
        }
    }while(ch!=4);
    return 0;
}