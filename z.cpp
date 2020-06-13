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
	bool searchList(node* &ppre,node* &ploc,int target)
	{	bool found;
		ppre=NULL;
		ploc=h->head;
	 	while(ploc!=NULL && target>ploc->data)
		{
			ppre=ploc;
			ploc=ploc->fore;
		}
		if(ploc==NULL)
			found=false;
		else
		{
			if(target==ploc->data)
				found=true;
			else
				found=false;
		}
		return found;
	}
	int insert(node* ppre,node*ploc,int datain)
	{
	
		bool found;
		found=searchList(ppre,ploc,datain);
		if(!found)
		{	
			node* newnode=new node;
			newnode->data=datain;
			++(h->count);
			if(ppre==NULL)
			{
				newnode->back=NULL;
				newnode->fore=h->head;
				h->head=newnode;	
			}
			else
			{
				newnode->fore=ploc;
				newnode->back=ppre;
				ppre->fore=newnode;
			}
			if(ploc==NULL)
				h->rear=newnode;
			else
				ploc->back=newnode;
			return 1;
		}
		
	}
	void destroy()
	{
		node* temp=h->head;
		while(temp!=NULL)
		{
			temp=temp->fore;
			delete temp;
		}
		h->count=0;
		h->head=NULL;
		h->rear=NULL;
	}
	
	bool deleteNode(node* ppre,node*ploc,int datain)
	{
		if(emptyList())
			return false;
		bool found;
		found=searchList(ppre,ploc,datain);
		if(found)
		{
			node* temp= ploc;
			if(ppre==NULL)
			{
				h->head=ploc->fore;
				ploc->fore->back=NULL;
			}
			else if(ploc->fore==NULL)
			{
				h->rear=ppre;
				ppre->fore=NULL;

			}
			else
			{

				ppre->fore=ploc->fore;
				ploc->fore->back=ppre;

			}

			delete temp;
			--(h->count);
			return true;
			
		}
		return false;

	}
	int searchHead(int target)
	{
		node*ploc=h->head;
		int pos=1;
		while(ploc!=NULL && target>ploc->data)
		{
			pos++;
			ploc=ploc->fore;
		}
		if(ploc==NULL)
			return -1;
		else
		{
			if(target==ploc->data)
				return pos;
			else	
				return -1;
		}
	}
	int searchRear(int target)
	{
		node*ploc=h->rear;
		int pos=1;
		while(ploc!=NULL && target<ploc->data)
		{
			pos++;
			ploc=ploc->back;
		}
		if(ploc==NULL)
			return -1;
		else
		{
			if(target==ploc->data)
				return pos;
			else
				return -1;
		}
	}
     node* gethead()
      {
     return h->head;
      }

   static void concatenate(node* a,node* b)
   {
  if(a!=NULL&&b!=NULL)
  {
   if(a->fore==NULL)
      a->fore=b;
   else
     concatenate(a->fore,b);
    }
  else
   cout<<"either a or b is null";

}



};
int main ()
{

	dll d,d1;int n,data,p;
	node* ppre=NULL,*ploc=NULL;
        d.insert(ppre,ploc,1);
        d.insert(ppre,ploc,2);
        d.insert(ppre,ploc,3);
        d.insert(ppre,ploc,4);

        d1.insert(ppre,ploc,5);
        d1.insert(ppre,ploc,6); 
        d1.insert(ppre,ploc,7);
        d1.insert(ppre,ploc,8);

       dll::concatenate(d.gethead(),d1.gethead());
       d.displayHead();
       return 0;

}

	

