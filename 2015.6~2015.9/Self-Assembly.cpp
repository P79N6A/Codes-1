#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
vector<int> G[60];
int vis[60];

int getid(char a, char b)
{
    return 2 * (a - 'A') + (b == '+');
}

bool dfs(int u)
{
    vis[u] = -1;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (vis[v] < 0) return 0;
        if (!vis[v] && !dfs(v)) return 0;
    }
    vis[u] = 1;
    return 1;
}

int main()
{
    int n;
    char s[20];
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < 52; ++i) G[i].clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            for (int i = 0; i < 8; i += 2)
            {
                for (int j = 0; j < 8; j += 2)
                {
                    if (i == j || s[i] == '0' || s[j] == '0') continue;
                    int a = getid(s[i],s[i+1]), b = getid(s[j],s[j+1]);
                    G[a^1].push_back(b); //eg.(A-00B+B-) (A-^1 = A+) -> (00B+B-)
                }
            }
        }
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < 52; ++i)
        {
            if (!vis[i] && !dfs(i))
            {
                printf("unbounded\n");
                goto ed;
            }
        }
        printf("bounded\n");
        ed:;
    }
    return 0;
}
