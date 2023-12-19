#include <iostream>
using namespace std;
#include <string>

int main()
{
    string s("HelloWord");

    for(auto ch:s)
    {
        cout << ch << endl;
    }

    return 0;
}