// 1. Write a program to insert an element into a binary search tree.
// 2. Write a program to delete an element from a binary search tree.
// 3. Write a program to search for a given element in a binary search tree.
// 4. Write a program to traverse a binary search tree and print it.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createNode(int x){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=0;
    newnode->right=0;
    newnode->data=x;
    return newnode;
}
struct node*root=0;
void insert(int x){
    if(root==0){
        root=createNode(x);
    }
    else{
        struct node*current=root;
        struct node*prev=0;
        while(current!=0){
            prev=current;
            if(current->data==x){
                return;
            }
            if(x>current->data){
                current=current->right;
            }
            else{
                current=current->left;
            }
        }
        if(x>prev->data){
            prev->right=createNode(x);
        }
        else{
            prev->left=createNode(x);
        }
    }
}
struct node*inorderPredecessor(struct node*current){
    current=current->left;
    while(current->right!=0){
        current=current->right;
    }
    return current;
}
struct node* delete(struct node*current,int x){
    if(current==0){
        return 0;
    }
    if(current->left==0&&current->right==0){ //leaf
        free(current);
        return 0;
    }
    //search
    if(x>current->data){
        current->right=delete(current->right,x);
    }
    else if(x<current->data){
        current->left=delete(current->left,x);
    }
    else{
        //found
        struct node*ipre=inorderPredecessor(current);
        current->data=ipre->data;
        current->left=delete(current->left,ipre->data);
    }
}

void createBST(){
    int x;
    printf("Enter root(-1 for no node):");
    scanf("%d",&x);
    while(x!=-1){
        if(root==0){
            root=createNode(x);
        }
        else{
            insert(x);
        }
        printf("Enter data(-1 for no node):");
        scanf("%d",&x);
    }
}

struct node* iterSearch(int x){
    if(root==0){
        return 0;
    }
    if(root->data==x){
        return root;
    }
    struct node*current=root;
    while(current!=0){
        if(x==current->data){
            return current;
        }
        if(x>current->data){
            current=current->right;
        }
        else{
            current=current->left;
        }
    }
}
struct node*search(struct node*current,int x){
    if(root==0){
        return 0;
    }
    if(x==current->data){
        return current;
    }
    if(x<current->data){
        return search(current->left,x);
    }
    if(x>current->data){
        return search(current->right,x);
    }

}
void levelOrder(){
    if(root==0){
        return;
    }
    struct node**queue=(struct node**)malloc(sizeof(struct node*)*100);
    int front=0; int rear=0;
    queue[rear++]=root;
    while(rear>front){
        struct node*current=queue[front++];
        printf("%d\t",current->data);
        if(current->left!=0){
            queue[rear++]=current->left;
        }
        if(current->right!=0){
            queue[rear++]=current->right;
        }
    }
    printf("\n");
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
int main(){
    createBST();
    display(root,0);
    int y;
    printf("Enter element to be inserted in BST:");
    scanf("%d",&y);
    insert(y);
    display(root,0);
    int z;
    printf("Enter element to be deleted from BST:");
    scanf("%d",&z);
    delete(root,z);
    display(root,0);
    printf("\nLEVEL ORDER:\n");
    levelOrder();
    int x;
    printf("\nEnter an element to search in BST:");
    scanf("%d",&x);
    if(iterSearch(x)){
        printf("FOUND!!!!\n");
    }
    else{
        printf("NOT FOUND!!!\n");
    }
    int ele;
    printf("\nEnter an element to search in BST:");
    scanf("%d",&ele);
    if(search(root,ele)){
        printf("FOUND!!!!\n");
    }
    else{
        printf("NOT FOUND!!!\n");
    }


return 0;
}