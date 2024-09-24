# include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
struct node * new_element(int element){
    struct node* temp = NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=element;
    temp->link=NULL;
    return temp;
}
struct node * traversal(struct node* head){
    struct node* current=head;
    while(current->link!=NULL){
        current=current->link;
    }
    return current;
}
struct node * add_at_pos(struct node *head,int pos){
    int element;
    printf("Enter the no to be inserted : ");
    scanf("%d",element);
    struct node* temp=new_element(element);
    struct node* rot=head;
    while(rot != NULL){
        if(rot->data==pos){
            break;
        }
        rot=rot->link;
    }
    if (rot == NULL){
        return head;
    }
    temp->link=rot->link;
    rot->link=temp;
    return head;
}
int main(){
    int length;
    printf("Enter the no of element : ");
    scanf("%d",&length);
    struct node *head=NULL,*new=NULL;
    for(int i = 0;i<length;i++){
        int element;
        printf("enter %d element : ",i+1);
        scanf("%d",&element);
        struct node* temp=new_element(element);
        if(head==NULL){
            head=temp;
        }
        else{
            struct node*new=traversal(head);
            new->link=temp;
        }
    }
    int pos;
    printf("Enter the position you want to enter:");
    scanf("%d",&pos);
    head=add_at_pos(head,pos);
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}
