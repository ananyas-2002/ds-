#include<iostream>
using namespace std;
struct node
{
	int data;
	node*link;
};
node*tmp;
node*t;
class linkedlist
{
	node*head;
	public:
		linkedlist()
		{
			head=NULL;
		}
	void addbegging(int n)
	{
	     tmp=new node;
		tmp->data=n;
		tmp->link=NULL;
		if(head==NULL)
		{
			head=tmp;
		}
		else
		{
			tmp->link=head;
			head=tmp;
		}
		if(head==NULL)
		{
			cout<<"linkedlist empty"<<endl;
		}
		else
		{
		    	t=head;
		    	cout<<"list elements are:\n";
		    	while(t!=NULL)
		    	{
		    		cout<<t->data<<"->";
		    		t=t->link;
				}
		}
	}
	void addend(int m)
	{
		node*current=head;
	    tmp=new node;
		tmp->data=m;
		tmp->link=NULL;
		if(head==NULL)
		{
			head=tmp;
		}
		else
		{
			while(current->link!=NULL)
			{
				current=current->link;
			}
			current->link=tmp;
		}
		if(head==NULL)
		{
			cout<<"linkedlist empty"<<endl;
		}
		else
		{
		    	t=head;
		    	cout<<"list elements are:\n";
		    	while(t!=NULL)
		    	{
		    		cout<<t->data<<"->";
		    		t=t->link;
				}
		}
	}
	void adddesiredlocation(int n,int pos)
	{
		tmp=new node;
		tmp->data=n;
		tmp->link=NULL;
		if(head==NULL)
		{
			head=tmp;
		}
		else
		{
			int i=1;
			t=head;
			while(i!=pos&&t!=NULL)
			{
				t=t->link;
				i++;
			}
			if(t==NULL)
			{
				cout<<"position not found:"<<endl;
			}
			else
			{
			    tmp->link=t->link;
		     	t->link=tmp;
		    }
		}
		if(head==NULL)
		{
			cout<<"linkedlist empty"<<endl;
		}
		else
		{
		    	t=head;
		    	cout<<"list elements are:\n";
		    	while(t!=NULL)
		    	{
		    		cout<<t->data<<"->";
		    		t=t->link;
				}
		}
	}
	void deletebegging()
	{
		t=head;
		if(t->link==NULL)
		{
			head=NULL;
		}
		head=t->link;
		delete t;
		if(head==NULL)
		{
			cout<<"linkedlist empty"<<endl;
		}
		else
		{
		    	t=head;
		    	cout<<"\nlist of elements after deleting from begging:\n";
		    	while(t!=NULL)
		    	{
		    		cout<<t->data<<"->";
		    		t=t->link;
				}
		}
	}
	void deleteend()
	{
		t=head;
		node*p=NULL;
		if(t->link==NULL)
		{
			cout<<"linked list is empty"<<endl;
		}
		while(t->link!=NULL)
		{
			p=t;
			t=t->link;
		}
		p->link=NULL;
		delete t;
		t=head;
		if(head==NULL)
		{
			cout<<"linkedlist empty"<<endl;
		}
		else
		{
		    cout<<"list elements are:\n";
		    while(t!=NULL)
		    {
		    	cout<<t->data<<"->";
		    	t=t->link;
			}
		}
	}
	void deleteatspecifiedlocation(int pos)
	{
		t=head;
		node*p=NULL;
		if(t->link==NULL)
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
			t=t->link;
			i++;
		}
		p->link=t->link;
		delete t;
	   }
		if(head==NULL)
		{
			cout<<"linkedlist empty"<<endl;
		}
		else
		{
		    t=head;
		    cout<<"\nlist elements are:\n";
		    while(t!=NULL)
		    {
		    	cout<<t->data<<"->";
		    	t=t->link;
			}
		}
	}
};
int main()
{
	linkedlist l;
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
			case 1: cout<<"enter value at begging:"<<endl;
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
		    case 7:return 0;
		}	
	}while(ch!=7);
	return 0;
}

