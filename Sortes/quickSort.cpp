#include <iostream>
#include <cmath>

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

int lomotopatrition(int arr[], int first, int last) {
	int pivot = arr[first];
	int j = first;
	for(int i = first + 1; i <= last; i++) {
		if(arr[i] <= pivot) {
			j++;
			swap(arr, j, i);
		}
	}
	swap(arr, first, j);
	return j;
}

int hoarepatrition(int arr[], int first, int last) {
	int mid = (first+last) / 2;
	if(arr[first] > arr[mid]) {
		swap(arr, first, mid);
	}
	if(arr[first] > arr[last]) {
		swap(arr, first, last);
	}
	if(arr[mid] > arr[last]) {
		swap(arr, mid, last);
	}
	int pivot = arr[mid];
	
	int i = first;
	int j = last;
	while(true) {
		while(arr[i] < pivot) {
			i++;
		}
		while(arr[j] > pivot) {
			j--;
		}
		if(i >= j) {
			return j;
		}
		swap(arr, i, j);
	}
}

void quickSort(int arr[], int first, int last) {
	if(last > first) {
		int pat = hoarepatrition(arr, first, last);
		quickSort(arr, first, pat);
		quickSort(arr, pat + 1, last);
	}
}


int main() {
	int arr[10] = { 16, 1, 3, 2, 4, 9, 10, 14, 8, 7 };
	quickSort(arr, 0, 9);
	print(arr, 10);
	return 0;
}