#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE *link;
};
class queue
{
	   NODE *front,*rear;
	   public:
	   queue()
	   {
		     front=NULL;
		     rear=NULL;
	   }
	   void insert(int x)
	   {
			NODE *nn=new NODE;
			nn->data=x;
			nn->link=NULL;
			if(front==NULL)
			  front=rear=nn;
			else
			{  
			   rear->link=nn;
			   rear=nn;
			}
	   }
	   void del()
	   {
		      if(front==NULL)
		      {
		      	cout<<"empty"<<endl;
			return;
		      }
		      NODE *t;
		      t=front;
		      if(front==rear)
		      {   
			   front=rear=NULL; 
		      }
		      else
		      {
			  front=front->link;
		      }
		      delete t;
	   }
	   int queuefront()
	   {
		      if(front==NULL)
		      {
			 return -1;
		      }
		      else
		      {  
			  return front->data;
		      }
	   }
	   int queuerear()
	   {
		      if(front==NULL)
		      {
			 return -1;
		      }
		      else
		      {  
			  return rear->data;
		      }
	   }
	   bool isempty()
	   {         
		     if(rear==NULL)
		     {
			return 1;
		     }
		     else
		     {
			return 0;
		     }      
	   }
	   int queuecount()
	   {
		     int c=0;
		     if(front==NULL)
		       return -1;
		     NODE *tmp=front;
		     while(tmp!=NULL)
		     {
			 c++;
			 tmp=tmp->link;
		     }
		      return c;
	   } 
	   void display()
	   {
		     if(front==NULL)
		       cout<<"Queue is empty.";
		     else
		     {
		       NODE *t=front;
		       cout<<"The elements in the queue are:"<<endl;
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
	   queue q;
	   do{
	   cout<<"Choose:"<<endl;
	   cout<<"1. insert"<<endl<<"2. delete"<<endl<<"3. front element of the queue"<<endl<<"4. rear element of the queue"<<endl<<"5. check if queue is empty"<<endl<<"6. No of elements in the queue"<<endl<<"7. display"<<endl;
	   cin>>n;
	   switch(n)
	   {
		      case 1:  cout<<"Enter an element:";
			       cin>>ele;
			       q.insert(ele);
			       break;
		      case 2:  q.del();
			       break;
		      case 3:  if(q.queuefront()==-1)
				   cout<<"Empty"<<endl;
			       else
				   cout<<q.queuefront()<<endl;
			       break;
		      case 4:  if(q.queuerear()==-1)
				   cout<<"Empty"<<endl;
			       else
				   cout<<q.queuerear()<<endl;
			       break;
		      case 5:  if(q.isempty()==1) 
				cout<<"Queue is empty"<<endl;
			       else 
				cout<<"Queue is not empty"<<endl;
			       break;
		      case 6:  if(q.queuecount()==-1) 
				cout<<"Queue is empty"<<endl;
			       else 
				cout<<"no of elements: "<<q.queuecount()<<endl;
			       break;
		      case 7:  q.display();
	   }
	   cout<<endl<<"Do you want to continue?(y/n)";
	   cin>>ch;
	   }while(ch=='y');
}
  
