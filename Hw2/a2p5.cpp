#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> values;
    vector<int>::iterator it;

    for(int i = 0; i < 6; i++)
    {
        int a = rand() % 49 + 1;
        bool dupl = false;

        for(it = values.begin(); it != values.end(); it++)
        {
            if(*it == a)
                dupl = true;
        }

        if(!dupl)
            values.push_back(a);
    }

    sort(values.begin(), values.end());
    for(it = values.begin(); it != values.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}