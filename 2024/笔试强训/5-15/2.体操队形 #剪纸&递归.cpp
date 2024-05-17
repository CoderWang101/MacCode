#include <iostream>
using namespace std;

const int N=15;
int ret;
int n;
bool vis[N];
int a[N];

void dfs(int pos)
{
    if(pos==n+1)
    {
        ret++;
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        if(vis[a[i]]) return;//剪枝  vis[a[pos]]->所诉求位置是否被访问
        vis[i]=true;
        dfs(pos+1);
        vis[i]=false;//还原现场
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1);
    cout<<ret<<endl;

    return 0;
}


// int dfs(vector<int> &a, vector<bool> &vis, int pos)
// {
//     vis[pos] = true;
//     int count = 1;

//     // vis[a[pos]]->所诉求位置是否被访问
//     if (!vis[a[pos]] && a[pos] != pos)
//         count += dfs(a, vis, a[pos + 1]);
//     return count;
// }

// error
//      int n;
//      cin>>n;

//     vector<int> a(n);
//     vector<int> dp(n);
//     for (int i = 0; i < n; i++)
//         cin>>a[i];

//     dp[0]=1;

//     for (int i = 1; i < n; i++)
//     {
//         if(a[i]==i)
//         {
//             dp[i]=dp[i-1];
//             continue;
//         }
//         dp[i]=dp[i-1]+a[i];
//     }
//    cout<<dp[n-1]<<endl;