//整数删除：优先队列 + 模拟链表
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
// #include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5 + 10;
int a[N], l[N], r[N];
int st[N];
void solve()
{
	int n, k; cin >> n >> k;
    //pii：队列中存储的元素类型，这里是一个包含两个整数的对; 
    //vector<pii>：底层容器的类型，这里是一个存储 pii 类型元素的 vector 容器。
    //greater<pii> 表示按照从小到大的顺序排序
	priority_queue<pii, vector<pii>, greater<pii>>q;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		q.push({a[i], i});

		st[i] = a[i];

		l[i] = i - 1;
		r[i] = i + 1;
		
		if(r[i] == n)
			r[i] = -1;
	}

	int cnt = k;
	while(k)
	{
		pii t = q.top();

		q.pop();

		if(t.first != st[t.second])
		{
			q.push({st[t.second], t.second});
			continue;
		}

		k --;

		//获取该元素在原数组中的位置
		int pos = t.second;

		//将该元素的相邻元素加上该数值
		if(l[pos] >= 0)
		    st[l[pos]] += t.first;

		if(r[pos] >= 0)
		    st[r[pos]] += t.first;


		//更新相邻点的相邻元素
		if(l[pos] >= 0)
		    r[l[pos]] = r[pos];
		if(r[pos] >= 0)
		    l[r[pos]] = l[pos];

		//该元素已经被删除，打标记
		st[pos] = -1;
	}
	for(int i = 0; i < n; i ++)
	{
		if(st[i] != -1)
			cout << st[i] << " ";
	}
	
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)
	solve();
}
