#include<iostream>
using namespace std;
class stack
{
int st[10],size,top;
public:
stack()
{
   size=5;
   top=-1;
}
bool isempty();
bool isfull();
bool push(int datain);
bool pop(int &dataout);//no difference btw with and without reference
bool stacktop(int &stop);
void display();
};
  

bool stack::isempty()
{
   bool empty;
   if(top==-1)
      {
       empty=true;
      }
   else
      {
      empty=false;
      }
   return empty;
}
bool stack::isfull()
{
   bool full;
   if(top==size-1)
     {
      full=true;
     }
   else
    {
     full=false;
    }
   return full;
}
bool stack::push(int datain)
{
    bool success;
    if(isfull())
     {
      success=false;
     }
   else
     {
     top++;
     st[top]=datain;
     success=true;
     }
   return success;
   
 
} 
bool stack::pop(int &dataout)
{ 
    bool success;
    if(isempty())
      {
       success=false;
      }
    else
      {
      dataout=st[top];
      top--;
      success=true;
      }
    return success;
}

bool stack::stacktop(int &stop)
{
     bool success;
     if(isempty())
      {
     success=false;
      }
     else
      {
     stop=st[top];
     success=true;
      }
   return success;
}
void stack::display()
{
     if(isempty())
       {
        cout<<"stack is empty";
       }
     else
       {
         for(int i=top;i>=0;i--)
          {
         cout<<"\n"<<st[i]<<"\n";
          }
       }
}
int main()
{
stack s;
int datain,dataout,stop,ch;
while(1)
{
   cout<<"1.push\n 2.pop\n 3.stacktop\n  4.display\n 5.exit\n ";
   cout<<"enter your choice";
   cin>>ch;
   switch(ch)
   {
   case 1:cout<<"enter element to  push";
          cin>>datain;
          if(s.push(datain))
           {
          cout<<datain<<"element is pushed"<<"\n";                                                                                
           }
          break;
  case 2:if(s.pop(dataout))
          {
          cout<<"\n"<<"element is poped"<<"\n";
          }
         else
          {
         cout<<"element is not poped (stack is empty)";
          }
          break;
  case 3:if(s.stacktop(stop))
         {
         cout<<"element in top is"<<"\n";
         }
        else
         {
        cout<<"stack is empty";
         }
       break;
 case 4:s.display();
        break;
 case 5:exit(0);
 default:cout<<"invalid choice";
    }
}
return 0;
} 
        
