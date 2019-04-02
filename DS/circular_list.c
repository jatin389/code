#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
int val;
struct node *nxt;
}list;

list *start=NULL,*last=NULL;
//---------------------------------------------------

void insert(int x)
{
list *tmp=(list *)malloc(sizeof(list));
tmp->nxt=NULL;
tmp->val=x;

if(start==NULL)
{
	start=last=tmp;
	last->nxt=start;
}

else
{
	last->nxt=tmp;
	last=tmp;
	last->nxt=start;
}
}
//---------------------------------------------------
void display(list *root,int n)
{
list *q=root;

for(int i=0;i<n;i++)
{
	printf("%d -> ",q->val);
	q=q->nxt;
}
}

//---------------------------------------------------

int check_circular(list *root)
{
list *q=root,*q1=root;

while(q!=NULL)
{
q=q->nxt;
q1=q1->nxt->nxt;
if(q1==q)
return 1;
}

return 0;
}
//---------------------------------------------------
int main()
{
int n;

printf("enter no. of elements");
scanf("%d",&n);

int x;
printf("enter elements");
for(int i=0;i<n;i++)
{
	scanf("%d",&x);
	insert(x);
}


display(start,n);

int c=check_circular(start);
if(c)
printf("yes cycles exists");
else
printf("no");
return 0;
}
