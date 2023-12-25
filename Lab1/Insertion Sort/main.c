#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter array size:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("\nArray:\n");
     for(int i=0;i<n;i++){
       printf("%d\t",arr[i]);
    }
    //insertion sort
    for(int i=1;i<n;i++){
          for(int j=i;j>=1;j--){
                if(arr[j]<arr[j-1]){
             int temp=arr[j];
             arr[j]=arr[j-1];
             arr[j-1]=temp;
                }
        }
    }
    printf("\nSorted array:\n");
       for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
