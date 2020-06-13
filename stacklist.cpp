#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE *link;
};
class stack
{
	   NODE *top;
	   public:
	   stack()
	   {  top=NULL; }
	   void push(int x)
	   {
		     NODE *nn=new NODE;
		     nn->data=x;
		     nn->link=top;
		     top=nn;
	   }
	   void pop()
	   {
		      if(top==NULL)
		      {
			 cout<<"empty"<<endl;
			 return;
		      }
		      NODE *t=top;
		      top=top->link;
		      delete t;
	   }
	   int stacktop()
	   {
		      if(top==NULL)
		      {
			 return -1;
		      }
		      else
		      {  
			  return top->data;
		      }
	   }
	    bool isempty()
	   {         
		     if(top==NULL)
		     {
			return 1;
		     }
		     else
		     {
			return 0;
		     }      
	   }
	   void destroy()
	   {
		     NODE *t;
		     while(top!=NULL)
		     {
			t=top;
			top=top->link;
			delete t;
		     }
		     cout<<"Stack destroyed."<<endl;
	   }
	   void display()
	   {
		     if(top==NULL)
		       cout<<"Stack is empty.";
		     else
		     {
		       cout<<"The elements in the stack are:"<<endl;
		       NODE *t=top;
		       while(t!=NULL)
		       {
			  cout<<t->data<<" ";   
			  t=t->link;
		       }  
		     }
		     cout<<endl;
	   }	
};
main()
{
	   int n,ele;
	   char ch;
	   stack s;
	   do{
	   cout<<"Choose:"<<endl;
	   cout<<"1. push"<<endl<<"2. pop"<<endl<<"3. top element of the stack"<<endl<< "4. check if stack is empty"<<endl<<"5. destroy stack"<<endl<<"6. display"<<endl;
	   cin>>n;
	   switch(n)
	   {
		      case 1:  cout<<"Enter an element:";
			       cin>>ele;
			       s.push(ele);
			       break;
		      case 2:  s.pop();
			       break;
		      case 3:  if(s.stacktop()==-1)
				   cout<<"Empty"<<endl;
			       else
				   cout<<s.stacktop()<<endl;
			       break;
		      case 4:  if(s.isempty()==1) cout<<"Stack is empty"<<endl;
			       else cout<<"stack is not empty"<<endl;
			       break;
		      case 5:  s.destroy();
			       break;
		      case 6:  s.display();
	   }
	   cout<<"Do you want to continue?(y/n)";
	   cin>>ch;
   	   }while(ch=='y');
}
             

