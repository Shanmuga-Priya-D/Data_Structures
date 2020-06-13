#include<iostream>
using namespace std;
class queue
{
int qu[100],front ,rear,size;
public:
queue()
{
front=-1;
rear=-1;
size=5;
for(int i=0;i<size;i++)
{
qu[i]=0;
}
}
bool isfull()
{
if(rear==size-1)
return true;
else 
return false;
}
bool isempty()
{
if((front==-1)&&(rear==-1))
return true;
else
return false;
}
void enqueue(int x)
{
if(isfull())
{
cout<<"queue is full";
}
else if(isempty())
{
front=rear=0;
}
else
{
rear++;
}
qu[rear]=x;
cout<<"element inserted";

}
}
void dequeue()
{
int dataout;
if(isempty())
{
cout<<"queue is empty";
}
else if(front==rear)
{
dataout=qu[front];
front=rear=-1;
cout<<"element deleted";                 
}
else 
{
dataout=qu[front];
front++;
cout<<dataout<<"is deleted";
}
}
int getfront()
{
if(isempty())
{
return 0;
}
else
{
return qu[front];
}
}
int getrear()
{
if(isempty())
{
return 0;
}
else
{
return qu[rear];
}
}
int count()
{
if(isempty())
{
return 0;
}
else
{
return rear-front+1;
}
}
void display()
{
if(isempty())
{
cout<<"queue is empty";
}
else
{
for(int i=front;i<=rear;i++)
{
cout<<endl<<qu[i]<<endl;
}
}
}
};
int main()
{
queue q;
int ele,c;
while(1)
{
cout<<"1.enqueue  2.dequeue  3.front  4.rear  5.count  6.display  7.exit \n";
cout<<"enter your choice";
cin>>c;
switch(c)
{
case 1:cout<<"enter element to push";
       cin>>ele;
       q.enqueue(ele);
       break;
case 2:q.dequeue();
       break;
case 3:cout<<"element at front is"<<q.getfront();break;
case 4:cout<<"element at rear is"<<q.getrear();break;
case 5:cout<<"count of queue is"<<q.count();break;
case 6:q.display();break;
case 7:return 0;
}
}
}

      
