

#include<iostream>
using namespace std;
struct node
{
	int data;
	node* link;
};
struct head
{
	int count;
	node *front,*rear;
};
class queuel
{
	head *h;
	public:
	queuel()
	{
	h->count=0;
	h->front=NULL;
	h->rear=NULL;
}
bool isempty()
{
	if(h->count==0)
	return true;
	else
	return false;
}
void enqueue(int datain)
{
	node* nn=new node;
	nn->data=datain;
	nn->link=NULL;
	if(isempty())
	{
		h->front=nn;
	}
	else
	{
		node* temp;
		temp=h->front;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=nn;
		h->rear=nn;
	}
	h->count++;
	cout<<"node inserted";
}
void dequeue(int dataout)
{
    if(isempty())
    cout<<"queue is empty";
    else
      {
       dataout=h->front->data;
       		if(h->count==1)
                 {
        	h->rear=NULL;
                h->front=NULL;
                 }
           else
             {
              node* temp=h->front;
               h->front=h->front->link;
               delete temp;
               h->count--;
             }
         }
          
cout<<"element deleted";
}
void count()
{
cout<<"count is"<<h->count;
}
void getrear()
{
    if(isempty())
    cout<<"queue is empty";
    else if(h->count==1)
     
    cout<<"element at rear is"<<h->front->data;

    else
      
      cout<<"element at rear is"<<h->rear->data;
     
}
void getfront()
{
   if(isempty())
   cout<<"queue is empty";
   else
    {
       cout<<"element at front is"<<h->front->data;
    }
}
void destroy()
{
   while(h->front!=NULL)
      {
       h->front=h->front->link;
       delete h->front;
       h->count--;
      }
cout<<"queue destroyed";
}
void display()
{
   node* temp=h->front;
   while(temp!=NULL)
    {
    cout<<temp->data;
    temp=temp->link;
    }
}
};
int main()
{
	queuel  q;
	int ele,c,dataout;
	while(1)
	{
	cout<<"1.enqueue  2.dequeue  3.front  4.rear  5.count  6.display   7.destroy\n";
	cout<<"\nenter your choice :";
	cin>>c;
switch(c)
{
case 1:cout<<"enter element to push:";
       cin>>ele;
       q.enqueue(ele);
       break;
case 2:q.dequeue(dataout);
       break;
case 3:q.getfront();break;
case 4:q.getrear();break;
case 5:q.count();break;
case 6:q.display();break;
case 7:q.destroy();break;
}
}
}
