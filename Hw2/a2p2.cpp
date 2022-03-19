#include <iostream>
#include <deque>

using namespace std;

int main()
{
    //1
    deque<float> A;

    float myfloat;
    do
    {
        //2
        cin >> myfloat;
        //3
        if(myfloat > 0)
        {
            A.push_back(myfloat);
        }
        else if(myfloat < 0)
        {
            A.push_front(myfloat);
        }
    } while(myfloat);

    //4
    for(int i = 0; i < (int)A.size(); i++)
    {
        cout << A[i] << " ";
    }
    //5
    cout << endl;

    //6
    deque<float>::iterator it = A.begin();
    while(*it < 0)
        it++;

    A.insert(it, 0);

    //7
    for(int i = 0; i < (int)A.size() - 1; i++)
    {
        cout << A[i] << ";";
    }
    cout << A[(int)A.size() - 1] << endl;

    return 0;
}