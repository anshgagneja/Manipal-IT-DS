#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1,a2,b1,b2;
    printf("Rows: ");
    scanf("%d",&a1);
    printf("Columns: ");
    scanf("%d",&a2);
    int A[a1][a2],B[a1][a2],i,j;
    printf("\nMATRIX A\n");
    for(i=0;i<a1;i++){
        for(j=0;j<a2;j++){
            printf("Enter element: ");
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nMATRIX B\n");
    for(i=0;i<a1;i++){
        for(j=0;j<a2;j++){
            printf("Enter element: ");
            scanf("%d",&B[i][j]);
        }
    }
    //filling matrix C
    int C[a1][a2];
    for(i=0;i<a1;i++){
        for(j=0;j<a2;j++){
            C[i][j]=(A[i][j]>B[i][j])?(A[i][j]):(B[i][j]);
        }
    }
    //display
    for(i=0;i<a1;i++){
        for(j=0;j<a2;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
