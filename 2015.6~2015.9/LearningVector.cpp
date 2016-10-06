#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 55;
int vis[MAXN][MAXN][3000], dp[MAXN][MAXN][3000], t, n, k, kase;
struct V{
	int x, y;
	bool operator <(const V &t)const
	{
		return y * t.x > x * t.y; //б��[y/x]>[t.y/t.x]
	}
}v[MAXN];

int dfs(int id, int pick, int h)
{
	int &ret = dp[id][pick][h];
	if (pick == k) return ret = 0; //�������������ֻʣ0��
	if (id == n) return ret = -INF; //����������������-INF
	if (vis[id][pick][h] == kase) return ret;
	vis[id][pick][h] = kase;
	ret = 0;
	ret = max(ret, dfs(id + 1, pick, h)); //��ȡ�ڸ�id��
	ret = max(ret, dfs(id + 1, pick + 1, h + v[id].y) + 2*v[id].x*h+v[id].x*v[id].y); //ȡ��id��
	return ret;
}

int main()
{
	for (kase = scanf("%d",&t); kase <= t; ++kase)
	{
	    cin >> n >> k;
	    for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y;
	    sort(v, v + n);
	    cout << "Case " << kase << ": " << dfs(0,0,0) << '\n';
	}
	return 0;
}

