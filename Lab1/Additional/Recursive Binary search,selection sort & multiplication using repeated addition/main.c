#include <stdio.h>
#include <stdlib.h>

// Recursive Binary Search
int recursiveBinarySearch(int arr[],int left,int right,int target) {
    if(left<=right) {
        int mid=left+(right-left)/2;

        if (arr[mid]==target)
            return mid;
        else if (arr[mid]<target)
            return recursiveBinarySearch(arr,mid+1,right,target);
        else
            return recursiveBinarySearch(arr,left,mid-1,target);
    }
    return -1; // Element not found
}

// Recursive Selection Sort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recursiveSelectionSort(int arr[], int n, int index) {
    if (index >= n - 1)
        return;

    int minIndex = index;
    for (int i=index+1;i<n;i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    if (minIndex != index)
        swap(&arr[minIndex], &arr[index]);

    recursiveSelectionSort(arr, n, index + 1);
}

// Recursive Multiplication using Repeated Addition
int recursiveMultiply(int a, int b) {
    if (b == 0)
        return 0;
    return a + recursiveMultiply(a, b - 1);
}

int main() {
    int choice;

    do {
        printf("Choose an operation:\n");
        printf("1. Binary Search\n");
        printf("2. Selection Sort\n");
        printf("3. Multiply two numbers using repeated addition\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n, target;
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter array elements: ");
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                printf("Enter the element to search: ");
                scanf("%d", &target);
                recursiveSelectionSort(arr, n, 0); // Sort the array
                int index = recursiveBinarySearch(arr, 0, n - 1, target);
                if (index != -1)
                    printf("Element %d found at index %d\n", target, index);
                else
                    printf("Element %d not found\n", target);
                break;
            }
            case 2: {
                int n;
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter array elements: ");
                for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
                recursiveSelectionSort(arr, n, 0);
                printf("Sorted array: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 3: {
                int num1, num2;
                printf("Enter two numbers to multiply: ");
                scanf("%d %d", &num1, &num2);
                int result = recursiveMultiply(num1, num2);
                printf("%d * %d = %d\n", num1, num2, result);
                break;
            }
            case 0:
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
