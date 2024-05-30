#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a,int b)
{
    return a>b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int range;
        cin>>range;

        if(range==0)
            cout<<0<<endl;

        sort(arr.begin(),arr.begin()+range,compare);        
        cout<<arr[1]<<endl;
    }
    
    return 0;
}
