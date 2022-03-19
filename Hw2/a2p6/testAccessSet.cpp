#include <iostream>
#include <vector>
#include "Access.h"

int main()
{
    Access A;
    A.activate(1234);
    A.activate(9999);
    A.activate(9876);
    
    unsigned int usercode;
    bool closed = true;
    while(closed)
    {
        cout << "Enter your access code: ";
        cin >> usercode;
        if(A.isactive(usercode))
        {
            closed = false;
            cout << "Door opened successfully!" << endl;
        }
        else
            cout << "Couldn't open the door :(" << endl;
    }
    
    A.deactivate(usercode);
    A.deactivate(9999);
    A.activate(1111);

    bool closedagain = true;
    while(closedagain)
    {
        cout << "Enter your access code: ";
        cin >> usercode;
        if(A.isactive(usercode))
        {
            closedagain = false;
            cout << "Door opened successfully!" << endl;
        }
        else
            cout << "Couldn't open the door :(" << endl;
    }

    return 0;
}