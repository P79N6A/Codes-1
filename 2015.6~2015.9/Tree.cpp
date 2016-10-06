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
int va[MAXN], lch[MAXN], rch[MAXN]; //lch、rch分别为i点的左右节点坐标 
V in, pos; //中序，后序 
string s;
int root;

void init() //初始化 
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
	V::iterator it = find(a.begin(), a.end(), rt); //在中序中找到根节点 
	V la(a.begin(), it); //左子树的中序 
	V ra(it + 1, a.end());   //右子树的中序 
	int l = la.size(), r = ra.size();
	V lb(b.begin(), b.begin() + l ); //左子树的后序 
	V rb(b.begin() + l, b.begin() + l + r); //右子树的后序 
	if (!lb.empty()) lch[rt] = lb.back(); //标记左右节点 
	if (!rb.empty()) rch[rt] = rb.back();
	build(la, lb); build(ra, rb); //递归建树 
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
		int mi = 0x3f3f3f3f, ans = 0x3f3f3f3f;  //mi：最小下标 ，ans：最小权值和 
		while (!q.empty())  //当前节点的权值等于当前节点本身值加上父节点权值 
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

