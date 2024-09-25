# include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
struct node * new_element(int element){  // adding new element
    struct node* temp = NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=element;
    temp->link=NULL;
    return temp;
}
struct node * traversal(struct node* head){    // Traversing
    struct node* current=head;
    while(current->link!=NULL){
        current=current->link;
    }
    return current;
}
struct node * count(struct node* head){    // count
    int cnt=0;
    struct node* current=head;
    while(current->link!=NULL){
        cnt++;
        current=current->link;
    }
    return (cnt+1);
}
struct node * add_at_pos(struct node *head,int pos){//insertion at postion
    int element;
    printf("Enter the no to be inserted : ");
    scanf("%d",&element);
    struct node* nxt=head;
    struct node* temp=new_element(element);
    struct node* new=traversal(head);
    struct node* rot=head;
    if (pos==1){    //insertion at beginning
        temp->link=head;
        head=temp;
        return head;
    }
    else if(pos>count(head)){
        new->link=temp;
        temp->link=NULL;
        return head;
    }
    else{    //insertion at ending
        int position = 1;
        while(position<pos-1){
            nxt=nxt->link;
            position++;
        }
        temp->link=nxt->link;
        nxt->link=temp;
        return head;
    }
}
struct node * add_at_beg(struct node* head){    //insertion at beginning
    int element;
    printf("Enter the no to be inserted : ");
    scanf("%d",&element);
    struct node* temp=new_element(element);
    temp->link=head;
    head=temp;
    return head;
}
struct node * add_at_end(struct node * head){    //insertion at ending
    int element;
    printf("Enter the no to be inserted : ");
    scanf("%d",&element);
    struct node* temp=new_element(element);
    struct node* new=traversal(head);
    new->link=temp;

};
struct node* print_linkedlist(struct node* head){    //printing the linkedlist

    struct node* current=head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
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
    /*//insertion of element
    printf("**Insertion of element**\n");
    printf("Enter the position you want to enter : ");
    scanf("%d",&pos);
    head=add_at_pos(head,pos);
    //insertion at beginning
    printf("**Insertion at beginning**\n");
    head=add_at_beg(head);
    //insertion at end;
    printf("**Insertion at end**\n");
    add_at_end(head);
    //count
    printf("Count of element = %d \n",count(head));
    //print of linked list*/
    //deletion of element
    print_linkedlist(head);
}
