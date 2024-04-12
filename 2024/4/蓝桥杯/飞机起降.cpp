//#include <bitset/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
bool dfs(int u, int time): 这是一个递归函数，用于尝试安排飞机的降落顺序。参数u表示当前已经成功降落的飞机数量，time表示当前的时间，即前一架飞机落地的时间。

if(u>=n) return true;: 如果已经成功降落的飞机数量等于总飞机数量n，则表示所有飞机都已经成功降落，返回true。

for (int i = 0; i < n; i++): 遍历所有飞机，尝试确定下一架要降落的飞机。

if(!st[i]): 如果第i架飞机还没有降落过（st[i]为false），则尝试安排其降落。

st[i]=true;: 标记第i架飞机已经被安排降落。

if (time>p[i].d+p[i].l): 如果当前时间已经超过了第i架飞机的降落截止时间（即飞机飞行时长加上降落耗时），则该安排是不合法的，返回false。

int t=max(time,p[i].d)+p[i].l;: 计算下一架飞机的降落时间。如果当前时间已经超过了第i架飞机的起飞时间，则下一架飞机可以在当前时间降落；否则，需要等到第i架飞机起飞后再降落。

if(dfs(u+1,t)) return true;: 递归调用dfs函数，尝试安排下一架飞机的降落。如果成功安排下一架飞机的降落，则返回true。

st[i]=false;: 如果无法安排下一架飞机的降落，则取消对第i架飞机的降落安排，进行回溯。

return false;: 如果遍历所有飞机后都无法成功安排下一架飞机的降落，则返回false，表示当前安排是不合法的。
*/

const int N=10+20;//最大飞机数量+20(偏大)

struct plane	
{
	int t;//到达时间
	int d;//悬停时间
	int l;//降落时间
}p[N];

int st[N];//判断当前飞机是否降落

int n;//飞机数量

//u:已经降落的飞机数量, time:表示当前时间,前一架飞机降落的时间
bool dfs(int u, int time)
{
	if(u>=n)
		return true;
	//第(n+1)架飞机降落
	for (int i = 0; i < n; i++)
	{
		if(!st[i])
		{
			st[i]=true;
			//不合法
			if (time>p[i].d+p[i].l)
			{
				st[i]=false;
				return false;
			}
			int t=max(time,p[i].d)+p[i].l;
			if(dfs(u+1,t))
				return true;
			
			st[i]=false;
		}
	}
	return false;
}

void solve()
{
	cin>>n;//飞机数量
	for (int i = 0; i < n; ++i)
		cin>>p[i].t>>p[i].d>>p[i].l;//输入设定

	if(dfs(0,0))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	//防止多次执行
	for (int i = 0; i < n; i++)
		st[i]=false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin>>t;//循环次数
	while (t--)
		solve();

	return 0;
}