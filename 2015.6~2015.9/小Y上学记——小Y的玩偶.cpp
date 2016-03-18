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
const int INF = 0x7f7f7f7f, MAXN = 1111;
int w[MAXN], id[MAXN], n;
vector<int> v[MAXN];
bool vis[MAXN];

bool cmp(int a, int b)
{
    return w[a] > w[b];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i) v[i].clear();
        for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
        for (int i = 0; i < n; ++i)
        {
            int k, x;
            id[i] = i;
            scanf("%d", &k);
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &x);
                v[i].push_back(x);
            }
        }
        sort(id, id + n, cmp);
        memset(vis, 0, sizeof vis);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int num = id[i];
            vis[num] = 1;
            for (int j = 0; j < v[num].size(); ++j)
            {
                int cur = v[num][j];
                if (!vis[cur])
                {
                    ans += w[cur];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
