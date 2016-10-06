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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int len[MAXN];
int cnt[MAXN];
int p[MAXN], q[MAXN];
vector<int> G[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k, x;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        G[x].push_back(i);
    }
    bool flag = G[0].size() == 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            int u = G[i][j];
            if (cnt[u] == k) continue;
            for (int &l = len[i + 1]; l < G[i + 1].size(); ++l) {
                int v = G[i + 1][l];
                if (cnt[v]) continue;
                p[ans] = u, q[ans++] = v;
                ++cnt[v];
                if (++cnt[u] == k) {
                    ++l;
                    break;
                }
            }
        }
        if (len[i + 1] != G[i + 1].size()) {
            flag = 0;
            break;
        }
    }
    if (!flag) ans = -1;
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) {
        printf("%d %d\n", p[i], q[i]);
    }
    return 0;
}
