#include <iostream>

using namespace std;

typedef unsigned long long int bigboi;

bigboi powerNum(int n, int pow) {
	if(pow == 0) {
		return 1;
	}
	if( pow == 1 || n == 0 || n == 1 ) {
		return n;
	}
	
	if( pow % 2 == 0) {
		return powerNum(n * n, pow / 2);
	} else {
		return powerNum(n * n, pow/2) * n;
	}
}

int main() {
	int n, k;
	cin >> n;
	cin >> k;	
	cout << powerNum(n, k) << endl;
	return 0;
}