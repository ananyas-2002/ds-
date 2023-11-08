#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[size];

    while (i <= m && j <= r) 
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
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }


    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}


void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r) 
	{
        int m = (l + r) / 2;
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);
        merge(arr, l, m, r, size);
    }
}

int main()
{
	int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int a[size];
    cout << "Enter " << size << " elements to the array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    mergeSort(a, 0, (size - 1), size); 

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
