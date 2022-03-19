#include <iostream>

using namespace std;

typedef unsigned long long int bigboi;

bigboi fibBottomUp(int n) {
	bigboi arr[n];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	for(int i = 3; i <= n; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}

int main() {
	int n;
	cin >> n;
	cout << fibBottomUp(n) << endl;
	return 0;
}