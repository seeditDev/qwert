#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left,*right;
};
struct queue 
{
  struct node* tree_node_address ;
 struct queue *next;
};
struct queue* qhead=NULL;
struct queue*qlast=NULL;
struct node* root=NULL;
struct node* createnode(int val)
{
  struct node* newnode=(struct node*) malloc(sizeof(struct node));
  newnode->data=val;
  newnode->left=NULL;
  newnode->right=NULL;
  
  return newnode;
}
void enqueue(struct node*root)
{
    struct queue*qnewnode=(struct queue*)malloc(sizeof(struct queue));
    qnewnode->tree_node_address=root;
    qnewnode->next=NULL;
    
    if(qhead==NULL)
    {
        qhead=qnewnode;
        qlast=qnewnode;
    }
    else
    {
        qlast->next=qnewnode;
        qlast=qnewnode;
    }
}
struct node* dequeue()
{
    struct node*temp=qhead->tree_node_address;
    if(qhead==qlast) 
        qhead=qlast=NULL;
    else
      qhead=qhead->next;
    
    return temp;
}
void insert(int val)
{
    struct node* newnode=createnode(val);
    
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    else
    {
        enqueue(root);
        
        while(!(qhead==NULL && qlast==NULL))
        {
            struct node*temp=dequeue();
            if(temp->left==NULL)
            {
                temp->left=newnode;
                break;
            }
            if(temp->right==NULL)
            {
                temp->right=newnode;
                break;
            }
            enqueue(temp->left);
            enqueue(temp->right);
        }
        qhead=NULL;
        qlast=NULL;
    }
}
void inorder(struct node* root)
{
    if(root==NULL) return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void display()
{
    inorder(root);
}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
display();
}
