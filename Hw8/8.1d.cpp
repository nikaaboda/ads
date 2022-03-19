#include <iostream>
#include <string>

using namespace std;

void print(string arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int maxLength(string arr[], int n) {
	int max = arr[0].length();

	for(int i = 1; i < n; i++) {
		if((int)arr[i].length() > max)
			max = arr[i].length();
	}

	return max;
}

void counting(string arr[], int n, int d) {
	cout << "Okay" << endl;
	int buffer[25];
	string result[n];

	for(int i = 0; i < 25; i++) {
		buffer[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		result[i] = " ";
	}

	for(int i = 0; i < n; i++) {
		int digit = (int)arr[i].length() > d ? (arr[i].at(d) - 97) : 0;
		buffer[digit]++;
	}

	for(int i = 1; i < 25; i++) {
		buffer[i] = buffer[i] + buffer[i-1];
	}
// "word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time" 
	for(int i = n-1; i >= 0; i--) {
		string word = arr[i];
		int digit = (int)arr[i].length() > d ? (arr[i].at(d) - 97) : 0;
		int index = buffer[digit] - 1;
		result[index] = word;
		buffer[digit]--;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = result[i];
	}
}

void radix(string arr[], int n) {
	int max = maxLength(arr, n);

	for (int i = max - 1; i >= 0; i--) {
		counting(arr, n, i);
	}
}

int main() {
	string arr[10] = {  "word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time" };
	print(arr, 10);
	radix(arr, 10);
	print(arr, 10);
	return 0;
}