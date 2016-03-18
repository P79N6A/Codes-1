#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

struct Edge{
    int to, w;
    Edge(int _to, int _w):to(_to), w(_w){}
};

vector<vector<Edge> > G;
int ans;

int dfs(int u, int fa)
{
    if (G[u].size() <= 1) return 0;

    vector<int> temp;
    for (int i = 0; i < G[u].size(); ++i) {
        if (G[u][i].to == fa) continue;
        temp.push_back(dfs(G[u][i].to, u) + G[u][i].w);
    }
    sort(temp.begin(), temp.end());
    // 就是这里！！！！！本地运行越界也无所谓，真是醉了，然而去掉这句就WA
    if (temp.size() > 1){
        ans = min(ans, temp[0] + temp[1]);
    }
    return temp[0];
}

int main()
{
    int n, u, v, w;
    while (~scanf("%d", &n) && n)
    {
        G.clear();
        G.resize(n + 2);
        ans = INF;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(Edge(v, w));
            G[v].push_back(Edge(u, w));
        }

        for (int i = 1; i <= n; ++i) {
            if (G[i].size() > 1) {
                dfs(i, -1);
                break;
            }
        }

        if (n == 2) ans = w;

        printf("%d\n", ans);
    }
    return 0;
}
