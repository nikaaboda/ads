#include <iostream>

using namespace std;

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

void bubbleSort(int arr[], int n) {
	bool swapped = true;
	while(swapped) {
		swapped = false;
		for(int i = 0; i < n - 1; i++) {
			if(arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}
	}
}

int main() {
	int arr[] = { 15, -7, 124, 914, 2, 55, 124, 12};
	int size = sizeof(arr) / sizeof(int);
	bubbleSort(arr, size);
	print(arr, size);
	return 0;
}