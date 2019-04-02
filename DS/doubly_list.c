#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
struct node *pre,*nxt;
int val;
}list;

list *start=NULL, *last=NULL;
//----------------------------------------------------

void insert(int n)
{
list *tmp=(list *)malloc(sizeof(list));
tmp->val=n;
tmp->nxt=NULL;
tmp->pre=NULL;

if(start==NULL)
{
	start=last=tmp;
}
else
{
	tmp->pre=last;
	last->nxt=tmp;
	last=tmp;
}

}

//---------------------------------------------------
void display(list *root)
{
list *q=root;
while(q!=NULL)
{
	printf("%d -> ",q->val);
	q=q->nxt;
}
}

//----------------------------------------------------------
void rev_display(list *root)
{
list *q=root;
while(q!=NULL)
{
	printf("%d <- ",q->val);
	q=q->pre;
}
}

//----------------------------------------------------------
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


display(start);

printf("\n....reverse display...\n\n");
rev_display(last);


return 0;
}
