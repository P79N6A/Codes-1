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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
int k, cnt;
char s[11][11], t[11][11], ans[8];
set<char> col[10];

bool dfs(int d)
{
    if (d == 7)
    {
        if (++cnt == k)
        {
            puts(ans + 1);
            return 1;
        }
    }
    for (auto &c : col[d])
    {
        ans[d] = c;
        if (dfs(d + 1)) return 1;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int tt; cin >> tt;
    while (tt --)
    {
        cin >> k;
        for (int i = 1; i <= 6; ++i) scanf("%s", s[i] + 1);
        for (int i = 1; i <= 6; ++i) scanf("%s", t[i] + 1);
        for (int j = 1; j <= 6; ++j)
        {
            set<char> v;
            col[j].clear();
            for (int i = 1; i <= 6; ++i) v.insert(s[i][j]);
            for (int i = 1; i <= 6; ++i)
            {
                if (v.count(t[i][j]))
                    col[j].insert(t[i][j]);
            }
        }
        cnt = 0;
        if (!dfs(1)) puts("NO");
    }
    return 0;
}

