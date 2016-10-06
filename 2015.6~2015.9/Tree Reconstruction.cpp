#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
const int MAXN = 1111;
vector<int> bfs, dfs; //存储bfs、dfs序 
int pos[MAXN];        //记录节点与根节点的距离 
set<int> son[MAXN]; //存储子节点(set可以自动排序）Ps：虽然这题已经给好升序排列了XD 
int n;

void init()
{
	int a;
	bfs.clear(), dfs.clear();
	for (int i = 0; i <= n; ++i) 
		son[i].clear();
	for (int i = 0; i < n; ++i) 
	{ 
		cin >> a, bfs.push_back(a);
		pos[a] = i;
	}
	for (int i = 0; i < n; ++i) 
		cin >> a, dfs.push_back(a); 
}

int main()
{
	while (cin >> n)
	{
		init();
		stack<int> sta; //存储父亲节点 
		int rt = dfs[0];
		sta.push(rt);
		for (int i = 1; i < n; ++i)
		{
			while(1) //整个过程就是比较距离，判断是否是子节点或者兄弟节点。 
			{
				int now = sta.top(); //当前节点 
				if (now == rt || pos[now] + 1 < pos[dfs[i]] /*兄弟节点*/)
				{
					son[now].insert(dfs[i]);
					sta.push(dfs[i]);
					break;
				}
				else sta.pop(); //如果两节点距离相邻则呼唤父亲几点。栈的下一个节点是当前栈顶节点的父节点 
			}
		}
		set<int>::iterator it;
		for (int i = 1; i <= n; ++i)
		{
			cout << i << ":";
			for (it = son[i].begin(); it != son[i].end(); ++it)
				cout << ' ' << *it;
			cout << '\n';
		}
	}
	return 0;
}

