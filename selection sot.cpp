#include<iostream>
using namespace std;
class selectionsort
{
	public:
		int a[20],n,i,j,temp,small;
void array()
{
   cout<<"enter array size:";
   cin>>n;
   cout<<"enter array elements: ";
   for(i=0;i<n;i++)
   {
   	  cin>>a[i];
   }	
}
void sort()
{
	for(i=0; i<n-1; i++)
    {
        
        small = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[small])
            {
                small = j;
            }
        }
        if(a[i]>a[small])
        {
        	temp=a[i];
        	a[i]=a[small];
        	a[small]=temp;
		}
    }
}
void display()
{
	cout<<"sorted array using selection sort: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
};
int main()
{
	selectionsort s;
	s.array();
	s.sort();
	s.display();
}

