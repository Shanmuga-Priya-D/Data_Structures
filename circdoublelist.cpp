
#include<iostream>
using namespace std;
struct node
{
 int data;
 node *fore;
 node *back;
};
struct list
{
 int count;
 node *head;
 node *rear;
};
class CDLL
{
 list *h;
 public:
 CDLL()
 {
h=new list();
h->count=0;
h->head=NULL;
h->rear=NULL;
}
 
 
 void insert(int d)
 {
  node *pnew=new node;
  pnew->data=d;
  node *ppre=NULL;
  node *suc=NULL;
  if(h->count==0)
  {
   h->head=h->rear=pnew;
   pnew->fore=pnew->back=pnew;
   ++(h->count);
  }
  else{
  bool f=search(ppre,suc,d);
  if(!f)
  {
   if(ppre==NULL)
   {
    pnew->back=h->rear;
    pnew->fore=h->head;
    h->head->back=h->rear->fore=pnew;
    h->head=pnew;
   }
   else if(ppre->fore==h->head)
   {
    pnew->fore=h->head;
    pnew->back=h->rear;
    h->rear->fore=h->head->back=pnew;
    h->rear=pnew;
   }
   else
   {
    pnew->back=ppre;
    pnew->fore=ppre->fore;
    ppre->fore->back=pnew;
    ppre->fore=pnew;
   }
   ++(h->count);
   cout<<"element inserted";
  }
  else
  cout<<"cannot insert"<<endl;
 }}
 void deletenode(int tar)
 {
  node *dlt=NULL;
  node *del=NULL;
  node *sud=NULL;
  bool f=search(dlt,sud,tar);
  if(f)
  {
   if(h->count==1)
   {
    del=h->head;
    h->head=h->rear=NULL;
    delete del;
    --(h->count);
   }
   else if(dlt==NULL)
   {
    del=h->head;
    h->head=h->rear->fore=del->fore;
    del->fore->back=h->rear;
    delete del;
    --(h->count);
   }
   else if(dlt->fore->fore==h->head)
   {
    del=dlt->fore;
    h->rear=h->head->back=dlt;
    dlt->fore=h->head;
    delete del;
    --(h->count);
   }
   else
   {
    del=dlt->fore;
    dlt->fore=del->fore;
    del->fore->back=del->back;
    delete del;
    --(h->count);
   }
cout<<"element deleted";
  }
  else
  cout<<"deleting data not found"<<endl;
 }
 bool search(node *&pre,node *&ploc,int se)
 {
  pre=NULL;
  ploc=h->head;
  if(ploc->data==se)
  {
   ploc=ploc->fore;
   return true;
  }
  if(se<h->head->data)
  {
   return false;
  }pre=ploc;ploc=ploc->fore;
  while(ploc!=h->head&&se>ploc->data)
  {
   pre=ploc;
   ploc=ploc->fore;
  }
  if(ploc->data==se)
   return true;
  else
   return false;
 }
 void displayheadtorear()
 {
  if(h->count==0)
  cout<<"list is empty"<<endl;
  else{
  node *temp=h->head;
  cout<<temp->data<<endl;
  temp=temp->fore;
  while(temp!=h->head)
  {
   cout<<temp->data<<endl;
   temp=temp->fore;
  }}
 }
 void displayreartohead()
 {
  if(h->count==0)
  cout<<"list is empty"<<endl;
  else{
  node *temp=h->rear;
  cout<<temp->data<<endl;
  temp=temp->back;
  while(temp!=h->rear)
  {
   cout<<temp->data<<endl;
   temp=temp->back;
  }}
 }
 int poshead(int ph)
 {
  int pos;
  if(h->count==0)
  cout<<"list is empty"<<endl;
  else{
  node *temp=h->head;
  pos=1;
  if(temp->data==ph)
  return pos;
  temp=temp->fore;
  ++pos;
  while(temp!=h->head&&ph!=temp->data)
  {
   temp=temp->fore;
   ++pos;
  }
  if(ph==temp->data) 
  return pos;
  else
  return -1;
  }
 }
 int posrear(int pr)
 {
  int pos;
  if(h->count==0)
   cout<<"list is empty"<<endl;
  else
  {
   node *temp=h->rear;
   pos=1;
   if(temp->data==pr)
   return pos;
   temp=temp->back;
   ++pos;
   while(temp!=NULL&&temp->data!=pr)
   {
    temp=temp->back;
    ++pos;
   }
   if(temp->data==pr)
   return pos;
   else
   return -1;
  }
 }
 void destroy()
 {
  node *temp=h->head;
  node *del=NULL;
  if(h->count!=0){
  del=temp;
  temp=temp->fore;
  delete temp;
  while(temp!=h->head)
  {
   del=temp;
   temp=temp->fore;
   delete del;
  }
 }
  h->head=NULL;
  h->rear=NULL;
  h->count=0;
 }
  int listcount()
   {
   return h->count;
   }
};
int main()
{
 int ch,p,key;node *A=NULL; node *B=NULL;
 CDLL c;
  //cdll.createlist();
 cout<<"1.insert,2.delete,3.search,4.display from head,5.display from rear,6.listcount,7.destroy,8.searchfromhead,9.searchfromrear"<<endl;
 while(1)
 {
  cout<<"enter ur choice"<<endl;
  cin>>ch;
  switch(ch)
  {

    case 1:cout<<"\nenter key";
           cin>>key;
           c.insert(key);
	   break;
    case 2:cout<<"\nenter key";
           cin>>key;
           c.deletenode(key);
	     break;
   case 3:cout<<"\nenter key";
           cin>>key;
           if(c.search(A,B,key))
           cout<<"element found";
           else
           cout<<"element not found";
	  break;
   case 4:c.displayheadtorear();
          break;
   case 5:c.displayreartohead();
          break;
   case 6:cout<<"list count is"<<c.listcount();
          break;
    case 7:c.destroy();break;
    case 8:cout<<"\nenter key";
           cin>>key;
           p=c.poshead(key);
            if(p==-1)
             cout<<"element is not found";
             else
             cout<<"element is found in pos"<<p;
              break;
	case 9:cout<<"\nenter key";
	       cin>>key;
	       p=c.posrear(key);
            if(p==-1)
               cout<<"element is not found";
             else
             cout<<"element is found in pos"<<p;
              break;
             
   default:cout<<"invalid i/p";
           break;
 }
  }
 
  }

	
	
	

