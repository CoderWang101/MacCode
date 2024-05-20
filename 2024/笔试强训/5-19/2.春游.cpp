#include <iostream>
using namespace std;
//%25
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        int member, price1, price2, sum = 0;
        cin >> member >> price1 >> price2;

        int tmp1 = price2 / 2, tmp2 = price2 / 3;

        if (tmp1 > tmp2)
        {
            if (member > 2)
            {
                int clu=member;
                clu/=3;
                member %= 3;
                sum += price2*clu;
            }
        }
        else
        {
            if (member > 1)
            {
                int clu=member;
                clu/=2;
                member %= 2;
                sum += price2*clu;
            }
        }
        if (member > 0)
            sum += price1 < price2 ? price1 : price2;
        cout << sum << endl;
    }

    return 0;
}
