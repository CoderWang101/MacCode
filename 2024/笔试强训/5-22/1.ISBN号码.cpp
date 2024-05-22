#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 13;

int main()
{
    string t;
    vector<string> s(N);
    cin>>t;
    for (int i = 0; i < N; i++)
        s[i]=t[i];

    int pos = 0, num = 1, count = 0;
    while (pos < N - 1)
    {
        if (pos == N - 2)
            break;
        if (s[pos] == "-")
        {
            ++pos;
            continue;
        }

        int tmp = stoi(s[pos]);
        tmp *= num++;
        count += tmp;
        s[pos] = to_string(tmp);
    }

    int end_num = count % 11;
    int num_check = stoi(s[s.size() - 1]);
    if (end_num == num_check)
        cout << "Right" << endl;
    else
        for (int i = 0; i < s.size(); i++)
            cout << s[i] << endl;

    return 0;
}
