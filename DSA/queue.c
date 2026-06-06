#include<stdio.h>
#define MAXSIZE 4
void insert(int qu[],int *rear){
    if(*rear==MAXSIZE-1)
    printf("Queue is overflow");
    else{
        int n;
        printf("Enter Number :");
        scanf("%d",&n);
        (*rear)++;
        qu[*rear]=n;
    }
}
void delete(int qu[],int *rear,int *front){
    if(*front>*rear)
    printf("Queue is Empty");
    else{
        int n=qu[*front];
        printf("Deleted Element is %d",n);
        (*front)++;
    }
}
void display(int qu[],int *rear,int *front){
    if(*front>*rear)
    printf("Queue is Empty");
    else{
        for(int i=*rear;i>=*front;i--)
        printf("%d ",qu[i]);
    }
}
int main(){
    int qu[MAXSIZE],rear = -1,front = 0;
    int ch;
    do{
        printf("\n1.Insert\n2.delete\n3.Display\n4.EXIT");
        printf("\nEnter choice :");
        scanf("%d",&ch);
        switch (ch){
            case 1:{
                insert(qu,&rear);
                break;
            }
            case 2:{
                delete(qu,&rear,&front);
                break;
            }
            case 3:{
                display(qu,&rear,&front);
                break;
            }
            case 4:{
                printf("EXIT");
            }
        }
    }while(ch!=4);
    return 0;
}