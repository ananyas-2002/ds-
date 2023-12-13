#include<bits/stdc++.h>
using namespace std;
bool flag = 0;
void PrintSubsetSum(int i, int n, vector<int>&arr, int targetSum,vector<int>& subsetarr)
{
	if (targetSum == 0) 
	{
		flag = 1;
		cout << "[ ";
		for (int i = 0; i < subsetarr.size(); i++) 
		{
			cout << subsetarr[i] << " ";
		}
		cout << "]";
		cout<<endl;
		return;
	}

	if (i == n) 
	{
		return;
	}
	PrintSubsetSum(i + 1, n,arr,targetSum,subsetarr);
	if (arr[i] <= targetSum) 
	{

		subsetarr.push_back(arr[i]);
		PrintSubsetSum(i + 1, n, arr, targetSum - arr[i],subsetarr);
		subsetarr.pop_back();
	}
}
int main()
{
	int n,data,sum;
	vector<int> arr, subsetarr;
	cout<<"enter number of elements:";
	cin>>n;
	cout<<"enter elements:";
	for(int i=0;i<n;i++)
	{
		cin>>data;
		arr.push_back(data);
	}
	cout<<"enter sum:";
	cin>>sum;
	cout<<"Subset:";
	cout<<endl;
	PrintSubsetSum(0, n, arr, sum, subsetarr);
	if(!flag)
	{
		cout<<"there is no solution*";
	}
	return 0;
}

