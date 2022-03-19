#include <iostream>
#include "WindGauge.h"
#include <vector>
using namespace std;

WindGauge::WindGauge(int period)
{
    vector<int> temp(period);
    values = temp;
    temp = vector<int>();
}

void WindGauge::currentWindSpeed(int speed)
{
    if(values[(int)values.size() - 1])
    {
        for(int i = 0; i < (int)values.size() - 1; i++)
        {
            values[i] = values[i+1];
        }
        values[(int)values.size() - 1] = speed;
    }
    else
    {
        int i = 0;
        while(values[i])
            i++;
        
        values[i] = speed;
    }
}

int WindGauge::highest() const
{
    int max = 0;
    for(int i = 0; i < (int)values.size(); i++)
    {
        if(values[i] > max)
            max = values[i];
    }

    return max;
}

int WindGauge::lowest() const
{
    int min = values[0];
    for(int i = 0; i < (int)values.size(); i++)
    {
        if(values[i] < min && values[i] > 0)
            min = values[i];
    }

    return min;
}

int WindGauge::average() const
{
    int sum = 0, i = 0, avg;
    
    while(values[i] > 0 && i < (int)values.size())
    {
        sum += values[i];
        i++;
    }

    avg = sum/i;

    return avg;
}

void WindGauge::dump()
{
    cout << "Highest: " << WindGauge::highest() << endl;
    cout << "Lowest: " << WindGauge::lowest() << endl;        
    cout << "Average: " << WindGauge::average() << endl;                
}