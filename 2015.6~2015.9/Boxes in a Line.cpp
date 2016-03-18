#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e5 + 111;
typedef long long ll;
struct Node{
	int l, r;
}node[MAXN];

inline void link(int& x, int& y)
{
	node[x].r = y, node[y].l = x;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n, m, kase = 0;
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 1; i < n; ++i) {node[i].l = i - 1, node[i].r = i + 1;}
		node[0].l = n, node[0].r = 1, node[n].l = n - 1, node[n].r = 0;
		int op, x, y;
		bool run = 0;
		while (m --)
		{
			scanf("%d", &op);
			if (op == 4) run = 1 - run;
			else
			{
				scanf("%d%d", &x, &y);
				if (op == 3 && node[y].r == x) swap(x, y);
				int LX = node[x].l, RX = node[x].r, LY = node[y].l, RY = node[y].r;
				if (run) op = 3 - op;
				if (op == 1)
				{
					if (node[x].r == y) continue;
					link(LX,RX), link(LY, x), link(x, y);
				}
				else if (op == 2)
				{
					if (node[x].l == y) continue;
					link(LX,RX), link(y, x), link(x, RY);
				}
				else
				{
					if (node[x].r == y) link(LX, y), link(y, x), link(x, RY);
					else link(LX, y), link(y, RX), link(LY, x), link(x, RY);
				}
			}
		}
		ll ans = 0;
		int b = 0;
		for (int i = 1; i <= n; ++i)
		{
			b = node[b].r;
			if (i % 2 == 1) ans += b;
		}
		if (run && (n % 2 == 0)) ans = (ll)(n + 1) * n / 2 - ans;
		printf("Case %d: %lld\n", ++kase, ans);
	} 
	return 0;
}

