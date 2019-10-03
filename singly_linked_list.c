#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *n,*s,*t,*r,*l,*m,*a,*b;
struct node *p=NULL;

struct node* getnode()
{
    struct node* q;
    q=(struct node *)malloc(1*sizeof(struct node));
    return q;
};
void insert_end()
{
    int x;
    printf("Enter the data.\n");
    scanf("%d",&x);
    t=getnode();
    t->data=x;
    t->next=NULL;

    if(p==NULL)
    {
        p=t;
    }
    else
    {
        r=p;
        while(r->next!=NULL)
        {
            r=r->next;
        }
        r->next=t;
    }
}

void display()
{
    r=p;
    while(r!=NULL)
    {
    printf("Data=%d\t",r->data);
    r=r->next;
    }
    printf("\n\n\n");
}
void insert_front()
{
    int x;
    printf("Enter the data.\n");
    scanf("%d",&x);
    t=getnode();
    t->data=x;
    t->next=p;
    p=t;
}

void delete_end()
{
    r=p;
    while(r->next!=NULL)
    {
        l=r;
        r=r->next;
    }
    free(r);
    l->next=NULL;
}
void delete_front()
{
    s=p;
    n=s->next;
    free(s);
    p=n;
}

void insert_n()
{
    int x,i;
    printf("Enter the position");
    scanf("%d",&x);
    m=p;
    t=getnode();
    printf("Please enter the data.\n");
    scanf("%d",&t->data);
    if(x==1)
    {
        p=t;
        t->next=NULL;
    }
    else
    {
        for(i=1;i<x-1;i++)
        {
            m=m->next;
        }
        a=p;
        for(i=1;i<x;i++)
        {
            a=a->next;
        }
    m->next=t;
    t->next=a;
    }
}

void delete_n()
{
    int x,i;
    printf("Enter the position");
    scanf("%d",&x);
    m=p;
    for(i=1;i<x-1;i++)
    {
        m=m->next;
    }
    a=p;
    for(i=1;i<x;i++)
    {
        a=a->next;
    }
    b=p;
    for(i=0;i<x;i++)
    {
        b=b->next;
    }
    m->next=b;
    free(a);
}
void main()
{
    int n;
    while(1)
    {
    printf("Enter your choice.\n1.Insert end.\n2.Insert front.\n3.Delete end.\n4.Delete front.\n5.Display\n6.Insert as nth node\n7.Delete nth node\n8.exit.\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: insert_end();
                break;
        case 2: insert_front();
                break;
        case 3: delete_end();
                break;
        case 4: delete_front();
                break;
        case 5: display();
                break;
        case 6: insert_n();
                break;
        case 7: delete_n();
                break;
        case 8: exit(0);
                break;
        default:    printf("Default case is executed.\n");
    }
    }
}
