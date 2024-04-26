#include <iostream>
#include<vector>
using namespace std;
typedef vector<long long> VLL;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x,y;
    cin>>n>>m>>x>>y;
    //修正位置,方便标记起始点
    x+=1,y+=1;

    vector<VLL> dp(25,vector<long long>(25,0));

    //初始化-起点
    dp[0][1]=1;//dp[1][1]=1->出发点

    //计算所有路径
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = 1; j <= m+1; j++)
        {
            if((i!=x && j!=y && abs(i-x)+abs(j-y)==3) || (i==x) && (j==y))
                dp[i][j]=0;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n+1][m+1]<<endl;

    return 0;
}








