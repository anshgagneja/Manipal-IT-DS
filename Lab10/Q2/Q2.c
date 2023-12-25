#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
struct node*create(){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("Enter left child of %d:",x);
    newnode->left=create();
    printf("Enter right child of %d:",x);
    newnode->right=create();
    return newnode;
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
    struct node*root;
    root=create();
    display(root,0);
return 0;
}