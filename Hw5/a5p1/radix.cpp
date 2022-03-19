#include <iostream>
#include <cmath>

using namespace std;

void radix(int arr[], int n) {
	for(int i = 0; i < n; i++) {

	}
}

int digits(int number) {
	int i = 1;

	while (number >= 10) {
		number /= 10;
		i++;
	}

	return i;
}

int main() {
	int arr[] = { 123, 46, 521, 124, 643, 5, 1345 };
	for (int i = 0; i <= 100; i++) {
		cout << i << " has " << digits(i) << " digits" << endl;
	}
	return 0;
}