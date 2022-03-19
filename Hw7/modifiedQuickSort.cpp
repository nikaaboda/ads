#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

tuple<int, int> patrition(int arr[], int first, int last) {
	int pivot1 = arr[first];
	int pivot2 = arr[first + 1];
	int large = pivot2 >= pivot1 ? pivot2 : pivot1;
	int small = pivot1 <= pivot2 ? pivot1 : pivot2;
	if(pivot2 == small) {
		swap(arr, first, first + 1);
	}

	int j = first;
	int k = j + 1;
	for(int i = k + 1; i <= last; i++) {
		if(arr[i] <= small) {
			j++;
			swap(arr, j, i);
		} else if(arr[i] <= large) {
			k++;
			swap(arr, k, i);
		}
	}
	swap(arr, first + 1, k);
	return {j, k};
	//	int arr[10] = { 16, 1, 3, 2, 4, 9, 10, 14, 8, 7 };
}


void quickSort(int arr[], int first, int last) {
	if(last > first) {
		auto [piv1, piv2] = patrition(arr, first, last);
		quickSort(arr, first, piv1);
		quickSort(arr, piv1 + 1, piv2);
		quickSort(arr, piv2 + 1, last);
	}
}


int main() {
	int arr[10] = { 16, 1, 3, 2, 4, 9, 10, 14, 8, 7 };
	quickSort(arr, 0, 9);
	print(arr, 10);
	return 0;
}