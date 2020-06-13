#include<iostream>
using namespace std;
void printmat(int mat[20][20],int n)
{
int i,j;
cout<<"\n";
for(i=0;i<n;i++)
cout<<""<<i+1<<"";
cout<<"\n";
for(i=0;i<n;i++)
{
  cout<<""<<i+1<<"";
  for(j=0;j<n;j++)
  {
   cout<<mat[i][j];
  }
  cout<<"\n";
}

}
int main()
{
int i,j,v;
cout<<"enter number of vertices";
cin>>v;
int mat[20][20];
for(i=0;i<v;i++)
{
for(j=i;j<v;j++)
{
if(i!=j)
{
cout<<"enter 1 if vertex "<<i+1<<"is adjacent to"<<j+1<<"otherwise 0";
cin>>mat[i][j];
mat[j][i]=mat[i][j];
}
else
mat[i][j]=0;
}
}
printmat(mat,v);
return 0;
}
