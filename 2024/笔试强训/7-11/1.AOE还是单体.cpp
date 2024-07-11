//37.5%
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int mid = n / 2, count = 0,pos=0;
    while (v[mid] != 0)
    {
        v[mid] -= 1; 
        count += x;
        pos++;
    }

    int sum=count;
    for (int i = mid + 1; i < n; i++)
        sum += v[i]-pos;

    cout<<sum<<endl;

    return 0;
}
