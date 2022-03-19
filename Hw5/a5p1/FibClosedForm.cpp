#include <iostream>
#include <cmath>   

using namespace std;

typedef unsigned long long int bigboi;

bigboi fibClosedform(int n) {
	bigboi fibNum;
	double numPow;
	double fi = (1 + sqrt(5))/2;

	double temp = pow(fi, n/2);
	if(n % 2 == 0) {
		numPow = temp * temp;	
	} 
	else {
		numPow = temp * temp * fi;
	}

	fibNum = ceil(numPow/sqrt(5));

	return fibNum;
}

int main() {
	int n;
	cin >> n;
	cout << fibClosedform(n) << endl;
	return 0;
}