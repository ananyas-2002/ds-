#include<iostream>
using namespace std;
struct node
{
	int data;
	node*Llink;
	node*Rlink;
};
node*tmp;
node*t;
class doublylinkedlist
{
	node*head;
	public:
		doublylinkedlist()
		{
			head=NULL;
		}
		node*createnode(int a)
		{
			node*m=new node;
			m->data=a;
			m->Llink=NULL;
			m->Rlink=NULL;
			return m;
		}
		void addbegging(int n)
		{
			tmp=new node;
			tmp->data=n;
			tmp->Llink=NULL;
			tmp->Rlink=NULL;
			if(head==NULL)
			{
				head=tmp;
			}
			else
			{
				tmp->Rlink=head;
				head->Llink=tmp;
				head=tmp;
			}
			display();
		}
		void addend(int n)
		{
			node*current=head;
	        tmp=new node;
	     	tmp->data=n;
	     	tmp->Llink=NULL;
	     	tmp->Rlink=NULL;
	    	if(head==NULL)
		    {
	 	     	head=tmp;
	     	}
	    	else
	     	{
		     	while(current->Rlink!=NULL)
		    	{
			    	current=current->Rlink;
		    	}
		    	current->Rlink=tmp;
		    	tmp->Llink=current;
	     	}
	     	display();
    	}
	   	void adddesiredlocation(int n,int pos)
	    {
	     	tmp=new node;
	    	tmp->data=n;
	     	tmp->Llink=NULL;
	     	tmp->Rlink=NULL;
	    	if(head==NULL)
	     	{
		    	head=tmp;
	    	}
	    	else
	    	{
		    	int i=0;
		    	t=head;
		    	while(i!=pos&&t->Rlink!=NULL)
		    	{
			    	t=t->Rlink;
			    	i++;
		    	}
		    	if(t->Rlink==NULL)
		    	{
			    	cout<<"position not found:"<<endl;
		     	}
		     	else
		     	{
		     	   node*flag=t->Rlink;
		     	   t->Rlink=tmp;
			       tmp->Llink=t;
		           tmp->Rlink=flag;
		           flag->Llink=tmp;
		       }
	    	}
	    	display();
	    }
	void deletebegging()
	{
		t=head;
		if(t->Llink==NULL&&t->Rlink==NULL)
		{
			head=NULL;
			delete t;
		}
		t->Rlink->Llink=NULL;
		head=t->Rlink;
		delete t;
	   display();
	}
	void deleteend()
	{
		t=head;
		node*p=NULL;
		if(t==NULL)
		{
			cout<<"linked list is empty"<<endl;
		}
		while(t->Rlink!=NULL)
		{
			p=t;
			t=t->Rlink;
		}
		p->Rlink=NULL;
		delete t;
		display();
	}
void deleteatspecifiedlocation(int pos)
	{
		t=head;
		node*p=NULL;
		if(t==NULL)
		{		
	    	cout<<"list is empty after deleteing from desired location:"<<endl;
		}
		else if(pos==1)
		{
			deletebegging();
    	}
		else
		{
	    	int i=1;
	    	while(i!=pos)
	    	{
		    	p=t;
		    	t=t->Rlink;
		     	i++;
	    	}
	    	if(t==NULL)
	    	{
	    		cout<<"position not found"<<endl;
			}
		    t->Rlink->Llink=p;
		    p->Rlink=t->Rlink;
	    	delete t;
	        display();
        }
	}
	    void display()
		{
			if(head==NULL)
			{
				cout<<"doubly linked list is empty:"<<endl;
			}
			else
			{
				t=head;
				cout<<"doubly linked list elements are:";
				while(t!=NULL)
				{
					cout<<t->data<<"->";
					t=t->Rlink;
				}
				
			}
		}
};
int main()
{
	doublylinkedlist l;
	int ch;
	int n,m,pos;
	do
	{
		cout<<"\nselect choice:"<<endl;
		cout<<"1.insert at begging:"<<endl;
		cout<<"2.insert at end:"<<endl;
	    cout<<"3.insert at desired location:"<<endl;
		cout<<"4.delete from begging:"<<endl;
	    cout<<"5.delete from end:"<<endl;
		cout<<"6.delete from desired location:"<<endl;
		cout<<"7.exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:  cout<<"enter value at begging:"<<endl;
			          cin>>n;
			          l.addbegging(n);
			          break;
			case 2: cout<<"enter value at end"<<endl;
		              cin>>m;
		             l.addend(m);
		              break;
		   case 3:cout<<"enter value to be inserted at desired location:"<<endl;
		            cin>>n;
		            cout<<"enter position:"<<endl;
		             cin>>pos;
		             l.adddesiredlocation(n,pos);
		             break;
		   case 4: l.deletebegging();
		             break;
		    case 5: l.deleteend();
		             break;
		  case 6: cout<<"enter position to be deleted:"<<endl;
		           cin>>pos;
		             l.deleteatspecifiedlocation(pos);
		             break;
		    case 7:  cout<<"invalid choice"<<endl;
		           return 0;
		}
	}while(ch!=7);
	return 0;
}

