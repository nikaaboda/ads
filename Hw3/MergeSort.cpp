#include <iostream>

using namespace std;

int* mergeSort(int arr, int size);

int main()
{
	return 0;
}

int* mergeSort(int arr, int size)
{
	for(int i = 0; i < size; i+=2)
	{
		if(arr[i] > arr[i+1])
		{
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	for(int i = 0)
}