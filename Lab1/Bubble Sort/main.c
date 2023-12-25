#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    //bubble sort
    for(int i=0;i<n-1;i++){
      bool flag=true;   // flag used for optimization
        for(int j=0;j<n-i-1;j++){ // n-i-1 used for optimizing
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=false;
            }
        }
        if(flag==true){
            break;
        }
    }
    printf("\nArray after sorting:\n");
      for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
