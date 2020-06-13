#include<iostream>
using namespace std;
#include<string.h>
class stack
{
char s[10];
int top;
public:
stack()
{
top=-1;
}
void push(char x)
{
top++;
s[top]=x;
}
char pop()
{
return s[top--];
}
char peaktop()
{
if(top!=-1)
return s[top];
}
bool empty()
{
if(top==-1)
return true;
else
return false;
}
int priority(char c)
{
if(c=='+' || c=='-')
return 1;
else if(c=='*' || c=='/')
return 2;
else if(c=='(' || c==')')
return 0;
else
return -1;

}

};
class InfixToPostfix
{
char Infix[10];
char postfix[10];
stack s;
int pcount;
public:
InfixToPostfix()
{
pcount=0;
}
void getExpression()
{
cout<<"Enter your Expression : ";
cin>>Infix;
}

void Conversion()
{
int i;
for(i=0;i<Infix[i]!='\0';i++)
{
if(Infix[i]=='(')
s.push(Infix[i]);
else if(Infix[i]==')')
{
char c=s.pop();
while(c!='(')
{
postfix[pcount++]=c;
c=s.pop();
}
}
else if(Infix[i]=='+'|| Infix[i]=='-'|| Infix[i]=='*'|| Infix[i]=='/'|| Infix[i]=='^')
{
char k=s.peaktop();
while(s.empty() && (s.priority(Infix[i])<=s.priority(k)))
{
char t =s.pop();
postfix[pcount++]=t;
k=s.peaktop();

}
s.push(Infix[i]);
}
else
{
postfix[pcount++]=Infix[i];
}

}
while(s.empty()==false)
{
postfix[pcount++]=s.pop();
}
postfix[pcount]='\0';
}
void Display()
{
cout<<"Infix Expression :"<<Infix;
cout<<"\nPostFix Expression :"<<postfix;

}
};
int main()
{
InfixToPostfix itp;
itp.getExpression();
itp.Conversion();
itp.Display();
return 0;
}


