#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 111;
double x[2 * MAXN];
int n;
struct Building{
	int id;
	double x, y, w, d, h;
	bool operator < (const Building& t)const
	{
		return (x < t.x || (x == t.x && y < t.y));
	}
}b[MAXN];

bool cover(int id, double mx)
{
	return (mx >= b[id].x && mx <= b[id].x + b[id].w );
}

bool visable(int id, double mx)
{
	if (!cover(id, mx)) return 0;
	for (int i = 0; i < n; ++i)
	{
		if (b[i].y < b[id].y && b[i].h >= b[id].h && cover(i, mx))
			return 0;
	}
	return 1;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int kase = 0;
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
			b[i].id = i + 1;
			x[2 * i] = b[i].x, x[2 * i + 1] = b[i].x + b[i].w;
		}
		sort(b, b + n);
		sort(x, x + 2 * n);
		int cnt = unique(x, x + 2 * n) - x;
		
		if (kase) putchar('\n');
		printf("For map #%d, the visible buildings are numbered as follows:\n", ++kase);
		printf("%d", b[0].id);
		for (int i = 1; i < n; ++i)
		{
			bool have = 0;
			for (int j = 1; j < cnt; ++j) //建筑放到每个区间里去判断 
				if (visable(i, (x[j] + x[j - 1]) / 2.0)) { have = 1; break;}
			if (have)
				printf(" %d", b[i].id); 
		}
		putchar('\n');
	}
	return 0;
}

