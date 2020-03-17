#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
}*first,*last;

void create (struct node *p,struct node *q,int n)
{
        for (int i=0;i<n;i++)
    {
        if(i==0)
        {

        p=new struct node;
        cin>>p->data;

        q=p;
        }
       else
       {
           q->next=new struct node;
            q=q->next;
           cin>>q->data;


       }
    }
    q->next=NULL;
    first=p;
    last=q;
}

void display (struct node *r)
{

    if(r!=0)
    {
    cout<<r->data;
    display (r->next);
    //cout<<r->data;
    }
    cout<<endl;
}

int Inodecount(struct node *a)
{
    struct node *p;
    p=a;
    int c=0;
    while(p!=0)
    {
      c++;
      p=p->next;
    }
    return c;
}

int Rnodecount1(struct node *a)
{
    int c=0;
    while(a!=0)
    {
        c++;
        a=a->next;
        Rnodecount1(a);
    }
    return c;
}

int Rnodecount2(struct node *a)
{
    if(a==0)
        return 0;
    else
        return Rnodecount2(a->next)+1;
}

int sum(struct node *a)
{
    if (a==0)
        return 0;
    else
        return sum(a->next)+a->data;
}

int maximum(struct node *a)
{
    int maxi=a->data;
    while (a)
    {
        if(maxi<a->data)
            maxi=a->data;
        a=a->next;
    }
    return maxi;
}

int Rmaximum(struct node *a)
{
    int x;
 if(a)
 {
     x=Rmaximum(a->next);
    if (x>a->data)
        return x;
    else
        return a->data;
 }
 return 0;

}

struct node * Search (struct node *a, int b)
{
    while (a!=0)
    {
        if(a->data==b)
        return a;
        else
        a=a->next;
    }
    cout<<"element not found"<<endl;
    return 0;
}

node *SearchMth(node *a, int b)
{
    node *temp=a;
    while(a!=0)
    {
        if(a==first && a->data==b)
            return a;
        else if(a!=first && a->data==b)
        {
            temp->next=a->next;
            a->next=first;
            first=a;
            return a;
        }
        temp=a;
        a=a->next;
    }
    cout<<"element not found"<<endl;
    return 0;
}

void Insert (node *a,int b,int d)
{
     node *c= new node;
     int l=1;
    if(b==0)
    {
       c->next=first;
       first=c;
       first->data=d;
       return;
    }
    else
    {
       while (a!=0 && b>l)
       {

           a=a->next;
           l++;
       }
       c=a->next;
       a=c;
       a->data=d;
    }
}

int main()
{
    struct node *t;
    int r,c;
    cout<<"enter the no of elements"<<endl;
    cin>>r;
    cout<<"enter the elements one by one"<<endl;

    create(first,last,r);
    display(first);
    /*//cout<<"No. of nodes= "<<Inodecount(first)<<endl;
    //cout<<"No. of nodes= "<<Rnodecount2(first);
    //cout<<"sum is= "<<sum(first);
    //cout<<"maximum element is "<<Rmaximum(first);
    while (1)
    {
    cout<<"enter the element to be searched"<<endl;
    cin>>c;
    t=SearchMth(first,c);
    cout<<t->data<<endl;
    display(first);
    }
*/
    Insert (first,1,5);
    display(first);


}

