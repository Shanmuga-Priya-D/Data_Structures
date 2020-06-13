#include<iostream>
using namespace std;
struct node
{
	char data;
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
	void displayHead(int x)
	{
		if(emptyList())
			cout<<"list is empty";
		node* temp=h->head;
                  int k=1;
                 while(k<=x&&temp!=NULL)
	        {
	        cout<<temp->data;
                k++;
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
	bool searchList(node* &ppre,node* &ploc,char target)
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
	int insert(node* ppre,node*ploc,char datain)
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
	
	bool deleteNode(node* ppre,node*ploc,char datain)
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
	int searchHead(char target)
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
	int searchRear(char target)
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
void reverse()
{
node* temp=NULL;
node* curr=h->head;
while(curr!=NULL)
{
temp=curr->back;
curr->back=curr->fore;
curr->fore=temp;
curr=curr->back;
}
if(temp!=NULL)
h->head=temp->back;
}



};
int main ()
{
	dll d,d1;int n;char data;int p;
char s1[10] ,s2[10] ;
int x,y;
	node* ppre=NULL,*ploc=NULL;
cout<<"enter first string";
cin>>s1;
cout<<"enter second string";
cin>>s2;
cout<<"enter x";
cin>>x;
cout<<"enter y";
cin>>y;
int i;
	while(1)
	{
cout<<"enter for first dll"<<"\n";
  cout<<"\n1.insert\n2.delete\n3.search\n4.display from head\n5.display from rear\n6.search from head\n7.search from Rear\n8.destroy list\n 9. list count \n 10.empty list\n 111.reverse \n exit";
cout<<"enter for second dll"<<"\n";
cout<<"\n11.insert\n12.delete\n13.search\n14.display from head\n15.display from rear\n16.search from head\n17.search from Rear\n18.destroy list\n 19. list count \n 20.empty list\n 222.reverse \n exit";
		cout<<"Enter choice";
		cin>>n;
		switch(n)
		{
			case 1:for(i=0;i<s1[i]!='\0';i++)
                            {
                                
				if(d.insert(ppre,ploc,s1[i]))
					cout<<"Data entry successful";
				else
					cout<<"Data entry unsuccessful";
                            }
				break;
                            
			case 2:cout<<"Enter data to be deleted";cin>>data;
				if(d.deleteNode(ppre,ploc,data))
					cout<<"Data deletion successful";
				else
					cout<<"Data deletion unsuccessful";
				break;

			case 3:cout<<"Enter data to be searched";
				cin>>data;
				if(d.searchList(ppre,ploc,data))
					cout<<data<<" is found";
				else
					cout<<data<<" is not found";
				break;
			case 4:d.displayHead(x);break;
			case 5:d.displayRear();break;
			case 6:cout<<"Enter data to be searched";
				cin>>data;
				p=d.searchHead(data);
				if(p==-1)
					cout<<data<<" not found";
				else
					cout<<data<<" is found in pos"<<p;
				break;
			case 7:cout<<"Enter data to be searched";
				cin>>data;
				p=d.searchRear(data);
				if(p==-1)
					cout<<data<<" not found";
				else
					cout<<data<<" is found in pos"<<p;
				break;
			case 8:d.destroy();break;
			case 9:cout<<"No.of nodes is"<<d.dllCount();break;
			case 10:if(d.emptyList())
					cout<<"List is empty";
				else
					cout<<"List is not empty";
				break;
			case 111:d.reverse();break;
                        
                        case 11:for(i=0;i<s2[i]!='\0';i++)
                            {
                                
				if(d1.insert(ppre,ploc,s2[i]))
					cout<<"Data entry successful";
				else
					cout<<"Data entry unsuccessful";
				
                            }
                                 break;
			case 12:cout<<"Enter data to be deleted";cin>>data;
				if(d1.deleteNode(ppre,ploc,data))
					cout<<"Data deletion successful";
				else
					cout<<"Data deletion unsuccessful";
				break;

			case 13:cout<<"Enter data to be searched";
				cin>>data;
				if(d1.searchList(ppre,ploc,data))
					cout<<data<<" is found";
				else
					cout<<data<<" is not found";
				break;
			case 14:d1.displayHead(y);break;
			case 15:d1.displayRear();break;
			case 16:cout<<"Enter data to be searched";
				cin>>data;
				p=d1.searchHead(data);
				if(p==-1)
					cout<<data<<" not found";
				else
					cout<<data<<" is found in pos"<<p;
				break;
			case 17:cout<<"Enter data to be searched";
				cin>>data;
				p=d1.searchRear(data);
				if(p==-1)
					cout<<data<<" not found";
				else
					cout<<data<<" is found in pos"<<p;
				break;
			case 18:d1.destroy();break;
			case 19:cout<<"No.of nodes is"<<d1.dllCount();break;
			case 20:if(d1.emptyList())
					cout<<"List is empty";
				else
					cout<<"List is not empty";
				break;
			case 222:d1.reverse();break;
                        case 0:return 0;
	
		}
	}
}

	

