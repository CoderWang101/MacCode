#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> s(n);

    int left = 0, right = n - 1;
    for (int i = 1; i <= n; i++)
        if (i % 2 == 1)
            s[left++] = i;
        else
            s[right--] = i;
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}
