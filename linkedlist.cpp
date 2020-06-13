#include<iostream>
using namespace std;
struct node
{
int data;
node* link;
};
struct list
{
int count;
node* head;
};
class linkedlist
{
list h;
public:
linkedlist()
{
h.count=0;
h.head=NULL;
}
node* gethead()
{
return h.head;
}
bool insert(node *&ppre,int datain)
{
node* pnew=new node();
pnew->data=datain;
if(ppre==NULL)
{
pnew->link=h.head;
h.head=pnew;
}
else
{
pnew->link=ppre->link;
ppre->link=pnew;
}
h.count++;
return true;
}

int deletenode(node *&ppre,int dataout,node *&ploc)
{
ppre->link=ploc;
ploc->data=dataout;
if(ppre==NULL)
{
h.head=ploc->link;
}
else
{
ppre->link=ploc->link;
}
h.count--;
return dataout;
}
bool search(node *&ppre,node *&ploc,int target)
{
bool found;
ploc=h.head;
while((ploc!=NULL)&&(target>ploc->data))
{
ppre=ploc;
ploc=ploc->link;
}
if(ploc==NULL)
{
found=false;
}
else
{
if(target==ploc->data)
{
found=true;
}
else
{
found=false;
}
return found;
}

}
bool isempty()
{
if(h.count==0)
{
return true;
}
else
{
return false;
}
}
int lcount()
{
return h.count;
}
bool traverse()
{
node* temp;
temp=h.head;
if(isempty())
return false;
else
{
while(temp!=NULL)
{
cout<<endl<<temp->data<<endl;
temp=temp->link;
}
return true;
}
}
};
int main()
{
linkedlist l;
node *ppre,*ploc;
int datain,dataout,c,sele;
while(1)
{
cout<<endl<<"1.insertion"<<endl<<"2.deletion"<<endl<<"3.search"<<endl<<"4.display"<<endl<<"5.listcount"<<endl<<"6.exit"<<endl;
cout<<"enter your choice";
cin>>c;
switch(c)
{
case 1:ppre=NULL;ploc=NULL;
       cout<<"enter data to insert";
       cin>>datain;
       l.search(ppre,ploc,datain);
       if(l.insert(ppre,datain))
       {
       cout<<"element inserted";
       }
       else
       {
       cout<<"element not inserted";
       }
       break;
case 2:ppre=NULL;ploc=NULL;
       cout<<"enter data to delete";
       cin>>dataout;
       l.search(ppre,ploc,dataout);
       if(l.deletenode(ppre,dataout,ploc))
       {
       cout<<dataout<<"is deleted";
       }
       else
       {
       cout<<"element is not deleted";
       }
       break;
case 3:cout<<"enter element to search";
       cin>>sele;
       ppre=NULL;
       ploc=NULL;
       if(l.search(ppre,ploc,sele))
        {
        cout<<"element found";
        }
      else
       {
      cout<<"element not found";
       }
       break;
case 4:l.traverse();
       break;
case 5:cout<<"count is"<<l.lcount();
       break;
case 6:return 0;
default:cout<<"invalid choice";
}
}
}


