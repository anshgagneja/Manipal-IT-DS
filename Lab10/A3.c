#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* children[10];
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    for (int i = 0; i < 10; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

TreeNode* copyTree(TreeNode* original) {
    if (original == NULL) {
        return NULL;
    }

    TreeNode* copied = createNode(original->value);

    for (int i = 0; original->children[i] != NULL && i < 10; ++i) {
        copied->children[i] = copyTree(original->children[i]);
    }

    return copied;
}

void printTree(TreeNode* node, int depth) {
    if (node != NULL) {
        for (int i = 0; i < depth; ++i) {
            printf("  ");
        }
        printf("%d\n", node->value);

        for (int i = 0; node->children[i] != NULL && i < 10; ++i) {
            printTree(node->children[i], depth + 1);
        }
    }
}

int main() {
    TreeNode* originalTree = createNode(1);
    originalTree->children[0] = createNode(2);
    originalTree->children[1] = createNode(3);
    originalTree->children[0]->children[0] = createNode(4);
    originalTree->children[0]->children[1] = createNode(5);

    TreeNode* copiedTree = copyTree(originalTree);

    printf("Original Tree:\n");
    printTree(originalTree, 0);

    printf("\nCopied Tree:\n");
    printTree(copiedTree, 0);

    return 0;
}
