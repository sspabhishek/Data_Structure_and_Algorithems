float Aveg(int A[],int size);
main()
{
    int size,i;
    float Average;
    printf("Enter Size of Array ");
    scanf("%d",&size);
    int A[size];
    printf("Enter Array Elements ");
    for(i=0;i<size;i++)
        scanf("%d",&A[i]);
    Average=Aveg(A,size);
    printf("%f",Average);
}

float Aveg(int Arr[],int size)
{
    int i;
    float sum=0;
    for(i=0;i<size;i++)
    {
        sum=sum+Arr[i];
    }
    return sum/size;
}
