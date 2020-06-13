#include<iostream>
#include<string.h>
using namespace std;
struct node
{
string name;
int age;
double height;
node* next;
};
class list
{
node* root;
public:
list()
{
root=NULL;
}
void insert()
{
node *temp;
temp = new node;
cout<<"enter name";
cin>>temp->name;
cout<<"enter age";
cin>>temp->age;
cout<<"enter height";
cin>>temp->height;
cout<<endl;
temp->next=root;
root=temp;
cout<<"node inserted";
}
void sortname()
{
   node* temp=root;
   string tname;
   int counter=0;
   /*while(temp)
     {
     temp=temp->next;
     counter++;
     }
   temp=root;*/
    
      while(temp->next)
       {
        if(strcmp(temp->name,temp->next->name)>0)
              {
             strcpy(tname,temp->name);
             strcpy(temp->name,temp->next->name);
             strcpy(temp->next->name,tname);

              }
          temp=temp->next;
         }
        
      

}

void swap(node* a,node* b)
{
int temp=a->age;
a->age=b->age;
b->age=temp;
}
 void sort() 
    {
     int swapped;
    node* lptr;
    node* rptr= NULL;
    do
     {
      swapped=0;
       lptr=root;
       while(lptr->next!=rptr)
         {
           if(lptr->age > lptr->next->age)
               {
                swap(lptr,lptr->next);
                swapped=1;
               }
            lptr=lptr->next;
          }
      rptr=lptr;
     }while(swapped);
}
void display()
{
node *t=root;
if(t==NULL)
cout<<"list is empty";
else
{
while(t!=NULL)
{
cout<<"name is"<<t->name<<endl;
cout<<"age is"<<t->age<<endl;
cout<<"height is"<<t->height<<endl;
t=t->next;
}
}
}
};
int main()
{
list l;
int c;
while(1)
{
cout<<"1.insert 2.display  2.sort 3.sort name";
cout<<"enter your choice";
cin>>c;
switch(c)
{
case 1:l.insert();break;
case 2:l.display();break;
case 3:l.sort();break;
case 4:l.sortname();break;
return 0;
}
}
}
