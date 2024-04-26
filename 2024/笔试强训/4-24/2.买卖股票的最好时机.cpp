#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int max_profile(vector<int>& prices)
{
    int min_num=INF, max_prices=0;
    for (int i = 0; i < prices.size(); i++)
    {
        min_num=min(min_num,prices[i]);
        max_prices=max(max_prices,prices[i]-min_num); 
    }
    return max_prices;
}

int main()
{
    int n;
    cin >> n;
    if (n == 1 || n == 0)
    {
        cout<<0<<endl;
        return 0;
    }

    vector<int> prices;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        prices.push_back(tmp);
    }
    int MaxProfile=max_profile(prices);
    cout<<MaxProfile<<endl;

    return 0;
}
