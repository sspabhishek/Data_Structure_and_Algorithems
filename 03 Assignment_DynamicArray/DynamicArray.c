#include<stdio.h>
#include<conio.h>
struct DynArray
{
    int capacity;
    int lastindex;
    int *ptr;
};

struct DynArray* CreateArray(int cap)
{
    struct DynArray *arr =NULL;
    arr=(struct DynArray*)malloc(sizeof(struct DynArray));
    arr->capacity=cap;
    arr->lastindex=-1;
    arr->ptr=(int*)malloc(sizeof(int)*cap);
    return arr;
}
void DoubleArray(struct DynArray *arr)
{
    int *temp;
    temp=(int*)malloc(arr->capacity*2);
    for(int i=0;i<=arr->lastindex;i++)
        temp[i]=arr->ptr[i];
    arr->capacity*=2;
    free(arr->ptr);
    arr->ptr=temp;
}
void HalfArray(struct DynArray *arr)
{
    int *temp;
    temp=(int*)malloc(arr->capacity/2);
    for(int i=0;i<=arr->lastindex;i++)
        temp[i]=arr->ptr[i];
    arr->capacity/=2;
    free(arr->ptr);
    arr->ptr=temp;

}
void Append(struct DynArray *arr,int data)
{
    if(arr->lastindex+1==arr->capacity)
        DoubleArray(arr);
    arr->lastindex+=1;
    arr->ptr[arr->lastindex]=data;
}
void Insert(struct DynArray *arr,int index,int data)
{
    if(index<0 || index>arr->lastindex+1)
        printf("InsertionError : Invalid Index");
    else{
        if(arr->lastindex+1==arr->capacity)
            DoubleArray(arr);
        for(int i=arr->lastindex;i>=index;i--){
            arr->ptr[i+1]=arr->ptr[i];
        }
        arr->ptr[index]=data;
        arr->lastindex+=1;
    }
}
void Count(struct DynArray *arr)
{
    printf("\n%d",arr->lastindex+1);
}
void Del(struct DynArray *arr,int index)
{
    for(int i=index;i<arr->lastindex;i++){
        arr->ptr[i]=arr->ptr[i+1];
    }
    arr->lastindex-=1;
    if((arr->lastindex+1)==(arr->capacity/2))
        HalfArray(arr);
}
int Search(struct DynArray *arr,int data)
{
    for(int i=0;i<=arr->lastindex;i++){
        if(arr->ptr[i]==data)
            return i;
    }
    return -1;
}
void View(struct DynArray *arr)
{
    for(int i=0;i<=arr->lastindex;i++)
        printf("%d ",arr->ptr[i]);
}
void main()
{
    struct DynArray *arr1;
    int cap,i,d,t;
    printf("Enter Initial Size of Array : ");
    scanf("%d",&cap);
    arr1=CreateArray(cap);
    while(1){
        system("cls");
        printf("\nCapacity : %d",arr1->capacity);
        printf("\nArray  Index :  ");
        for(int k=0;k<arr1->capacity;k++)
            printf(" %d ",k);
        printf("\nArray Element : ");
        View(arr1);
        printf("\n<------------------------------------------------------------------------------------------->");
        printf("\n1.Append");
        printf("\n2.Insert");
        printf("\n3.Delete Index");
        printf("\n4.Count");
        printf("\n5.Delete Array");
        printf("\n6.Exit");
        printf("\n<------------------------------------------------------------------------------------------->\n");
        printf("\nEnter Key Value of operations : ");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("\nEnter the data you want to append : ");
            scanf("%d",&d);
            Append(arr1,d);
            break;
        case 2:
            printf("\nEnter the index and data you want to Insert");
            printf("\nIndex : ");
            scanf("%d",&d);
            printf("\nData : ");
            scanf("%d",&t);
            Insert(arr1,d,t);
            break;
        case 3:
            printf("\nEnter the index you want to delete : ");
            scanf("%d",&t);
            Del(arr1,t);
            break;
        case 4:
            Count(arr1);
            break;
        case 5:
            free(arr1);
        case 6:
            exit(0);

        default :
            printf("\nWrong key value : retry");
        }
        getch();

    }
}
