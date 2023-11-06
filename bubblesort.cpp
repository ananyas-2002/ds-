#include<iostream>
using namespace std;
class bubble
{
	int n,i,j,temp,a[30];
	public:
void declarearray()
{
    cout<<"enter array size: ";
	cin>>n;
	cout<<"enter array elements: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void bubblesorting()
{
	cout<<endl<<"sorting the array using bubble sort:"<<endl;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}		
		}
	}
}
void printarray()
{
	cout<<"sorted array: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
};
int main()
{
	bubble b;
	b.declarearray();
	b.bubblesorting();
	b.printarray();
	return 0;
}
