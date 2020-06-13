/*Q1: Create a Binary Search Tree that contains the r
ecords of the students of II
Year IT ‘A’ Section having information like reg. no.,
 name of the student, Number
of Arrears and CGPA. The BST has to be arranged base
d on the student’s CGPA.
Print the following information by traversing the BST
:
i.
All students’ records in increasing order of CGPA
ii.
The students’ records who have obtained CGPA >= 8.0
iii.
The students’ records who have obtained 6.0 <= CGPA
 <= 8.0
iv.
The reg. no. and name of the students who have more
than 3 arrears
but less than or equal to 5 arrears.
v.
The reg. no. and name of the students who have more
than 5 arrears*/

#include<iostream>
using namespace std;
struct node
{
int regno;
string name;
int no_arrears;
float cgpa;
node* left;
node* right;
};
class bst
{
public:
node* create(int reg,string na,int no,float cg)
{
node *pnew=new node;
pnew->regno=reg;
pnew->name=na;
pnew->no_arrears=no;
pnew->cgpa=cg;
pnew->left=NULL;
pnew->right=NULL;
return pnew;
}
node* insert(node* r,int reg,string na,int no,float cg)
{
if(r==NULL)
return create(reg,na,no,cg);
else if(cg>r->cgpa)
r->right=insert(r->right,reg,na,no,cg);
else if(cg<r->cgpa)
r->left=insert(r->left,reg,na,no,cg);
return r;
}
/*bool search(node* r,int key)
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

}*/
void inorder(node *r)//JUZT INORDER TRAVERSAL BCOZ INORDER TRAVERSAL WILL PROVIDE ASCENDING ORDER
{
if(r==NULL)
return;
inorder(r->left);
cout<<r->regno<<"  "<<r->name<<"  "<<r->no_arrears<<"  "<<r->cgpa<<" || ";
inorder(r->right);
}
void in1(node *r)
{
if(r==NULL)
return;
if((r->cgpa)>=8.0)
{
inorder(r->left);
cout<<r->regno<<"   "<<r->name<<"  "<<r->no_arrears<<"  "<<r->cgpa<<" || ";
inorder(r->right);
}
}

void in2(node *r)
{
if(r==NULL)
return;
inorder(r->left);
if(((r->cgpa)>=6.0)&&((r->cgpa)<=8.0))
{
cout<<r->regno<<"   "<<r->name<<"  "<<r->no_arrears<<"  "<<r->cgpa<<" || ";
}
inorder(r->right);
}


};
int main()
{
int ch;
bst b;
int reg;
string na;
int no;
float cg;
node* rr=NULL;
do
{
cout<<" 1.INSERT || 2.ALL RECORDS INCREASING ORDER OF CGPA|| 3.CGPA GREATER THAN 8|| 4.CGPA GREATER THAN 6 BUT LESS THAN 8 ||5.MORE THAN 3 AREARS BUT LESS THAN OR EQUAL TO 5 AREARS ||6.MORE THAN 5 ARREARS ||7.EXIT CHOICE:";
cin>>ch;
switch(ch)
{
case 1:cout<<"enter regno,name,no of arrears,cgpa";
cin>>reg>>na>>no>>cg;
rr=b.insert(rr,reg,na,no,cg);
break;
case 2:
b.inorder(rr);
break;
case 3:
b.in1(rr);
break;
case 4:
b.in2(rr);
break;

/*case 2:
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
break;*/
/*case 9:break;
case 7:b.largest(rr);
break;
case 8:b.smallest(rr);
break;*/
default:cout<<"\n WRONG CHOICE:";
}
}while(ch!=9);
}

	

