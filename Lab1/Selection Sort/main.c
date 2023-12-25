#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nArray:\n");
      for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    for(int i=0;i<n-1;i++){
            int min=INT_MAX;
            int minidx=-1;
        for(int j=i;j<n;j++){
           if(arr[j]<min){
            min=arr[j];
            minidx=j;
           }
        }
         int temp=arr[i];
         arr[i]=arr[minidx];
         arr[minidx]=temp;
    }
    printf("\nSorted Array:\n");
     for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}
