#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 25
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*stack[MAX];
int top=-1;
struct node*create(){
    struct node*root=0;
    int x;
    int choice;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    while(x!=-1){
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->left=0;
        newnode->right=0;
        if(root==0){
            root=newnode;
        }
        else{
            struct node*current=root;
            while(1){
                printf("Press 0 for left child of %d & 1 for right child of %d:",current->data,current->data);
                scanf("%d",&choice);
                if(choice==0){
                    if(current->left==0){
                        current->left=newnode;
                        break;
                    }
                    else{
                        current=current->left;
                    }
                }
                if(choice==1){
                    if(current->right==0){
                        current->right=newnode;
                        break;
                    }
                    else{
                        current=current->right;
                    }
                }
            }
        }
        printf("Enter data (-1 for no node):");
        scanf("%d",&x);
    }
    return root;
}
void display(struct node*root,int level){
    if(root==0){
        return;
    }
    display(root->right,level+1);
    for(int i=0;i<level;i++){
        printf("    ");
    }
    printf("%d\n",root->data);
    display(root->left,level+1);
}
void push(struct node*x){
    if(top==MAX-1){
        printf("Stack underflow!\n");
        return;
    }
    stack[++top]=x;
}
struct node*pop(){
    if(top==-1){
        printf("Stack underflow!\n");
        return NULL;
    }
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}
void inorder(struct node*root){
    struct node*current=root;
    while(current||!isEmpty()){
        while(current){
            push(current);
            current=current->left;
        }
        current=pop();
        printf("%d\t",current->data);
        current=current->right;
    }
    printf("\n");
}
void preorder(struct node*root){
    struct node*current=root;
    push(current);
    while(!isEmpty()){
        current=pop();
        printf("%d\t",current->data);
        if(current->right){
            push(current->right);
        }
        if(current->left){
            push(current->left);
        }
    }
    printf("\n");
}
void postorder(struct node*root){
    if(root==0){
        return;
    }
    struct node*current=root;
    struct node*lastvisited=0;
    while(current||!isEmpty()){
        while(current){
            push(current);
            current=current->left;
        }
        struct node*peek=stack[top];
        if(peek->right&&peek->right!=lastvisited){
            current=peek->right;
        }
        else{
            printf("%d\t",peek->data);
            lastvisited=pop();
        }
    }
    printf("\n");
}
bool searchParent(struct node* root, int x) {
    if ((root->left && root->left->data == x) || (root->right && root->right->data == x)) {
        printf("Parent: %d\n", root->data);
        return true;
    }

    bool leftResult = searchParent(root->left, x);
    bool rightResult = searchParent(root->right, x);

    return leftResult || rightResult;
}
void parent(struct node* root, int elem) {
    bool b=searchParent(root,elem);
    if (root->data == elem) {
        printf("Root has no parent\n");
        return;
    } 
    else {
        if (!b)
            printf("Element does not exist in the tree\n");
    }
}
int counter(struct node* root) {
    if (root == NULL)
        return 0;
    int lDepth = counter(root->left);
    int rDepth = counter(root->right);

    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}

void level(struct node* root) {
    int v = counter(root);
    printf("Total Depth is: %d\n", v);
}

bool searchAncestor(const struct node* root, int elem) {
    if (root == NULL)
        return false;
    else if (root->data == elem)
        return true;
    else if (searchAncestor(root->left, elem) || searchAncestor(root->right, elem)) {
        printf("%d ", root->data);
        return true;
    }
    return false;
}

void ancestors(const struct node* root, int elem) {
    if (root->data == elem)
        printf("Root element has no ancestor\n");
    else {
        if (!searchAncestor(root, elem))
            printf("Element does not exist in the tree\n");
    }
    printf("\n");
}

int leafcount(struct node* root) {
    if (root == NULL)
        return 0;
    else if (!root->left && !root->right)
        return 1;
    else
        return leafcount(root->left) + leafcount(root->right);
}

void leafs(struct node* root) {
    printf("Leafs present: %d\n", leafcount(root));
}
int main(){
    struct node* root = NULL;
    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Create Tree\n");
        printf("2. Display Tree\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Find Parent\n");
        printf("7. Calculate Depth\n");
        printf("8. Find Ancestors\n");
        printf("9. Count Leafs\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = create();
                break;
            case 2:
                if (root) {
                    printf("TREE:\n\n");
                    display(root, 0);
                } else {
                    printf("Tree is not created yet!\n");
                }
                break;
            case 3:
                if (root) {
                    printf("INORDER:\n");
                    inorder(root);
                } else {
                    printf("Tree is not created yet!\n");
                }
                break;
            case 4:
                if (root) {
                    printf("PREORDER:\n");
                    preorder(root);
                } else {
                    printf("Tree is not created yet!\n");
                }
                break;
            case 5:
                if (root) {
                    printf("POSTORDER:\n");
                    postorder(root);
                } else {
                    printf("Tree is not created yet!\n");
                }
                break;
            case 6:
                if (root) {
                    int x;
                    printf("Enter the element in the tree whose parent you want to find: ");
                    scanf("%d", &x);
                    parent(root, x);
                    break;
                } else {
                    printf("Tree is not created yet!\n");
                    break;
                }
            case 7:
                if (root) {
                    level(root);
                } else {
                    printf("Tree is not created yet!\n");
                }
                break;
            case 8:
                if (root) {
                    int x;
                    printf("Enter the element in the tree whose ancestors you want to find: ");
                    scanf("%d", &x);
                    ancestors(root, x);
                } else {
                    printf("Tree is not created yet!\n");
                }
                break;
            case 9:
                if (root) {
                    printf("Leafs present: %d\n", leafcount(root));
                } else {
                    printf("Tree is not created yet!\n");
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

return 0;
}
