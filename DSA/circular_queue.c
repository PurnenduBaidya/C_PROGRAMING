#include<stdio.h>
#define MAX 4
void enqueue(int qu[],int *rear,int *front){
    if(*front==(*rear+1)%MAX)
    printf("Queue is overflowed");
    else{
        if(*front==-1){
            *front=*rear=0;
        }
        else{
        *rear=(*rear+1)%MAX;
        }
        int n;
        printf("Enter Number :");
        scanf("%d",&n);
        qu[*rear]=n;  
    }
}
void dequeue(int qu[],int *front,int *rear){
    if(*front==-1)
    {
        printf("Queue is Empty");
    }
    else{
        printf("Dequeued item is %d",qu[*front]);
        if(*front==*rear){
            *front=*rear=-1;
        }
        else{
            *front=(*front+1)%MAX;
        }   
    }
}
void display(int qu[],int *front,int *rear){
    if(*front==-1)
    printf("Queue is empty");
    else{
        int i = *front;
    while (1) {
        printf("%d ", qu[i]);
        if (i == *rear)
            break;
        i = (i + 1) % MAX;
    }
    }
}
int main(){
    int ch;
    int front =-1;
    int rear=-1;
    int qu[MAX];
    do{
        printf("\n1.enqueue\n2.dequeue\n3.Display\n4.EXIT");
        printf("\nEnter choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            enqueue(qu,&rear,&front);
        }
            break;
        case 2:{
            dequeue(qu,&front,&rear);
            break;
        }
        case 3:{
            display(qu,&front,&rear);
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