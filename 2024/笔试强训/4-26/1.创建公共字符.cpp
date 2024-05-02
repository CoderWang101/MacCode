#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string first, second;
    getline(cin, first);
    getline(cin, second);

    if (first.size() == 0)
        return 0;

    int ssz = second.size();
    for (int i = 0; i < ssz; i++)
    {
        size_t number = first.find(second[i]);
        while (number != string::npos)
        {
            first.erase(number, 1);
            number = first.find(second[i]);
        }
    }
    int fsz = first.size();
    for (size_t i = 0; i < fsz; i++)
        cout << first[i];

    return 0;
}
//输入:They are students. 
//输出:aeiou
