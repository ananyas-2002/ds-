#include<iostream>
using namespace std;
void minheapify(int arr[],int n,int i)
{
	int smallest=i;
	int left_child=2*i;
	int right_child=2*i+1;
	if(left_child<=n && arr[left_child]<arr[smallest])
	smallest=left_child;
	
	if(right_child<=n && arr[right_child]<arr[smallest])
	smallest=right_child;
	
	if(smallest!=i)
	{
     	swap(arr[i],arr[smallest]);
    	minheapify(arr,n,smallest);
    }
}
void printarray(int arr[],int n)
{
	for (int i = 1; i <=n; ++i)
		{
	     	cout << arr[i] << " ";
	    }
}
void heapsort(int arr[],int n)
{
	 for (int i = n / 2 ; i >0; i--)
	 {
        minheapify(arr, n, i);
     }
 
	for(int i=n;i>0;i--)
	{
		swap(arr[1],arr[i]);
		minheapify(arr,i-1,1);
	}
}
int main()
{
	int n,i;
	cout<<"enter size of the array:";
	cin>>n;
	int arr[n];
//	int *arr=new int(n+1);
//	arr[0]=0;
	cout<<"enter array elements:";
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
    }	
    cout<<"original array:";
    for(int i=1;i<=n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		for(int i=n/2;i>0;i--)
		{
         	minheapify(arr,n,i);
        }
		cout<<"After heapifying array(min heap):";
		printarray(arr,n);
		heapsort(arr,n);
		cout << "Sorted array is:"<<" ";
	    printarray(arr,n);
//	    delete[] arr;
}
