#include <iostream>
#include <vector>

using namespace std;

void max(vector<vector<int>> &arr, int m, int n) {
	vector<vector<int>> sum;
	sum.resize(m);
	for(int i = 0; i < m; i++) {
		sum[i].resize(n);
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			sum[i][j] = arr[i][j];
		}
	}

	for(int i = n-2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			if(sum[i][j] + sum[i+1][j] >= sum[i][j] + sum[i+1][j+1]) {
				sum[i][j] += sum[i+1][j];
			} else {
				sum[i][j] += sum[i+1][j+1];
			}
		}
	}

	cout << sum[0][0] << endl;

	int k = 0;
	for(int i = 0; i < m; i++) {
		if(arr[i][k] < arr[i][k+1]) {
			k++;
		}
		cout << arr[i][k] << " ";
	}
}

int main() {
	vector<vector<int>> arr = {
		{7, 0, 0, 0, 0},
		{3, 8, 0, 0, 0},
		{8, 1, 0, 0, 0},
		{2, 7, 4, 4, 0},
		{4, 5, 2, 6, 5}
	};

	max(arr, 5, 5);
	return 0;
}