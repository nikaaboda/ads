#include <iostream>

using namespace std;

void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

void maxHeap(int arr[], int index, int heapsize, int length) {
	int l = index * 2 + 1;
	int r = index * 2 + 2;
	int largest = index;
	if(l < heapsize && arr[l] > arr[largest]) {
		largest = l;
	}

	if(r < heapsize && arr[r] > arr[largest]) {
		largest = r;
	}

	if (largest != index) {
		swap(arr, index, largest);
		maxHeap(arr, largest, heapsize, length);
	}
}

void buildMaxHeap(int arr[], int heapsize, int length) {
	for(int i = length/2 - 1; i >= 0; i--) {
		maxHeap(arr, i, heapsize, length);
	}
}

int pushdown(int arr[])

void heapSort(int arr[], int heapsize, int length) {
	buildMaxHeap(arr, heapsize, length);

	for(int i = heapsize-1; i >= 0; i--) {
		swap(arr, 0, i);
		heapsize--;
		//INSTEAD OF MAX-HEAPIFY
		/*
		int temp = arr[0];
		int index = heapsize - 1;
		for(int i = 0; i < index; i++) {
			arr[i] = arr[i+1];
		}
		*/
		arr[index] = temp;
		while(arr[index] > arr[index/2]) {
			swap(arr, index, index/2);
			index = index/2;
		}
	}
}

int main() {
	int arr[15] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	heapSort(arr, 10, 15);
	print(arr, 10);
	return 0;
}