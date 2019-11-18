#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
struct node* root=NULL,*parent,*s;
int i;

void search(int x)
{
    struct node *ptr;
    if(root==NULL)
            printf("Empty tree");
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
                    printf("value not found");
	    else
		    printf("Element found");
    }
}

void insert()
{
    int x;
    struct node *ptr;
    struct node *parent;
    printf("enter the data : ");
    scanf("%d",&x);
    struct node* new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->left=NULL;
    new->right=NULL;
    if(root==NULL)
    {
	    root=new;
    }
    else
    {
	    struct node* ptr=root;
	    int flag=0;
	    while((ptr!=NULL)&&(flag==0))
	    {
		    if(x<ptr->data)
		    {
			    parent=ptr;
			    ptr=ptr->left;
		    }
		    else if(x>ptr->data)
			    {
				    parent=ptr;
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
		 printf("value exists ");
    }
}
void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d  ",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(struct node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d  ",p->data);
	}
}
void inorder(struct node*p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d  ",p->data);
		inorder(p->right);
	}
}

void delete(int x)
{
    struct node *ptr;
    if(root==NULL)
	    printf("Empty tree");
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
		    printf("value not found");
	    else if((ptr->left==NULL)&&(ptr->right==NULL))
	    {
		    if(parent->left==ptr)
			    parent->left==NULL;
		    else
			    parent->right==NULL;
		    free(ptr);
	    }
	    else if((ptr->left!=NULL)&&(ptr->right!=NULL))
	    {
		    s=ptr->right;
		    while(s->left!=NULL)
		    {
			    s=s->left;
		    }
		    i=s->data;
		    delete(i);
		    ptr->data=i;
	    }
	    else
	    {
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
    

int main()
{
	int c,x1,x2;
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Search\n4.preorder traversal\n5.postorder traversal\n6.inorder traversal\n7.Exit\nEnter your choice : ");
                scanf("%d",&c);
		switch(c)
		{
			case 1:insert();
			       break;


			case 2:printf("Enter the element to be deleted : ");
			       scanf("%d",&x1);
			       delete(x1);
			       break;
			case 3:printf("enter the value to be searched : ");
                               scanf("%d",&x2);
			       search(x2);
			       break;
			case 4:preorder(root);
			       break;
			case 5:postorder(root);
			       break;
			case 6:inorder(root);
			       break;
			case 7:exit(0);
			default:printf("wrong choice :(");
		}
	}
}	

   


