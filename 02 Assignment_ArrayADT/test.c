#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i=0,j;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */

    for(j=num-1;j>=0;j--){
        arr[j]=arr[i];
        i++;
    }
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
