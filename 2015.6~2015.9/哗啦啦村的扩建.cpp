#include<iostream>
#include<cctype>
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
typedef long long ll;
const int MAXN = 1e5 + 111;
bool vis[MAXN];
int have[MAXN];
struct Edge{
    int to;
    int next;
    ll v;
}edge[MAXN];
int n, cnt, head[MAXN];
ll ans;

void make_map(int from, int to, int v)
{
    edge[cnt].to = to;
    edge[cnt].v = v;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}

void dmap(int from, int to, int v)
{
    make_map(from, to, v);
    make_map(to, from, v);
}

void dfs(int p)
{
    vis[p] = 1;
    for(int i = head[p]; ~i ; i = edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]) continue;
        dfs(v);
        have[p] += have[v];
        ans += edge[i].v * abs(n - 2 * have[v]);
    }
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	cin >> n;
	int a, b, c;
	cnt = 0;
	for(int i = 0; i <= n; ++i) have[i] = 1;
	memset(head, -1, sizeof head);
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; ++i)
	{
        cin >> a >> b >> c;
	    dmap(a, b, c);
    }
    ans = 0;
    dfs(1);
    if(ans)
        cout << ans << "00000000\n";
    else cout << 0 << '\n';
	return 0;
}


