#include <stdio.h>
#include <stdlib.h>

void Multiply(){
int m,n,p,q;
    printf("Enter the number of rows in matrix 1:");
    scanf("%d",&m);
    printf("Enter the number of columns in matrix 1:");
    scanf("%d",&n);
    printf("Enter the number of rows in matrix 2:");
    scanf("%d",&p);
    printf("Enter the number of columns in matrix 2:");
    scanf("%d",&q);
    int arr1[m][n];
    int arr2[p][q];
    int mul[m][q];
if(n!=p) {
    printf("The number of columns in Matrix-1 must be equal to the number of rows in Matrix-2\n");
}
else{
    printf("Enter the elements of matrix 1:\n");
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&arr1[i][j]);
    }
   }
 printf("Enter the elements of matrix 2:\n");
    for(int i=0;i<p;i++){
    for(int j=0;j<q;j++){
        scanf("%d",&arr2[i][j]);
    }
   }
       printf("Matrix 1:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            mul[i][j]=0;
            for(int k=0;k<n;k++){
                mul[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    printf("Multiplied matrix:\n");
   for(int i=0;i<m;i++){
    for(int j=0;j<q;j++){
        printf("%d\t",mul[i][j]);
    }
    printf("\n");
   }

}
return;
}
void Addition(){
    int x,y;
    printf("Enter the number of rows of the matrices:");
    scanf("%d",&x);
    printf("Enter the number of columns of the matrices:");
    scanf("%d",&y);
    int array1[x][y];
    int array2[x][y];
    int Add[x][y];
    printf("Enter the elements of matrix 1:\n");
    for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
        scanf("%d",&array1[i][j]);
    }
   }
    printf("Enter the elements of matrix 2:\n");
    for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
        scanf("%d",&array2[i][j]);
    }
   }
     printf("Matrix 1:\n");
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%d\t",array1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%d\t",array2[i][j]);
        }
        printf("\n");
    }
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
        Add[i][j]=array1[i][j]+array2[i][j];
    }
  }
   printf("Added matrix:\n");
   for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
        printf("%d\t",Add[i][j]);
    }
    printf("\n");
   }
  return;
}
void CheckMagicSquare(){
    int a;
    printf("Enter the size of the matrix:");
    scanf("%d",&a);
    int arr[a][a];
    printf("Enter the matrix elements:\n");
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            scanf("%d",&arr[i][j]);
        }
    }
      printf("Matrix :\n");
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    int sum=0; int sum1=0; int sum2=0; int flag;
    // for diagonal elements
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
                if(i==j)
            sum+=arr[i][j];
        }
    }
    //for row elements
     for (int i=0;i<a;i++) {
      sum1=0;
      for(int j=0;j<a;j++) {
         sum1=sum1+arr[i][j];
      }
      if(sum==sum1)
         flag = 1;
      else {
         flag=0;
         break;
      }
   }
   //For Column elements
   for(int i=0;i<a;i++) {
      sum2=0;
      for(int j=0;j<a;j++) {
         sum2=sum2+arr[j][i];
      }
      if (sum==sum2)
         flag=1;
      else {
         flag=0;
         break;
      }
   }

   if (flag==1)
      printf("\nMagic square\n");
   else
      printf("\nNot a Magic square\n");
      return;
}

int main(){
    int op;
    int x,y;
do{
    printf("Enter the operation you want to perform:\n 1:Matrix Multiplication\n 2:Matrix Addition\n 3:Check Magic Square\n 0:exit\n");
    scanf("%d",&op);
   switch(op){
   case 1:
    Multiply();
    break;
   case 2:
    Addition();
    break;
   case 3:
    CheckMagicSquare();
    break;
   case 0:
    break;
   default:
    printf("Choose valid operation(only 1,2,3)\n");
    break;
    }
 }
 while(op!=0);
return 0;
}
