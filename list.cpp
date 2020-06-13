#include<iostream>
using namespace std;
struct node{
    char data;
    node *link;
};
class SLL
{
	   node *root;
	   public:
	   SLL()
	   {  root=NULL; }
	   void insert(char x)
	   {
		     node* nn=new node;
		     nn->data=x;
		     nn->link=root;
		     root=nn;
                    cout<<"node inserted";
	   }
	   void deletee(char x)
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
	   void search(char[] x)
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
	   void count()
	   {
		      node *t=root;
		      int c=0;
		      while(t!=NULL)
		      {
			  c++;
			 t=t->link;
		      }
		     cout<<endl<<"The no of elements are: "<<c;
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
void sorting()
{
node* t=root;
int i,j,key;
for(i=1;t!=NULL;i++)
{
key=temp->data;
j=i-1;
while((j>=0)&&(a[j]>key))
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=key;
}
}
 
            
};
main()
{
   int n;
   char x[10],ch;
   SLL s;
   do{
   cout<<endl<<"Choose: 1. Insert\t2.Delete\t3.Search\t4.Empty\t5.Count\t6.Destroy\t7.Display\t8.sorting"<<endl;
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
      case 8:  s.sorting();break;
   }
   cout<<endl<<"Do you want to continue?(y/n)";
   cin>>ch;
   }while(ch=='y');
}
             

