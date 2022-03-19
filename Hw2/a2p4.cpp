#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> A;
    for(int i = 1; i < 31; i++)
        A.push_back(i);
    A.push_back(5);

    reverse(A.begin(), A.end());
    vector<int>::iterator it;
    for(it = A.begin(); it != A.end(); it++)
        cout << *it << " ";
    cout << endl;

    replace(A.begin(), A.end(), 5, 129);
    for(it = A.begin(); it != A.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}