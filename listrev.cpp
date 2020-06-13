#include<iostream>
using namespace std;
struct node{
    int data;
    node *link;
};
class SLL
{
	   node *root;
	   public:
	   SLL()
	   {  root=NULL; }
	   void insert(int x)
	   {
		     node *nn=new node;
		     nn->data=x;
		     nn->link=root;
		     root=nn;
	   }
	   void deletee(int x)
	   {
		      if(root==NULL)
		      {
			 cout<<endl<<"List empty";
			 return;
		      }
                         node *t=root;
		      while(t->link!=NULL)
		      {
			  if(t->link->data==x)
			  {
			     node *tmpp=t->link;
			     t->link=tmpp->link;
			     delete tmpp;
			     cout<<"element deleted."<<endl;
			     return;
			  }
			  t=t->link;
		      }
		      cout<<endl<<"element not found";
	   }
	   void search(int x)
	   {
		      node *t=root;
		      while(t!=NULL)
		      {
			   if(t->data==x)
			   {
			      cout<<endl<<"element found : "<<t->data;
			      return;
			   }
			  t=t->link;
		      }
		     cout<<"element not found."<<endl;
	   } 
	    void empty()
	   {         
		     if(root==NULL)
		     {
			cout<<endl<<"List empty";
		     }
		     else
		     {
			cout<<endl<<"List not empty";
		     }      
	   }
	   int count()
	   {
		      node *t=root;
		      int c=0;
		      while(t!=NULL)
		      {
			  c++;
			 t=t->link;
		      }
		     cout<<endl<<"The no of elements are: "<<c;
                      return c;
	   } 
	   void destroy()
	   {
		     
		     while(root!=NULL)
		     {
		
			root=root->link;
		
		     }
		     cout<<"list destroyed."<<endl;
	   }
	   void display()
	   {
                     
                  
		     if(root==NULL)
		       cout<<"list is empty.";
		     else
		     {
		       cout<<"The elements in the list are:"<<endl;
		       node *t=root;
		       while(t!=NULL)
		       {
			  cout<<t->data<<" ";   
			  t=t->link;
		       }  
		     }
		     cout<<endl;
	   }
          void rev()
            {
            node* curr=root;
            node  *prev=NULL;node* link=NULL;
            while(curr!=NULL)
             {
             link=curr->link;
             curr->link=prev;
             prev=curr;
             curr=link;
              }
            root=prev;
           }
    void swap(node* a,node* b)
    {
     int temp;
     temp=a->data;
     a->data=b->data;
     b->data=temp;
    }
    void sort() 
    {
     int swapped;
    node* lptr;
    node* rptr= NULL;
    do
     {
      swapped=0;
       lptr=root;
       while(lptr->link!=rptr)
         {
           if(lptr->data > lptr->link->data)
               {
                swap(lptr,lptr->link);
                swapped=1;
               }
            lptr=lptr->link;
          }
      rptr=lptr;
     }while(swapped);
}
void evenodd()
{
node* temp=root;
while(temp!=NULL)
{
if((temp->data%2)==0)
{
deletee(temp->data);
}
temp=temp->link;
}
}
void alternate()//print alternate nodes of list
{
int count=0;
node* temp=root;
while(temp!=NULL)
{
 if(count%2==0)
{
cout<<temp->data;
}
count++;
temp=temp->link;
}
}
void sumalternate()//print sum of alternate nodes
{
int count=0,sum=0;
node* temp=root;
while(temp!=NULL)
{
 if(count%2==0)
{
sum=sum+temp->data;
}
count++;
temp=temp->link;
}
cout<<"sum of alternate nodes is"<<sum;
}
void middle()
{
node* fptr=root;
node* sptr=root;
if(root!=NULL)
{
while((fptr!=NULL)&&(fptr->link!=NULL))
{
fptr=fptr->link->link;
sptr=sptr->link;
}
cout<<"mid element is"<<sptr->data;
}
}
       
};
int main()
{
   int n,x;
   char ch;
   SLL s;
   do{
   cout<<endl<<"Choose: 1. Insert\t2.Delete\t3.Search\t4.Empty\t5.Count\t6.Destroy\t7.Display\t8.reverse\t9.sorting\t.10.deleteeven\t11.alternate\t12.sumofalternate\t13.middle element"<<endl;
   cin>>n;
   switch(n)
   {
      case 1:  cout<<"Enter an element:";
               cin>>x;
               s.insert(x);
               break;
      case 2:  cout<<"Enter the element to be deleted: ";
               cin>>x;
               s.deletee(x);
               break;
      case 3:  cout<<"Enter the element to be searched: ";
               cin>>x;
               s.search(x);
               break;
      case 4:  s.empty();
               break;
      case 5:  s.count();
               break;
      case 6:  s.destroy();
               break;
      case 7:  s.display();break;
      case 8:  s.rev();break;
      case 9:  s.sort();break;
      case 10:s.evenodd();break;
     case 11:s.alternate();break;
     case 12:s.sumalternate();break;  
     case 13:s.middle();break;    
   }
   cout<<endl<<"Do you want to continue?(y/n)";
   cin>>ch;

   }while(ch=='y');
}
             

