#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high, int size)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[size];

    while (i <= mid && j <= high) 
	{
        if (arr[i] <= arr[j]) 
		{
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }


    for (int i = low; i <= high; i++) 
	{
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int low, int high, int size)
{
    if (low < high) 
	{
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, size);
        mergeSort(arr, mid + 1, high, size);
        merge(arr, low, mid, high, size);
    }
}
int main()
{
	int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int a[size];
    cout << "Enter " << size << " elements to the array: " << endl;
    for (int i = 0; i < size; i++) 
	{
        cin >> a[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++) 
	{
        cout << a[i] << " ";
    }
    cout << endl;
    mergeSort(a, 0, (size - 1), size); 

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) 
	{
        cout << a[i] << " ";
    }

    return 0;
}
