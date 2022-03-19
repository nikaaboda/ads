#include <iostream>

using namespace std;

typedef unsigned long long int bigboi;

bigboi fibMatrix(int n) {
	int arr[2][2];
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;

	int res[2][1];
	int temp1, temp2;

	res[0][0] = 0;
	res[1][0] = 1;

	for(int i = 0; i < n; i++) {
		temp1 = res[0][0];
		temp2 = res[1][0];
		res[0][0] = temp1 * arr[0][0] + temp2 * arr[1][0];
		res[0][1] = temp1 * arr[0][1] + temp2 * arr[1][1];
	}

	return res[0][0];
}

int main() {
	int n;
	cin >> n;
	cout << fibMatrix(n) << endl;
	return 0;
}