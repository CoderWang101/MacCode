#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (b.size() == 0)
    {
        cout << a.size() << endl;
        return 0;
    }

    int asz = a.size(), bsz = b.size();
    int count = 0;

    if (asz == bsz)
    {
        for (int i = 0; i < asz; i++)
            if (a[i] != b[i])
                ++count;
        cout << count << endl;
    }
    else
    {
        int front_len = bsz - asz, back_len = bsz - asz;
        // 补充后面
        for (int i = 0; i < asz; i++)
            if (a[i] != b[i])
                ++front_len;

        // 补充前面
        int d = bsz - asz;
        for (int i = 0; i < asz; i++)
            if (a[i] != b[i + d])
                ++front_len;
        cout << (front_len < back_len ? front_len : back_len) << endl;
    }

    return 0;
}
