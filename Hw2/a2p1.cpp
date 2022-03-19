#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main()
{
    //1
    list<int> A;
    list<int> B;
    list<int>::iterator a;
    list<int>::iterator b;

    bool condition = true;
    int n;
    //2
    while(condition)
    {
        cin >> n;
        if(n > 0)
        {
            A.push_back(n);
            B.push_front(n);
        }
        else
            condition = false;
    }
    //5
    for( a = A.begin(); a != A.end(); a++)
        cout << *a << " ";
    cout << endl;
    
    ofstream file;
    file.open("listB.txt");
    if(file.is_open())
    {
    for( b = B.begin(); b != B.end(); b++)
        file << *b << " ";
    file << endl;
    file.close();
    }
    //6
    cout << endl;
    //7
    a = A.begin();
    A.push_back(*a);
    A.pop_front();

    b = B.begin();
    B.push_back(*b);
    B.pop_front();

    //8
    a = A.begin();
    cout << *a;
    for( a++; a != A.end(); a++)
        cout << "," << *a;
    cout << endl;
    
    b = B.begin();
    cout << *b;
    for( b++; b != B.end(); b++)
        cout << "," << *b;
    cout << endl;

    //9
    cout << endl;

    //10
    A.merge(B);

    //11
    A.sort();
    for( a = A.begin(); a != A.end(); ++a)
        cout << *a << " ";
    cout << endl;

    return 0;
}