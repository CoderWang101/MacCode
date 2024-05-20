#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 建立小顶堆
    make_heap(a.begin(), a.end(), greater<int>());

    int days = 0, sum = 0;

    while (sum + a.front() > k)
    {
        sum += a.front();
        days++;
        pop_heap(a.begin(), a.end(), greater<int>()); // 将最大值移到末尾（未删除），然后重新调整堆
    }

    cout << days << endl;

    return 0;
}
// #include <iostream>
// #include<vector>
// #include <algorithm>
// using namespace std;
// //贪心-每一步都是最优秀
// int main()
// {
//     int n,k;
//     cin>>n>>k;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         cin>>a[i];

//     sort(a.begin(),a.end());

//     int days=0,sum=0;

//     for (int i = 0; i < n; i++)
//     {
//         while (sum+a[i]>k)
//         {
//             if(i==0)
//                 break;
//             sum-=a[i-1];
//             days--;
//         }
//         sum+=a[i];
//         days++;
//     }
//     cout<<days<<endl;

//     return 0;
// }
