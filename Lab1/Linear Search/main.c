#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[],int n,int x) {
  for (int i=0;i<n;i++){
    if(arr[i]==x){
        return i;
    }
  }
  return -1;
}

int main() {
  int arr[]={2,3,0,1,9};
  int x;
  printf("Enter element to be searched:");
  scanf("%d",&x);
  int n=sizeof(arr)/sizeof(int);
  int result=linearSearch(arr,n,x);
  if(result==-1){
    printf("Element not found!");
  }
  else {
    printf("Element found at index:%d",result);
  }
  return 0;
}



