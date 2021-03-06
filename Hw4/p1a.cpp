#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        key = arr[i];

        while(j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
 	int n1 = m - l + 1;
 	int n2 = r - m;
    // Create temp arrays
 	int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
 	for(int i = 0; i < n1; i++) 
 	{
 		L[i] = arr[l + i];
 	}

 	for(int j = 0; j < n2; j++)
 	{
 		R[j] = arr[m + 1 + j];
 	}
 
    // Merge the temp arrays back into arr[l..r]
 	int i = 0, j = 0, k = l;

 	while(i < n1 && j < n2)
 	{
 		if(L[i] <= R[j])
 		{
 			arr[k] = L[i];
 			i++;
 		} 
 		else 
 		{
 			arr[k] = R[j];
 			j++;
 		}
 		k++;
 	}
 
    // Copy the remaining elements of
    // L[] or R[], if there are any
 	while(i < n1)
 	{
 		arr[k] = L[i];
 		i++;
 		k++;
 	}

 	while(j < n2)
 	{
 		arr[k] = R[j];
 		j++;
 		k++;
 	}

}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r, int k){
    if(l>=r){
        return;//returns recursively
    }
    int m = l + (r-l)/2;
    if(m + 1 > k)
    {
        mergeSort(arr, l, m, k);
        mergeSort(arr, m+1, r, k);
    }
    else
    {
        insertionSort(arr, r + 1);
    }
    merge(arr, l, m, r);
}
 
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7, 15 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1, 2);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}