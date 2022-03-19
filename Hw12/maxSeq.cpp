#include <iostream>
#include <vector>

using namespace std;

enum Sign {LEFT, UP, DIAGONAL};

void print(vector<vector<Sign>> &signArr, vector<vector<int>> &lengthArr, vector<int> &sortedArr, int m, int n) {
	if(m != 0 && n != 0) {
		if(signArr[m-1][n-1] == DIAGONAL) {
			print(signArr, lengthArr, sortedArr, m-1, n-1);
			cout << sortedArr[m] << " ";
		} else if(lengthArr[m-1][n] > lengthArr[m][n-1]) {
			print(signArr, lengthArr, sortedArr, m-1, n);
		} else {
			print(signArr, lengthArr, sortedArr, m, n-1);
		}
	}
}

void maxSeq(vector<int> arr, vector<int> sortedArr, int m, int n) {
	vector<vector<int>> lengthArr;
	vector<vector<Sign>> signArr;
	lengthArr.resize(m+1);
	signArr.resize(m);
	for(int i = 0; i < m + 1; i ++) {
		lengthArr[i].resize(n);
	}
	for(int i = 0; i < m; i++) {
		signArr[i].resize(n);
	}

	for(int i = 0; i <= m; i++) {
		lengthArr[i][0] = 0;
	}

	for(int j = 0; j <= n; j++) {
		lengthArr[0][j] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(sortedArr[i] == arr[j]) {
				lengthArr[i][j] = lengthArr[i-1][j-1]+1;
				signArr[i-1][j-1] = DIAGONAL;
			}
			else if(lengthArr[i-1][j] > lengthArr[i][j-1]) {
				lengthArr[i][j] = lengthArr[i-1][j];
				signArr[i-1][j-1] = UP;
			}
			else {
				lengthArr[i][j] = lengthArr[i][j-1];
				signArr[i-1][j-1] = LEFT;
			}
		}
	}

	print(signArr, lengthArr, sortedArr, m, n);
}	

int main() {
	vector<int> arr = { 8, 3, 6, 50, 1, 10, 8, 100, 30, 60, 40, 80 };
	vector<int> sortedArr = { 1, 3, 6, 8, 8, 10, 30, 40, 50, 60, 80, 100 };
	int m = 12;
	int n = m;
	maxSeq(arr, sortedArr, m, n);
	return 0;
}