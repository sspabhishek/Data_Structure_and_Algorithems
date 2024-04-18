int Sum(int Arr[],int size);

main()
{
    int size,k;
    printf("Enter size of array ");
    scanf("%d",&size);
    int i,A[size];
    printf("Enter Elements of the Array ");
    for(i=0;i<size;i++)
        scanf("%d",&A[i]);
    k=Sum(A,size);
    printf("%d",k);
}

int Sum(int Arr[],int size)
{
    int i,sum=0;
    for(i=0;i<size;i++)
        sum=sum+Arr[i];
    return sum;
}
