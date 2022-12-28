#include<iostream>
#include<string.h>
#include<math.h>


using namespace std;

class bst
{
        public:
                int data;
                bst *right,*left,*root;

                bst *create(bst *root,int x);

        	void display(bst *root);
       		void search(bst *root,int x);
      		bst *del(bst *root,int x);
       		bst *mirror(bst *root);
       		int height(bst *T);
       		void  leaf(bst *root);
       		bst *copy(bst *root);
};

bst *bst::create(bst *root,int x)
{

        bst *temp,*nn;

        nn=new bst;
        nn->data=x;
        nn->right=NULL;
        nn->left=NULL;

        if(root==NULL)
        {
                root=nn;
                cout<<"\nRoot node added..!!";

        }
	else
	{
	        temp=root;
                if(temp->data>nn->data)
                {
                        if(temp->left!=NULL)
                        {
                                create(temp->left,nn->data);
                        }
                        else
                        {
                                temp->left=nn;
                                temp->left->left=NULL;
                                temp->left->right=NULL;
                                cout<<"\nLeft node added..!!";
                        }
                }
                else
                {
                        if(temp->right!=NULL)
                        {
                                create(temp->right,nn->data);
                        }
                         else
                        {
                                temp->right=nn;
                                temp->right->left=NULL;
                                temp->right->right=NULL;
                                cout<<"\nRight node added..!!";
                        }

                }
}
 return root;

}


void bst::display(bst *root)
{
        if(root!=NULL)
        {
                display(root->left);
                cout<<" "<<root->data;
                display(root->right);

        }
}

void bst::search(bst *root,int x)
{
        bst *temp=root;
        int flag=0;
        while(temp!=NULL)
        {
                if(x==temp->data)
                {
                        flag=1;
                        break;
                }
                else
                {
                        if(x<temp->data)
                        temp=temp->left;
                        else
                        temp=temp->right;
                }
        }
        if(flag==1)
        cout<<"\n Data found";
        else
        cout<<"\n Data not found";
}
int bst::height(bst *T)
{
	int hl,hr;
	if(T==NULL)
	return 0;
	if(T->left==NULL && T->right==NULL)
	return 0;
	hl=height(T->left);
	hr=height(T->right);
	if(hl>hr)
	return 1+hl;
	else
	return 1+hr;

}

bst *bst::del(bst *temp,int x)
{
        bst *t;
        if(temp==NULL)
        {
                cout<<"\n element not found";
                return(temp);
        }
        if(x<temp->data)
        {
                temp->left=del(temp->left,x);
                return(temp);
        }
        if(x>temp->data)
        {
                temp->right=del(temp->right,x);
                return(temp);
        }
         if(temp->left==NULL && temp->right==NULL)
        {
                t=temp;
                delete(t);
                return(0);
        }
        if(temp->left==NULL)
        {
                t=temp;
                temp=temp->right;
                delete t;
                return(temp);
        }
        if(temp->right==NULL)
        {
                t=temp;
                temp=temp->left;
                delete t;
                return(temp);
        }
        t=temp->right;
        while(t->left!=NULL)
        {
        t=t->left;
        }
        temp->data=t->data;
        temp->right=del(temp->right,t->data);
        return(temp);

}

bst *bst::mirror(bst *root)
{
        bst *p;
        p=NULL;
        if(root!=NULL)
        {
                p=new bst;
                p->data=root->data;
                p->left=mirror(root->right);
                p->right=mirror(root->left);
        }
        return p;
}

void bst:: leaf(bst *root)
{

	if(root==NULL)
	return ;
	if(root->left==NULL && root->right==NULL)
	{	cout<<"\t"<<root->data;
			}
  leaf(root->left);
  leaf(root->right);

}

bst *bst::copy(bst *root)
 {
 	bst *P;
 	P=NULL;
 	if(root!=NULL)
 	{
 		P=new bst();
 		P->data=root->data;
 		P->left=copy(root->left);
 		P->right=copy(root->right);
 	}
 	return P;
 }



int main()
{
    bst b,*root=NULL,*t1;
    bst *p;
    int ch,x1,d,z,i;
    char ans,ans1;
    do
    {
        cout<<"\n1]Create\n2]Display\n3]Search\n4]Delete\n5]Mirror\n6]Height\n7]Print Leaf Nodes\n8] Copy tree";
        cout<<"\nEnter your choice :";
        cin>>ch;

           switch(ch)
        {
            case 1: do
                    {
                        cout<<"\nEnter the data :";
                        cin>>x1;
                        root=b.create(root,x1);
                        cout<<"\nDo you want to enter more data(y/n):";
                        cin>>ans1;
                    }while(ans1=='y' || ans=='Y');
                        break;

            case 2: cout<<"\nTHE INORDER TRAVERSAL IS:";
                    b.display(root);
                    break;

            case 3: cout<<"\nEnter the data you want to search :";
                    cin>>d;
                    b.search(root,d);
                    break;

            case 4: cout<<"\nEnter the data you want to delete :";
                    cin>>z;
                    t1=b.del(root,z);
                    cout<<"\nThe data "<<z<<" has been Deleted ";
                    break;
            case 5:
                 p=b.mirror(root);
                 cout<<"\n The mirror tree is:";
                 b.display(p);
                 break;

            case 6:  i=b.height(root);
                        cout<<"Height of tree is="<<i;
                        break;

            case 7: cout<<"\n Leaf nodes are: ";
                    b.leaf(root);

            case 8: p=b.copy(root);
                    b.display(p);
                    break;

                default :
                                cout<<"\nWRONG CHOICE..";
                                break;
         }

        cout<<"\n\nDo you want to continue(y/n):";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
}


