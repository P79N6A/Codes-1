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

const int INF = 0x3f3f3f3f;
const int MAXN = 111;

struct P {
    int v, w;
    P(int a, int b):v(a), w(b){};
};
string mp[MAXN];
int dis[MAXN];
bool in[MAXN];
vector<P> G[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n; cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> mp[i];
            dis[i] = INF;
            in[i] = 0;
            G[i].clear();
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                if (mp[i][j] == 'N') continue;
                for (int k = 0; k < j; ++k) {
                    if (mp[i][k] == 'Y') ++sum;
                }
                G[i].push_back(P(j, sum));
            }
        }
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        in[0] = 1;
        while (q.size()) {
            int u = q.front(); q.pop();
            in[u] = 0;
            for (int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i].v, w = G[u][i].w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (!in[v]) {
                        in[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        if (dis[n - 1] == INF) dis[n - 1] = -1;
        printf("%d\n", dis[n - 1]);
    }
    return 0;
}
