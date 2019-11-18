#include <stdio.h>
#include <stdlib.h>
 struct node{
	int data;
	struct node * left,*right;
};
struct node* root=NULL,*parent,*s;
int i;
void insert()
{
  int x;
struct node *ptr;
  struct node *parent;
  printf("Enter the data :");
  scanf("%d",&x);
  struct node* new=(struct node *)malloc(sizeof(struct node));
  new->data=x;
  new->left =NULL;
  new->right=NULL;
  if(root ==NULL)
  {
  root =new;
  }
   else
   {
    struct node* ptr=root;
    int flag=0;
    while((ptr!=NULL)&&(flag==0))
   {
     if(x<ptr->data)
     {
      parent =ptr;
      ptr=ptr->left;
     } 
     else if(x>ptr->data)
     {
      parent =ptr;
      ptr=ptr->right;
     }
     else 
     flag=1;
   }
   if(flag==0)
   {
     if(x>parent->data)
       parent->right=new;
     else
      parent->left=new;
   }
   else
    printf("The value exist");
 
 }
}
void delete(int x)
{
struct node *ptr;
  if(root==NULL)
     printf("Empty Treee ");
  else
  {
    ptr=root;
    int flag=0;
    while((ptr!=NULL)&&(flag==0))
   {
     if(x>ptr->data)
     {
       parent=ptr;
       ptr=ptr->right;
     }
    else if(x<ptr->data)
    {
      parent=ptr;
      ptr=ptr->left;
    }
    else
    {
      flag=1;
    }
   }
  if(flag==0)
    printf("Value Not found");
  else if((ptr->left==NULL)&&(ptr->right==NULL))
  {
//aprintf("case 1");
    if(parent->left==ptr)
      parent->left=NULL;
    else
      parent->right=NULL;
    free(ptr);
  }
  else if((ptr->left!=NULL)&&(ptr->right!=NULL))
 {
   s=ptr->right;
//printf("case 3");
   while(s->left!=NULL)
    { 
      s=s->left;
     }
    i=s->data; 

   delete(s->data); 
   ptr->data=i;
 }
 else
  {
//printf("case 2");
    if(parent->left==ptr)
      {
        if(ptr->left==NULL)
           parent->left=ptr->right;
        else
           parent->left=ptr->left;
      } 
     else if(parent->right==ptr)
      {
        if(ptr->left==NULL)
           parent->right=ptr->right;
        else
           parent->right=ptr->left;
      }  
     free(ptr);   
  }
    
  }      
}
void preorder(struct node*p)
{
  if(p!=NULL)
   {
     printf("%d ",p->data);
     preorder(p->left);
     preorder(p->right);
   }
}
void inorder(struct node*p)
{
  if(p!=NULL)
   {
     inorder(p->left);
     printf("%d ",p->data);
     inorder(p->right);
   }
}
void postorder(struct node*p)
{
  if(p!=NULL)
   {
     postorder(p->left);
     postorder(p->right);
     printf("%d ",p->data);
   }
}
void search()
{ 
  int x;
struct node *ptr;
  ptr=root;
  int flag=0;
  printf("Enter the data :");
  scanf("%d",&x);
if(ptr==NULL)
   printf("Empty Tree ");
else
{
while((ptr!=NULL)&&(flag==0))
   {
     if(x<ptr->data)
     {
      ptr=ptr->left;
     } 
     else if(x>ptr->data)
     {
      ptr=ptr->right;
     }
     else 
      flag=1;
   }
  if(flag==1)
    printf("Element Found\n");
  else
    printf("Element Not Found\n");
 }
}

void main()
{
  int c,x;
  while(1){
     printf("\n\n1. Insert \n2. Delete \n3. Preorder traversal \n4. Inorder traversal \n5. Postorder traversal \n6. Search \n7. Exit \n\nEnter the choice: ");
     scanf("%d",&c);
     switch(c)
    {
      case 1 : insert();
               break;
      case 2 : 
               printf("Enter the data to be deleted : ");
               scanf("%d",&x);
               delete(x);
               break;
      case 3 : preorder(root);
               break;
      case  4: inorder(root);
               break;
      case 5 : postorder(root);
               break;
      case 6: search();
               break;
      case 7: exit(0);
      default : printf("Invalid choice \n");
    }
}
}

