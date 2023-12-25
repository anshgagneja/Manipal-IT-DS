#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

int areMirror(struct TreeNode* tree1, struct TreeNode* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }

    return (tree1->value == tree2->value &&
            areMirror(tree1->left, tree2->right) &&
            areMirror(tree1->right, tree2->left));
}

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode* tree1 = createNode(1);
    tree1->left = createNode(2);
    tree1->right = createNode(3);

    struct TreeNode* tree2 = createNode(1);
    tree2->left = createNode(3);
    tree2->right = createNode(2);

    if (areMirror(tree1, tree2)) {
        printf("The trees are mirror images.\n");
    } else {
        printf("The trees are not mirror images.\n");
    }

    return 0;
}
