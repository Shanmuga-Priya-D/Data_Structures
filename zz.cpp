#include<iostream>
using namespace std;
struct node
{
	int data;
	node* fore;
	node* back;
};
struct list
{
	int count;
	node* head;
	node* rear;
};
class dll
{
	list *h;
	public:
	dll()
	{
		h=new list;
		h->count=0;
		h->head= NULL;
		h->rear=NULL;
	}
	bool emptyList()
	{
		if(h->count==0)
			return true;
		else
			return false;
	}
	int dllCount()
	{
		return h->count;
	}
	void displayHead()
	{
		if(emptyList())
			cout<<"list is empty";
		node* temp=h->head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->fore;
		}
		cout<<"NULL";
	}
	void displayRear()
	{
		if(emptyList())
			cout<<"list is empty";
		node* temp=h->rear;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->back;
		}
		cout<<"NULL";
	}
void insert(int x)
{
node* nn=new node;
nn->data=x;
nn->fore=h->head;
nn->back=NULL;
if(h->head!=NULL)
h->head->back=nn;

h->head=nn;
}
void insertafter(int data,int x)
{
node* nn=new node;
nn->data=data;
node* temp=h->head;
while(temp->fore!=NULL&&temp->data!=x)
temp=temp->fore;

nn->fore=temp->fore;
nn->back=temp;
temp->fore=nn;
temp=nn;
cout<<"element inserted";
}
void dele(int x)
{
node* temp=h->head;
while(temp->fore!=NULL&&temp->data!=x)
temp=temp->fore;
temp->fore->back=temp->back;
temp->back->fore=temp->fore;
delete temp;
}
};
int main()
{
dll d;
d.insert(1);
d.insert(2);
d.insert(3);
d.insert(4);

d.displayHead();
//d.insertafter(5,3);
//d.displayHead();
d.dele(2);
d.displayHead();
return 0;
}



