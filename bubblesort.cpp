#include<iostream>
using namespace std;
class sort
{
int a[100],n;
public:
void get();
void sorting();
void put();
};
void sort::get()
{
    cout<<"enter valueof n";
    cin>>n;
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
     cin>>a[i];
    }
} 
void sort::sorting()
{  
  int i,j,temp;  
  for(i=0;i<n-1;i++)
  {
   for(j=0;j<n-1-i;j++)
     {
     if(a[j]>a[j+1])
       {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
       }
     }
  }
}
void sort::put()
{
    cout<<"array elements after sorting";
    for(int i=0;i<n;i++)
    {
    cout<<a[i];
    }
}
int main()
{
sort s;
s.get();
s.sorting();
s.put();
return 0;
}

