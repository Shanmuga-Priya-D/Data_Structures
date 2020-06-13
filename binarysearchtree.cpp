#include<iostream>
using namespace std;
struct node
{
int data;
node* left;
node* right;
};
class bst
{
public:
node* create(int key)
{
node *pnew=new node;
pnew->data=key;
pnew->left=NULL;
pnew->right=NULL;
return pnew;
}
node* insert(node* r,int key)
{
if(r==NULL)
return create(key);
else if(key>r->data)
r->right=insert(r->right,key);
else if(key<r->data)
r->left=insert(r->left,key);
return r;
}
bool search(node* r,int key)
{
bool found;
if(r==NULL)
return false;
else if(key>r->data)
found=search(r->right,key);
else if(key<r->data)
found=search(r->left,key);
else
return true;
}
bool del(node* r,int key)
{
        node* delnode; node* lar;
        if(r==NULL)
        return false;
        if(key<r->data)
        return del(r->left,key);
        else if(key>r->data)
        return del(r->right,key);
        else
        {
                if(r->left==NULL)
                {
                        r=r->right;
                        return true;
                }
                else if(r->right==NULL)
                {
                        r=r->left;
                        return true;
                }
                else
                {
                        delnode=r;
                        lar=largest(r->left);
                        delnode->data=lar->data;
                        return del(delnode->left,lar->data);
                }

        }
}
void preorder(node *r)
{
if(r==NULL)
return;
cout<<r->data;
preorder(r->left);
preorder(r->right);
}
node* largest(node *r)
{
        if(r->right==NULL)
        cout<<"LARGEST:"<<r->data;
        else
        return largest(r->right);
}
node* smallest(node *r)
{
        if(r->left==NULL)
        cout<<"\n SMALLEST:"<<r->data;
        else
        return smallest(r->left);
}
void postorder(node *r)
{
if(r==NULL)
return;
postorder(r->left);
postorder(r->right);
cout<<r->data;

}
void inorder(node *r)
{
if(r==NULL)
return;
inorder(r->left);
cout<<r->data;
inorder(r->right);
}
};
int main()
{
int ch,no;
bst b;
node* rr=NULL;
do
{
cout<<" 1.INS 2.SRCH 3.DEL 4.PRE 5.POST 6.IN 7.LARGE 8.SMALL 9.EXIT CHOICE:";
cin>>ch;
switch(ch)
{
case 1:
cin>>no;
rr=b.insert(rr,no);
break;
case 2:
cin>>no;
if(b.search(rr,no))
cout<<"\n FOUND";
else
cout<<"\n NOT FOUND";
break;
case 3:
cin>>no;       
if(b.del(rr,no)==true)
cout<<"\n DEL SUCCESS";
break; 
case 4:
b.preorder(rr);
break;
case 5:
b.postorder(rr);
break;
case 6:
b.inorder(rr);
break;
case 9:break;
case 7:b.largest(rr);
break;
case 8:b.smallest(rr);
break;
default:cout<<"\n WRONG CHOICE:";
}
}while(ch!=9);
}

	

