#include<stdio.h>
#define MAXSIZE 10
void push(int stack[],int *top){
    if(*top==MAXSIZE-1)
    printf("Stack is overflowed");
    else{
        int n;
        printf("Enter number :");
        scanf("%d",&n);
        (*top)++;
        stack[*top]=n;
    }
}
void pop(int stack[],int *top){
    if(*top==-1)
    printf("Stack is Empty");
    else{
        int a=stack[*top];
        (*top)--;
        printf("Dleted Element Is :%d",a);
    }
}
void display(int stack[],int *top){
    if(*top==-1)
    printf("Stack is empty");
    else{
        printf("Elements of Stack is :\n");
        for(int i=*top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}

int main(){
    int stack[MAXSIZE],top=-1;
    int ch;
    do{
    printf("\n1.Insert\n2.delete\n3.Display\n4.EXIT");
    printf("\nEnter Choice :");
    scanf("%d",&ch);
    switch(ch){
        case 1:{
            push(stack,&top);
            break;
        }
        case 2:{
            pop(stack,&top);
            break;
        }
        case 3:{
            display(stack,&top);
            break;
        }
        case 4:{
            printf("EXIT");
        }
    }
    }while(ch!=4);
    return 0;
}