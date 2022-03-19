#include <iostream>

using namespace std;

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
		int temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;
		maxHeap(arr, largest, heapsize, length);
	}
}

void buildMaxHeap(int arr[], int heapsize, int length) {
	for(int i = length/2 - 1; i >= 0; i--) {
		maxHeap(arr, i, heapsize, length);
	}
}

void heapSort(int arr[], int heapsize, int length) {
	buildMaxHeap(arr, heapsize, length);

	for(int i = heapsize-1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapsize--;
		maxHeap(arr, 0, heapsize, length);
	}
}

int main() {
	int arr[15] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	heapSort(arr, 10, 15);
	print(arr, 10);
	return 0;
}