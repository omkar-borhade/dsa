

 #include<iostream>
#include<stdlib.h>

using namespace std;


struct tree                                             
{
	char data;
	struct tree *left,*right;
        tree(char c)
	{
	        data=c;
	        left=right=NULL;
	}
};

class stack                          
{
         tree *stk[20];
         int top;
        public:
                  stack()             
                  {
                        top=-1;
                  }

                 int isempty();
                 int isfull();
                 void push(tree*);
                 tree* pop();
 };

int stack::isempty()      
{
        if(top==-1)
	return 1;
        return 0;
}

int stack::isfull()          
{
        if(top==19)
        return 1;
	return 0;
 }

void stack::push(tree *d)  
{
     if(!isfull())
     {
        stk[++top]=d;
      }
}

tree* stack::pop()            
{
        tree *temp=stk[top];
	top--;
	return temp;
}

tree *create()                
{
	char str[25];
	int i=0;
	stack s;                       
	cout<<"\nEnter the postfix expression = ";
	cin>>str;
	while(str[i]!='\0')
	   {
		tree *node=new tree(str[i]);
		if(isalnum(str[i]))
		{
	                       s.push(node);
		}
		else
		{
		     node->right=s.pop();
		     node->left=s.pop();
		     s.push(node);
		}
	         i++;
                      }
	return s.pop();
}

void in_trav(tree *temp)                 
{
        if(temp!=NULL)
        {

                in_trav(temp->left);
                cout<<temp->data;
                in_trav(temp->right);
         }
}
void pre_trav(tree *temp)              
{
	if(temp!=NULL)
	{
		cout<<temp->data;
		pre_trav(temp->left);
		pre_trav(temp->right);
	}
}

void post_trav(tree *temp)             
{
	if(temp!=NULL)
	{
		post_trav(temp->left);
		post_trav(temp->right);
		cout<<temp->data;
	}
}
void nr_inorder(tree *temp)          
{
   stack s;

   while(temp!=NULL)
   {
          s.push(temp);
          temp=temp->left;
   }
   while(!s.isempty())
   {
          temp=s.pop();
          cout<<temp->data;
          temp=temp->right;
              while(temp!=NULL)
              {
                  s.push(temp);
                  temp=temp->left;
              }
    }
 }

 void nr_preorder(tree *temp)        
 {
       stack s;

           while(temp!=NULL)
          {
                  cout<<temp->data;
                  s.push(temp);
                  temp=temp->left;
           }
          while(!s.isempty())
          {
                 temp=s.pop();
                 temp=temp->right;
                   while(temp!=NULL)
                   {
                       cout<<temp->data;
                       s.push(temp);
                       temp=temp->left;
                   }
            }
 }

  void nr_postorder(tree *temp)                
  {
              stack s,s1;
              while(temp!=NULL)
             {
                  s.push(temp);
                  s1.push(NULL);
                  temp=temp->left;
              }
             while(!s.isempty())             
             {
                  temp=s.pop();
                  if(s1.pop()==NULL)
                 {
                       s.push(temp);
                       s1.push((tree*)1);
                       temp=temp->right;

                      while(temp!=NULL)
                     {
                         s.push(temp);
                         s1.push(NULL);
                         temp=temp->left;
                      }
                 }
                else
             {
                     cout<<temp->data;
              }
             }
   }
  int main()
    {
	struct tree *root=NULL;
	int choice;

         do
          {
	cout<<"\n\nMENU";
	cout<<"\n1.create expression tree\n2.Preorder recursive\n3.Inorder recursive\n4.Postorder recursive\n5.Preorder non-recursive\n6.Inorder non-recursive\n7.Postorder non-recursive\n";
	cout<<"\nEnter your choice=";

	cin>>choice;
	switch(choice)
  	{
              	case 1:
			root=create();
		 	break;

		case 2:
			cout<<"\nPreorde expression(recursive) = ";
			pre_trav(root);                      
		 	break;

            	case 3:
			cout<<"\n Inorder expression(recursive) = ";
		 	in_trav(root);                        
		 	break;

	       case 4:
			cout<<"\n Postorder expression(recursive) = ";
			post_trav(root);                    
		 	break;

 	       case 5:
			cout<<"\n preorder expression(non-recursive) = ";
			nr_preorder(root);                 
		 	break;

            	case 6:
			cout<<"\n Inorder expression(recursive) = ";
		 	nr_inorder(root);                    
		 	break;

	       case 7:
			cout<<"\n Postorder expression(non-recursive) = ";
		 	nr_postorder(root);
		 	break;
	}

	         }while(choice<=7);


}


