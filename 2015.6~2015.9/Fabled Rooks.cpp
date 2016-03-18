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
const int MAXN = 5e3 + 111;
struct Rook{
	int l, r, id;
	bool operator < (const Rook& t)const
	{
		return r < t.r;
	}
};
Rook x[MAXN], y[MAXN];
int xx[MAXN], yy[MAXN], n;
bool vis[MAXN];

bool can(Rook *r, int *temp)
{
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; ++i)
	{
		bool ok = 0;
		//cout <<r[i].id << ',' <<  r[i].l <<',' <<  r[i].r << endl;
		for(int j = r[i].l; j <= r[i].r; ++j)
		{
			if(!vis[j])
			{
				temp[r[i].id] = j;
				ok = vis[j] = 1;
				break;
			}
		}
		if(!ok) return 0;
	}
	return 1;
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while(cin >> n)
	{
		for( int i = 0; i < n; ++i )
		{
			cin >> x[i].l >> y[i].l >> x[i].r >> y[i].r;
			x[i].id = y[i].id = i;
		}
		sort(x, x + n), sort(y, y + n);
		bool ans = (can(x, xx) && can(y, yy));
		if( ans )
		{
			for(int i = 0; i < n; ++i)
				cout << xx[i] << ' ' << yy[i] << '\n';
		}
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}

