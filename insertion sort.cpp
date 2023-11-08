#include<iostream>
using namespace std;
void insertion(int a[],int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
	   while(j>=0&&a[j]>key)
     	{
	    	a[j+1]=a[j];
	    	j=j-1;
    	} 
    	a[j+1]=key;
   }
}
void print(int a[],int n)
{
	int i;
	cout<<"sorted array: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int num,i,a[30];
	cout<<"enter size of array: ";
	cin>>num;
	cout<<"enter elements to array:";
	for(i=0;i<num;i++)
	{
		cin>>a[i];
	}
	insertion(a,num);
	print(a,num);
}
