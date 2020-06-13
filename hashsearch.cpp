#include<iostream>
using namespace std;
struct node
{
int data;
node* link;
};
struct Hash
{
int count;
node* head;
};
class hashtable
{
Hash ht[30];
int size;
public:
hashtable()
{
   size=10;
   for(int i=0;i<size;i++)
     {
      ht[i].count=0;
      ht[i].head=NULL;
     }
}
node* createnode(int key)
{
node* nn=new node();
nn->data=key;
nn->link=NULL;
return nn;
}

void insert(int key)
{
int hi=key%size;
node* nn=createnode(key);
nn->link=ht[hi].head;
ht[hi].head=nn;
ht[hi].count++;
cout<<"node inserted";
}
int del(int dltkey)
{
int hi=dltkey%size;
node* delnode=ht[hi].head;
node* temp=NULL;
while(delnode!=NULL)
  {
if(delnode->data==dltkey)
  {
    if(temp==NULL)
     {
      ht[hi].head=delnode->link;
     }
    else
     {
     temp->link=delnode->link;
     }
  ht[hi].count--;
 
 }
temp=delnode;
delnode-delnode->link;
 return 1;
}

}

int search(int skey)
{
  int hi=skey%size;
  node* snode=ht[hi].head;
  while(snode!=NULL)
    {
     if(snode->data==skey)
      {
      return 1;
      }
      else
      {
      return 0;
      }
    snode=snode->link;
    }
}
void display()
{
int  i=0;
while(i<size)
{
node* temp=ht[i].head;
while(temp!=NULL)
   {
   cout<<"data is"<<temp->data;
   temp=temp->link;
   }
 i++;
}
}
};
int main()
{
hashtable h;
int key,dltkey,skey;
int c;
while(1)
  {
    cout<<"1.insert \n 2.delete \n 3.search \n 4.display \n 5.exit\n";
    cout<<"enter your choice";
    cin>>c;
    switch(c)
    {
     case 1:cout<<"enter element to insert";
            cin>>key;
            h.insert(key);
            break;
    case 2:cout<<"enter element to delete";
           cin>>dltkey;
           if(h.del(dltkey))
             {
             cout<<"\n"<<dltkey<<"is deleted";
             }
           else
           {
           cout<<"element is not deleted";
           }
           break;
   case 3:cout<<"enter element to search";
          cin>>skey;
          if(h.search(skey))
          {
          cout<<skey<<"is found"<<endl;
          }
          else
          {
          cout<<skey<<"is not found"<<endl;
          }
          break;
   case 4:h.display();
          break;
  case 5:return 0;
  default:cout<<"invalid choice";
  }
}
}


       
         
         
 
   
   
	
	
	

