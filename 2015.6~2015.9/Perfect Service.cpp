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
const int MAXN = 1e4 + 111;
vector<int> son[MAXN], e[MAXN];
int d[MAXN][3];

void dfs(int node, int fa)
{
    int size = e[node].size();
    for (int i = 0; i < size; ++i)
    {
        int v = e[node][i];
        if (v != fa)
        {
            son[node].push_back(v);
            dfs(v, node);
        }
    }
}

int dp(int i, int j, int fas)
{
    if (d[i][j] >= 0) return d[i][j];
    if (son[i].empty())
    {
        if (j == 0 || fas != 0) return 1;
        return 0;
    }
    int size = son[i].size(), ret = 0;
    switch (j)
    {
        case 0:
            for (int k = 0; k < size; ++k)
                ret += min(dp(son[i][k], 0, j),dp(son[i][k],1,j));
            ret += 1;
            break;
        case 1:
            for (int k = 0; k < size; ++k)
                ret += dp(son[i][k], 2, j);
            break;
        case 2:
            ret = 0x7f7f7f7f;
            for (int k = 0; k < size; ++k)
                ret = min(ret, dp(i, 1, j) - dp(son[i][k],2,j) + dp(son[i][k],0,j)); //枚举：减一个C加一个S
            break;
    }
    return d[i][j] = ret;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, op, a, b;
    while (cin >> n)
    {
        memset(d, -1, sizeof d);
        for (int i = 1; i <= n; ++i) son[i].clear(), e[i].clear();
        for (int i = 1; i < n; ++i)
        {
            cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs(1, -1);
        cout << min(dp(1,0,0),dp(1,2,2)) << '\n';
        cin >> op;
        if (op == -1) break;
    }
	return 0;
}


