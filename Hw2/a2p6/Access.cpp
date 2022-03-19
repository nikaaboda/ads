#include <vector>
#include "Access.h"
using namespace std;

void Access::activate(unsigned int code)
{
    codes.push_back(code);
}

void Access::deactivate(unsigned int code)
{
    vector<int>::iterator it;
    for(it = codes.begin(); it != codes.end(); it++)
    {
        if(*it == (int)code)
                codes.erase(it);
    }
}

bool Access::isactive(unsigned int code) const
{
    for(int i = 0; i < (int)codes.size(); i++)
    {
        if(codes[i] == (int)code)
            return true;
    }

    return false;
}