#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
typedef vector<int> V;
const int MAXN = 1e4 + 111;
int va[MAXN], lch[MAXN], rch[MAXN]; //lch��rch�ֱ�Ϊi������ҽڵ����� 
V in, pos; //���򣬺��� 
string s;
int root;

void init() //��ʼ�� 
{
	int a;
	memset(lch, 0, sizeof lch);
	memset(rch, 0, sizeof rch);
	memset(va, 0, sizeof va);
	stringstream ss(s);
	in.clear(), pos.clear();
	while (ss >> a) in.push_back(a);
	getline(cin, s);
	stringstream ss2(s);
	while (ss2 >> a) pos.push_back(a);
}

void build(V& a, V& b)
{
	if (a.size() <= 1 || b.size() <= 1) return;
	int rt = b.back();
	V::iterator it = find(a.begin(), a.end(), rt); //���������ҵ����ڵ� 
	V la(a.begin(), it); //������������ 
	V ra(it + 1, a.end());   //������������ 
	int l = la.size(), r = ra.size();
	V lb(b.begin(), b.begin() + l ); //�������ĺ��� 
	V rb(b.begin() + l, b.begin() + l + r); //�������ĺ��� 
	if (!lb.empty()) lch[rt] = lb.back(); //������ҽڵ� 
	if (!rb.empty()) rch[rt] = rb.back();
	build(la, lb); build(ra, rb); //�ݹ齨�� 
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	while (getline(cin, s))
	{
		init();
		build(in, pos);
		root = pos.back();
		queue<int> q; q.push(root);
		va[root] = root;
		int mi = 0x3f3f3f3f, ans = 0x3f3f3f3f;  //mi����С�±� ��ans����СȨֵ�� 
		while (!q.empty())  //��ǰ�ڵ��Ȩֵ���ڵ�ǰ�ڵ㱾��ֵ���ϸ��ڵ�Ȩֵ 
		{
			int cur = q.front(); q.pop();
			int l = lch[cur], r = rch[cur];
			if (l)
			{
				va[l] = l + va[cur];
				q.push(l);
			}
			if (r)
			{
				va[r] = r + va[cur];
				q.push(r);
			}
			if (!l && !r)
			{
				if (ans > va[cur])
				{
					ans = va[cur];	
					mi = cur;
				}
				if (ans == va[cur] && mi > cur) 
					mi = cur;
			}
		}
		cout << mi << '\n';
	}
	return 0;
}

