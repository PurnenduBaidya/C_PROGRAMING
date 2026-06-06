#include<stdio.h>
int linearsearch(int arr[],int *n,int *num){
    int a=0,idx;
    for(int i=0;i<*n;i++){
        if(arr[i]==*num){
            a=1;
            idx=i;
            break;
        }
    }
    if(a==1)
    return idx;
    else printf("The number is not found");
}
int binarysearch(int arr[],int *n,int *num){
    for(int i=0;i<*n;i++){
        for(int j=0;j<*n;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int low=0; int high=*n-1; int mid;
    while(low<=high){
        mid=(high+low)/2;
        if(arr[mid]==*num){
            return mid;
        }
        if(arr[mid]<*num){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
void display(int arr[],int *n){
    for(int i=0;i<*n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n,num;
    printf("enter size :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter %d element :",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter number to search :");
    scanf("%d",&num);
    int ch;
    do{
        printf("\n1.linear Search\n2.binary search\n3.display arrray\n4.EXIT");
        printf("\nEnter choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            int a=linearsearch(arr,&n,&num);
            printf("the number is found at index %d",a);
        }
            break;
        case 2:{
            int b=binarysearch(arr,&n,&num);
            printf("the number is found at index %d",b);
            break;
        }
        case 3:{
            display(arr,&n);
            break;
        }
        case 4:{
            printf("Exit");
            break;
        }
        }
    }while(ch!=4);
}