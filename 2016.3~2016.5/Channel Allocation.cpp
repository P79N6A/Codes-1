#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;

vector<int> G[30];
bool use[30];
int color[30], n;

void dfs(int u) {
    memset(use, 0, sizeof use);
    for (int i = 0; i < G[u].size(); ++i) {
        use[color[G[u][i]]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!use[i]) {
            color[u] = i;
            break;
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    char s[100];
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            G[i].clear();
            color[i] = 0;
            scanf("%s", &s);
            int u = s[0] - 'A', len = strlen(s);
            for (int i = 2; i < len; ++i) {
                G[u].push_back(s[i] - 'A');
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!color[i]) dfs(i);
        }
        set<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.insert(color[i]);
        }
        if (ans.size() > 1)
            printf("%d channels needed.\n", ans.size());
        else printf("1 channel needed.\n");
    }
    return 0;
}
