//100%
#include <iostream>
#include <vector>

#define vi vector<int>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vi> v(m, vi(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    vector<vi> v_reserve(n, vi(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            v_reserve[j][i] = v[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << v_reserve[i][j] << " ";
        cout << endl;
    }
    return 0;
}