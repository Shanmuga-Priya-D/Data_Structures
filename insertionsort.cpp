#include<iostream>
using namespace std;

class sort
{
public:
void sorting(int a[],int n);
void display(int a[],int n);
};
void sort::sorting(int a[],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
key=a[i];
j=i-1;
while((j>=0)&&(a[j]>key))
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=key;
}
}
void sort::display(int a[],int n)
{
cout<<"array elements after sorting";
for(int i=0;i<n;i++)
{
cout<<"\n"<<a[i]<<"\n";
}
}
int main()
{
int n,a[30];
cout<<"enter n";
cin>>n;
cout<<"enter array elements ";
for(int i=0;i<n;i++)
{
cin>>a[i];
}
sort s;
s.sorting(a,n);
s.display(a,n);
return 0;
}
