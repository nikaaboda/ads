#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int bigboi;

bigboi powerNum(double n, int pow) {
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

bigboi fibNaive(int n)
{
	if(n < 2)
	{
		return n;
	}
	else
	{
		return fibNaive(n-1) + fibNaive(n-2);
	}
}

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

bigboi fibClosedform(int n) {
	bigboi fibNum;
	double fi = (1 + sqrt(5))/2;

	fibNum = ceil(powerNum(fi, n)/sqrt(5));

	return fibNum;
}

bigboi fibMatrix(int n) {
	bigboi arr[2][2];
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;

	bigboi res[2][1];
	bigboi temp1, temp2;

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

int main()
{
	int n;
	cin >> n;
	cout << fibMatrix(n) << endl;
	cout << fibClosedform(n) << endl;
	cout << fibBottomUp(n) << endl;
	cout << fibNaive(n) << endl;
	return 0;
}

