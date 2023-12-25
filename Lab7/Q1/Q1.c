#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* createList(){
    struct node*head,*temp,*newnode;
    head=0;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to keep inserting elements in the list and 0 to exit!\n");
        printf("Enter choice:");
        scanf("%d",&choice);
    }
    return head;
}
void insertBeforeAnotherEle(struct node**head){
    int target;
    printf("\nEnter the element before which you want to insert an element:");
    scanf("%d",&target);
    struct node*prev,*temp;
    temp=*head;
    while(temp!=0&&temp->data!=target){
        prev=temp;
        temp=temp->next;
    }
    if(temp!=0){
        struct node*newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element to be inserted before %d:",target);
        scanf("%d",&newnode->data);
        if(prev!=0){
            newnode->next=temp;
            prev->next=newnode;
        }
        else {
            newnode->next=temp;
            *head=newnode;
        }
    }
    else {
        printf("%d not found in the list");
    }
}
void insertAfterAnotherEle(struct node**head){
    int target;
    printf("\nEnter the element after which you want to insert another element:");
    scanf("%d",&target);
    struct node*temp;
    temp=*head;
    while(temp!=0&&temp->data!=target){
        temp=temp->next;
    }
    if(temp!=0){
        struct node*newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter element to insert after %d:",target);
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else {
        printf("%d not found in the list\n",target);
    }
}
void delEle(struct node**head){
    int ele;
    printf("\nEnter the element to be deleted:");
    scanf("%d",&ele);
    struct node*temp,*prev;
    temp=*head;
    while(temp!=0&&temp->data!=ele){
        prev=temp;
        temp=temp->next;
    }
    if(temp!=0){
        prev->next=temp->next;
        free(temp);
    }
    else {
        printf("%d not found in the list!\n",ele);
    }
}
void traverse(struct node*head){
    if(head==0){
        printf("List is empty!\n");
    }
    else {
    struct node*temp;
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    }
    printf("\n");
}
void reverse(struct node**head){
    struct node*currentnode,*prevnode,*nextnode;
    prevnode=0;
    currentnode=nextnode=*head;
    while(nextnode!=0){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    *head=prevnode;
}
void sort(struct node** head) {
   struct node*i,*j;
   for(i=*head;i->next!=0;i=i->next){
    for(j=i->next;j!=0;j=j->next){
        if(i->data>j->data){
            int temp=i->data;
            i->data=j->data;
            j->data=temp;
        }
    }
   }
}
void delAlternateNode(struct node**head){
    struct node*temp,*prev;
    temp=*head;
    prev=0;
    int count=1;
    while(temp!=0){
        if(count%2==1){
            prev=temp;
            temp=temp->next;
        }
        else {
            prev->next=temp->next;
            free(temp);
            temp=prev->next;
        }
        count++;
    }
}
void insertInSorted(struct node**head){
    struct node*temp,*prev,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    temp=*head;
    prev=0;
    while(temp!=0&&(temp->data)<(newnode->data)){
        prev=temp;
        temp=temp->next;
    }
    if(prev==0){
        newnode->next=*head;
        *head=newnode;
    }
    else {
        newnode->next=temp;
        prev->next=newnode;
    }

}
int main() {
    struct node* head = 0;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert Before Another Element\n");
        printf("3. Insert After Another Element\n");
        printf("4. Delete Element\n");
        printf("5. Sort List\n");
        printf("6. Insert in Sorted List\n");
        printf("7. Reverse List\n");
        printf("8. Delete Alternate Nodes\n");
        printf("9. Traverse List\n"); 
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                insertBeforeAnotherEle(&head);
                break;
            case 3:
                insertAfterAnotherEle(&head);
                break;
            case 4:
                delEle(&head);
                break;
            case 5:
                sort(&head);
                printf("After Sorting:\n");
                traverse(head);
                break;
            case 6:
                insertInSorted(&head);
                printf("After Inserting element into Sorted List:\n");
                traverse(head);
                break;
            case 7:
                reverse(&head);
                printf("After Reversal:\n");
                traverse(head);
                break;
            case 8:
                delAlternateNode(&head);
                printf("After Deleting Alternate Nodes:\n");
                traverse(head);
                break;
            case 9:
                printf("List Contents:\n");
                traverse(head);
                break;
            case 0:
                return 0; 
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
