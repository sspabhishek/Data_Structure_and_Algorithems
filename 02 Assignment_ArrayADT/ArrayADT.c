#include<stdio.h>
struct ArrayADT
{
    int capacity;
    int lastIndex;
    int *ptr;
};
struct ArrayADT* createArray(int cap)
{
    struct ArrayADT *arr=NULL;
    arr=(struct ArrayADT*)malloc(sizeof(struct ArrayADT));
    arr->capacity=cap;
    arr->lastIndex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*cap);
    return arr;
}
void append(struct ArrayADT *arr,int data){
    if(arr->lastIndex+1 == arr->capacity){
        printf("Overflow");
    }
    else{
        arr->lastIndex+=1;
        arr->ptr[arr->lastIndex]=data;
    }
}
void insert(struct ArrayADT *arr,int data,int index){
     if(index<0 || index>arr->lastIndex+1){
        printf("InsertionError : Invalid Index\n");
     }
     else if(arr->lastIndex+1==arr->capacity){
        printf("InsertionError: Overflow\n");
     }
     else{
        for(int i=arr->lastIndex;i>=index;i--){
            arr->ptr[i+1]=arr->ptr[i];
        }
        arr->ptr[index]=data;
        arr->lastIndex+=1;
     }
}
int count(struct ArrayADT *arr)
{
    return arr->lastIndex+1;
}
void del(struct ArrayADT *arr, int index)
{
    if(index<0 || index>arr->lastIndex){
        printf("DeletionError : InvalidIndex or Underflow");
    }
    else{
            for(int i=index;i<arr->lastIndex;i++){
                arr->ptr[i]=arr->ptr[i+1];
            }
            arr->lastIndex-=1;
    }
}
void view(struct ArrayADT *arr)
{
    for(int i=0;i<=arr->lastIndex;i++){
        printf("%d ",arr->ptr[i]);
    }
}
int search(struct ArrayADT *arr, int data)
{
    for(int i=0;i<=arr->lastIndex;i++)
        if(arr->ptr[i]==data)
            return i;
        return -1;
}
void main(){
    struct ArrayADT *arr;
    arr=createArray(4);
    append(arr,20);
    append(arr,30);
    //insert(arr,18,3);
    insert(arr,23,1);
    int k=count(arr);
    printf("%d\n",k);
    //insert(arr,56,4);
    view(arr);
    del(arr,1);
    printf("\n");
    view(arr);
    int s=search(arr,30);
    printf("\n%d",s);
    //printf("%d",arr->ptr[arr->lastIndex]);
    getch();
}
