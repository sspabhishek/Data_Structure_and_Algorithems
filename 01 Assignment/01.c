#include<stdio.h>

int maxValue(int A[],int size)
{
    int i,t=A[0];
    for(i=1;i<size;i++)
    {
        if(t<A[i])
            t=A[i];
    }
    return t;
}
void main()
{
    int a,i,k;
    printf("Enter Size of array\n");
    scanf("%d",&a);
    int Arr[a];
    printf("Enter Array value\n");
    for(i=0;i<a;i++)
        scanf("%d",&Arr[i]);
    k=maxValue(Arr
               ,a);
    printf("\nMax Value is %d",k);
}
