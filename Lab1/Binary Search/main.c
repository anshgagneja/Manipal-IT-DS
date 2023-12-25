#include <stdio.h>

int main(){
  int low,high,mid,n,key,arr[100];
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter %d integers:\n",n);
     for(int i=0;i<n;i++) {
    scanf("%d",&arr[i]);
     }
    printf("Enter value to find:");
    scanf("%d",&key);
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high){
    if(arr[mid]<key)
    low=mid+1;
    else if(arr[mid]==key) {
    printf("%d found at index %d\n",key,mid);
    break;
   }
   else
   high=mid-1;
   mid=(low+high)/2;

    }
   if(low>high)
   printf("Not found! %d is not present in the array\n",key);

    return 0;
}
