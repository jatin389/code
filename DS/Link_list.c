#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
int val;
struct val *nxt;
}list;


list * start=NULL;
list * last=NULL;
//-------------------------------------------------

void insert(int x)
{

list *tmp=(list *)malloc(sizeof(list));
tmp->val=x;
tmp->nxt=NULL;

if(start==NULL)
start=last=tmp;

else
{
	last->nxt=tmp;
	last=tmp;

}
}
//--------------------------------------------------------

void display(list * root)
{
list *q=root;
while(q!=NULL)
{
printf("%d -> ", q->val);
q=q->nxt;
}
}

//---------------------------------------------------------
void reverse(list * root)
{
list *prev, *next, *curr;
prev=next=NULL;
curr=root;

while(curr!=NULL)
{
	next=curr->nxt;
	curr->nxt=prev;
	prev=curr;
	curr=next;
}

start=prev;
}

//----------------------------------------------------------
int main()
{
int n;
printf("enter no. of elemnts\n");
scanf("%d",&n);

printf("enter elements");

int x;

for(int i=0;i<n;i++)
{
scanf("%d",&x);
insert(x);
}


display(start);
reverse(start);
printf("\n\n.......reversed list ......\n");
display(start);
	
return 0;
}
