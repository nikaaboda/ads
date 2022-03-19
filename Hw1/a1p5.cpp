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
        getline(cin, input);
        if(input == "END")
            condition = 0;
        else
            words.push_back(input);
        counter++;
    }

    if(words.size() >= 5)
    {
        string temp = words[1];
        words[1] = words[4];
        words[4] = temp;
    }
    else
        cout << "Second and/or fifth elements do/does not exist!" << endl;

    words.back() = "???";

    for(int i = 0; i < ((int)words.size()-1); i++)
        cout << words[i] << ',';
    cout << words[(int)words.size()-1];
    cout << endl;

    vector<string>::iterator j = words.begin();
    for(int i = 0; i < ((int)words.size()-1); i++)
    {
        cout << *j << ';';
        j++;
    }
    cout << *j << endl;
    

    vector<string>::iterator k = words.end() - 1;
    for(int i = 0; i < (int)words.size(); i++)
    {
        cout << *k << ' ';
        k--;
    }

    return 0;
}