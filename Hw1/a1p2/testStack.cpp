#include <iostream>
#include "Stack.h"
using namespace std;


int main()
{
    Stack<int> intstack;
    
    Stack<float> floatstack(15);
    //
    Stack<int> copystack(intstack);

    intstack.push(1); 
    intstack.push(2);
    intstack.print();

    int popped;
    intstack.pop(popped);
    intstack.print();

    int num = intstack.getNumEntries();
    int back = intstack.back();
    cout << num << " " << back << " " << popped << endl;
    
    return 0;
}