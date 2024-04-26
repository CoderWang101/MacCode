#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> words;
    string word;

    while (cin >> word && word != ".")
        words.push_back(word);

    reverse(words.begin(), words.end());

    for (size_t i = 0; i < words.size(); ++i)
    {
        cout << words[i];
        if (i != words.size() - 1)
        {
            cout << " ";
        }
    }

    return 0;
}
//I like beijing. -> beijing. like I