#include<stdio.h>
void bubble(int arr[],int *n){
    for(int i=0;i<*n;i++){
        for(int j=0;j<*n;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void printArray(int arr[],int *n){
    for(int i=0;i<*n;i++){
        printf("%d ",arr[i]);
    }
}
void insertion(int arr[],int *n){
    int idx,val;
    printf("Enter idx and val :");
    scanf("%d%d",&idx,&val);
    if(idx<0||idx>*n+1){
        printf("Invalide");
    }else{
        for(int i=*n;i>=idx;i--){
            arr[i]=arr[i-1];
        }
            arr[idx]=val;
    } 
    (*n)++;
}
void delete(int arr[],int *n){
    int idx;
    printf("Enter index :");
    scanf("%d",&idx);
    for(int i=idx;i<*n;i++){
        arr[i]=arr[i+1];
    }
    (*n)--;
}
int main(){
    int n;
    printf("Enter size of Array :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter %d element :",i+1);
        scanf("%d",&arr[i]);
    }
    int ch;
    do{
    printf("\n1.bubble Sort\n2.insertion\n3.delete\n4.display\n5.EXIT");
    printf("\nEnter Choice :");
    scanf("%d",&ch);
        switch(ch){
            case 1:{
                bubble(arr,&n);
                break;
            }
            case 2:{
                insertion(arr,&n);
                break;
            }
            case 3:{
                delete(arr,&n);
                break;
            }
            case 4:{
                printArray(arr,&n);
                break;
            }
            case 5:{
                printf("EXIT");
                break;
            }
        }
    
    }while (ch!=5);
    
    return 0;
}