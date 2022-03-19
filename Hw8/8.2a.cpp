#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print(vector<int>& arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int arrMax(vector<int>& arr, int n) {
	int max = arr[0];

	for(int i = 1; i < n; i++) {
		if(arr[i] > max)
			max = arr[i];
	}

	return max;
}

int digit_count(int number) {
	int i = 1;

	while (number >= 10) {
		number /= 10;
		i++;
	}

	return i;
}


void bucketSort(vector<int>& arr, int digits) {
	vector<int> buckets[10];
	for(int i = 0; i < (int)arr.size(); i++) {
		int pos = arr[i]/pow(10, digits - 1);
		buckets[pos].push_back(arr[i]);
	}
	cout << "got here" << endl;
	for(int i = 0; i < 10; i++) {
		if(buckets[i].size() > 1) {
			int max = arrMax(buckets[i], (int)buckets[i].size());
			int digits = digit_count(max);
			bucketSort(buckets[i], digits);
		}
	}

	int k = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < (int)buckets[i].size(); j++) {
			arr[k] = buckets[i][j];
			k++;
		}
	}
}

void radix(vector<int>& arr) {
	cout << "okay" << endl;
	int max = arrMax(arr, (int)arr.size());
	int digits = digit_count(max);
	bucketSort(arr, digits);
}


int main() {
    vector<int> arr(10);
    cout<<"Enter 10 values: "<<endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

	radix(arr);

	print(arr, 10);

	return 0;
}