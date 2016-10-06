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
vector<int> bfs, dfs; //�洢bfs��dfs�� 
int pos[MAXN];        //��¼�ڵ�����ڵ�ľ��� 
set<int> son[MAXN]; //�洢�ӽڵ�(set�����Զ�����Ps����Ȼ�����Ѿ���������������XD 
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
		stack<int> sta; //�洢���׽ڵ� 
		int rt = dfs[0];
		sta.push(rt);
		for (int i = 1; i < n; ++i)
		{
			while(1) //�������̾��ǱȽϾ��룬�ж��Ƿ����ӽڵ�����ֵܽڵ㡣 
			{
				int now = sta.top(); //��ǰ�ڵ� 
				if (now == rt || pos[now] + 1 < pos[dfs[i]] /*�ֵܽڵ�*/)
				{
					son[now].insert(dfs[i]);
					sta.push(dfs[i]);
					break;
				}
				else sta.pop(); //������ڵ����������������׼��㡣ջ����һ���ڵ��ǵ�ǰջ���ڵ�ĸ��ڵ� 
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

