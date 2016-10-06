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
const int MAXN = 511;

vector<int> G[MAXN];
int num[MAXN];
bool vis[MAXN];
struct P {
    int u, dis;
    P(int a, int b): u(a), dis(b){};
};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, u, v; cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i];
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    queue<P> q;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (__gcd(num[i], num[j]) == 1) {
                memset(vis, 0, sizeof vis);
                q.push(P(i + 1, 0));
                vis[i + 1] = 1;
                while (q.size()) {
                    P cur = q.front(); q.pop();
                    int u = cur.u, dis = cur.dis;
                    //pr(u);
                    if (u == j + 1) {
                        ans += dis;
                        //pr(dis)
                        while (q.size()) q.pop();
                        break;
                    }
                    for (int k = 0; k < G[u].size(); ++k) {
                        int v = G[u][k];
                        if (!vis[v]) {
                            q.push(P(v, dis + 1));
                            vis[v] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
