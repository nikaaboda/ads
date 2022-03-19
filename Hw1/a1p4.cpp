#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    string input;
    int counter = 0;
    int condition = 1;

    while(condition == 1)
    {
        cin >> input;
        if(input == "END")
            condition = 0;
        else
            words.push_back(input);
        counter++;
    }

    for(int i = 0; i < (int)words.size(); i++)
        cout << words[i] << " ";
    cout << endl;

    vector<string>::iterator j = words.begin();
    for(int i = 0; i < ((int)words.size()-1); i++)
    {
        cout << *j << ',';
        j++;
    }
    cout << *j << endl;
    return 0;
}