#include<iostream>
using namespace std;

void hashinsert(int *arr,int size,int ele)
{
	int n=0;
	int position=ele % size;
	while(arr[position]!=INT_MIN && n!=size)
	{
		position=(position+1)% size;
		n++;
	}
	if(n!=size)
	{
		arr[position]=ele;
	}
	else
	{
		cout<<"Table is full.Cannot insert values.\n";
	}
}
void display(int arr[],int size)
{
	cout<<"Index\tValue\n";
	for(int i=0;i<size;i++)
	{
		cout<<i<<"\t"<<arr[i]<<endl;
	}
}
int main()
{
	int size,choice,ele;
	cout<<"enter size of hash table:";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=INT_MIN;
	}
	while(1)
	{
		cout<<"enter choice\n1.Insert\n2.Display\n3.Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter value to insert:";
				cin>>ele;
				hashinsert(arr,size,ele);
				break;
			case 2:
				display(arr,size);
				break;
			case 3:
				exit(0);
				break;
			default:
				cout<<"enter correct choice\n";
				
		}
	}
	return 0;	
}
