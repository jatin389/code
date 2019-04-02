#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
int val;
struct node *left,*right;
}tree;

tree *root=NULL;
//-----------------------------------------

void insert(int x)
{
	tree* tmp=(tree *)malloc(sizeof(tree));
	tmp->val=x;
	tmp->left=NULL;
	tmp->right=NULL;
	
	if(root==NULL)
		root=tmp;
	else
	{
		tree *q=root;
		while(1)
		{
			if(x<q->val)
			{
				if(q->left==NULL)
					{
					q->left=tmp;
					break;
					}
				else
					q=q->left;
			}
			
			else
			{
				if(q->right==NULL)
					{
					q->right=tmp;
					break;
					}
				else
					q=q->right;
			}
		}
	}
}


//-----------------------------------------


void inorder(tree *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d  ",root->val);
		inorder(root->right);
	}
}


//-----------------------------------------
int main()
{

printf("enter no. of elements");
int n;
scanf("%d",&n);

int x;
for(int i=0;i<n;i++)
{
scanf("%d",&x);
insert(x);
}

inorder(root);

free(root);
inorder(root);
return 0;
}
