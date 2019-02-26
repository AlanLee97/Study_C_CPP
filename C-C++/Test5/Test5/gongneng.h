#include<malloc.h>
#include<stdio.h>

typedef int elemtype;

typedef struct lnode
{
	elemtype data;
	struct lnode *next;
} linknode;

void createlist(linknode *&l, elemtype a[], int n)
{
	l = (linknode *)malloc(sizeof(linknode));
	linknode *s, *r;
	r = l;//指针 r 指向最后
	for (int i = 0;i<n;i++)
	{
		s = (linknode *)malloc(sizeof(linknode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void display(linknode *l)
{
	linknode *p;
	p = l->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n\n");
}

void listinsert(linknode *&x, linknode *&y)
{
	linknode *end;
	end = x->next;
	while (end->next != NULL)
	{
		end = end->next;
	}
	end->next = y->next;
}

void chachong(linknode *&x,linknode *&y)
{
	linknode *a,*b,*c;
	a=x;
	b=y;
	//c = NULL;
	while(a->next!=NULL)
	{
		while(b->next!=NULL)
		{
			if(a->data==b->data)
				{
					c->next=b;
					c->next=b->next;
					free(b);
					b=c;
					
				}
			b=b->next;
		}
		a=a->next;
		b=y;
	}
}

