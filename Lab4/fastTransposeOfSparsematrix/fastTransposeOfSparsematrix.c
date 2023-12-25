#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

int main() {
    int rows, cols, numElements;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);

    struct Element sparseMatrix[numElements];
    struct Element transposedMatrix[numElements];

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].col, &sparseMatrix[i].value);
    }

    // Calculate the number of non-zero elements in each column of the original matrix
    int colCount[cols];
    for (int i = 0; i < cols; i++) {
        colCount[i] = 0;
    }
    for (int i = 0; i < numElements; i++) {
        colCount[sparseMatrix[i].col]++;
    }

    // Calculate the starting index for each column in the transposed matrix
    int colStartIndex[cols];
    colStartIndex[0] = 0;
    for (int i = 1; i < cols; i++) {
        colStartIndex[i] = colStartIndex[i - 1] + colCount[i - 1];
    }

    // Perform the fast transpose
    for (int i = 0; i < numElements; i++) {
        int col = sparseMatrix[i].col;
        int index = colStartIndex[col];

        transposedMatrix[index].row = sparseMatrix[i].col;
        transposedMatrix[index].col = sparseMatrix[i].row;
        transposedMatrix[index].value = sparseMatrix[i].value;

        colStartIndex[col]++;
    }

    // Display the transposed matrix
    printf("Fast Transposed Matrix:\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d %d %d\n", transposedMatrix[i].row, transposedMatrix[i].col, transposedMatrix[i].value);
    }

    return 0;
}
