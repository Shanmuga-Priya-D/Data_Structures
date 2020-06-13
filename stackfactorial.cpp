#include<iostream>
using namespace std;
class st
{
int s[30],n,top,size;
public:
st()
   {
    top=-1;
   }
void get()
   {
   cout<<"enter size";
    cin>>size;
    }
bool isfull()
   {
    if(top==(size-1))
       {
         return true;
        }
      else
       {
        return false;
        }
   }
int push(int ele)
  {
   if(isfull())
    {
   cout<<"stack is full";
     }
    else
    {
     top++;
      s[top]=ele;
      return top;
     }
   }
void factorial()
{
int fact=1;
while(top!=-1)
{
fact=fact*s[top];
top--;
}
cout<<"factorial is"<<fact;
}
};
int main()
{
st z;
z.get();

int ele;
while(1)
    {
    cout<<"enter element to be pushed";
     cin>>ele;
  int res=z.push(ele);
     if(z.isfull())
     {
      break;
     }
}
z.factorial();
return 0;
}


