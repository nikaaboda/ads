//(a)
#include <iostream>

using namespace std;

int* selectSort(int* arr, int size);

int main()
{
	int arr[10];
	for(int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	selectSort(arr, 10);
	for(int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

int* selectSort(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		int temp = arr[i];
		int min = arr[i];
		int index = i;
		for(int j = i + 1; j < size; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		arr[index] = temp;
		arr[i] = min;
	}
	return arr;
}
//(b)
// Proof:
/* 
Loop invariant: at the start of every iteration i, arr[0 to i-1] contains sorted i smallest array elements

initialization: at the start of first iteration, arr[0 to i-1] is an empty array thus it is sorted

maintence: assume arr[0 to i-1] was sorted i smallest elements at the start of iteration i. During iteration i,
the smallest element in subarray arr[i to last] will get pushed to arr[0 to i-1], thus at the start of iteration
i+1 we will have arr[0 to i] with i+1 sorted smallest array elements.

termination: after for loop terminates i = size, we will have {size} smallest elements in the arr[0 to size - 1]
which is the output that we want algorithm to give, thus algorithm is correct
*/
//(c)
//Case A: 
//Case B: it's obvios that case with least swaps would be already sorted array so
/*
i = 0;
While(i < n) 
{
	arr[i] = i;
	i++;
}
*/