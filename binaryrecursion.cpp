#include<iostream>
using namespace std;
int binary(int l,int h,int s,int a[])
{
if(l==h)
{
   if(a[l]==s)
    {
     return l;
    }
   else
   {
    return 0;
   }
}
else
{
int mid=l+h/2;
  if(a[mid]==s)
    {
    return mid;
    }
  else if(s>a[mid])
   {
    return binary(mid+1,h,s,a);
   }
  else
   {
    return binary(l,mid-1,s,a);
   }
}

}
int main()
{
int a[100],n,key;
cout<<"enter n";
cin>>n;
cout<<"enter array elements";
for(int i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"enter search element";
cin>>key;
int low=0;
int high=n-1;
int pos=binary(low,high,key,a);
cout<<"element is found at position"<<pos;
return 0;
}



