#include<iostream>
using namespace std;
struct node
{
int data;
node* link;
};
node* head=NULL;
node* temp=NULL;
class linkedlist
{
public:
	node* head=NULL;
void insertnode()
{
int n;
cout<<"enter nodes: ";
cin>>n;
for(int i=0;i<n;i++)
{
node* newnode=new node;
cout<<"enter data of node "<<i+1<<":";
cin>>newnode->data;
newnode->link=NULL;
if(head==NULL)
{
        head=temp=newnode;
    }
    else
    {
    temp->link=newnode;
    temp=newnode;
}
  }
}
void search()
{
int x;
cout<<"enter serach element: ";
cin>>x;
node* temp=head;
int found=0;
int i=0;
if(temp!=NULL)
{
while(temp!=NULL)
{
      i++;
      if(temp->data==x)
      {
    found++;
    break;
    }
    temp=temp->link;
    }
      if(found==1)
      {
    cout<<x<<' '<<"found at index= "<<i<<endl;
    }
    else
    {
   cout<<x<<"not found "<<endl;
    }
   }
   else
   {
    cout<<"list empty"<<endl;
   }
}

void display()
{
      temp=head;
    while(temp!=NULL)
    {
    cout<<temp->data<<"-->";
    temp=temp->link;
   }
   cout<<endl;

}
void splitelement()
{
int key;
cout<<"enter key value: ";
cin>>key;
if(head==NULL)
{
cout<<"list is empty";
}
    node* current = head;
    node* prev = NULL;
        while (current!=NULL)
        {
           if (current->data == key)
            {
               break;
            }
        prev = current;
        current = current->link;
        }

    if (current == NULL)
   {
        cout << key << " not found in the list" <<endl;
    }
else
{
        if (prev!=NULL)
        {
            prev->link = NULL;
        } 
		else 
		{
            head = NULL;
        }

        linkedlist secondLinkedList;
        secondLinkedList.head = current;
        cout << "First Linked List:" << endl;
        display();
        cout << "Second Linked List:" <<endl;
        secondLinkedList.display();
}

}
};
int main()
{
linkedlist l;
l.insertnode();
l.display();
l.search();
l.splitelement();

}

