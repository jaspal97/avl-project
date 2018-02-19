#include<iostream>
using namespace std;
struct node* insert(int n,struct node *r);
void preorder(struct node *p);
struct node
{
   int value;
   struct node * lptr;
   struct node * rptr;
   int height;
}*root;
main()
{
 root=NULL;
   while(1)
   {
   int f,n;
   /*
   cout<<"do wo want to insert any element:enter 1 or 0"<<endl;
   cin>>f;
   if(f==0)
   break;
   cout<<"enter the value of the number:"<<endl;
   cin>>n;
   insert(n,root);
   cout<<"do you wamt to display:enter 1 or 0"<<endl;
   cin>>f;
   if(f==1)
   */
   cin>>n;
   insert(n,root);
   preorder(root);
   }
}

struct node* insert(int n,struct node *r)
{
struct node*p;
    if(root==NULL)
   {
   cout<<"hello";
       root=new node;
       root->value=n;
       root->height=0;
       root->lptr=NULL;
       root->rptr=NULL;
   }
   else if(r==NULL)
   {
       p=new node;
       p->value=n;
       p->lptr=NULL;
       p->rptr=NULL;
       p->height=0;
       cout<<"returned"<<endl;
       cout<<p->lptr<<" "<<p->rptr<<" "<<p->value<<" "<<endl;
       return(p);
   }
   else
   {
       if(r->value<=n)
       {
           r->height++;
           r->rptr=insert(n,r->rptr);
       }
       if(r->value>n)
       {
           r->height--;
           r->lptr=insert(n,r->lptr);
       }
   }
}
int i=0;
void preorder(struct node *p)
{

    if(p!=NULL)
    {
    i=0;
       cout<<(++i)<<endl;
        preorder(p->lptr);
        cout<<p->value<<endl;
        preorder(p->rptr);
    }
    else
    return;
}
