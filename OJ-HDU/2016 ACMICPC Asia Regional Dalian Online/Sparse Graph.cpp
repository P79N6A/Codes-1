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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

map<pii, bool> edge;
int dis[MAXN];
int n, m;

void bfs(int s) {
    memset(dis, -1, sizeof dis);
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        if (i != s) st.insert(i);
    }
    set<int>::iterator it, temp;
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        vector<int> cl;
        for (it = st.begin(); it != st.end(); ++it) {
            int v = *it;
            if (!edge[pii(u, v)]) {
                dis[v] = dis[u] + 1;
                q.push(v);
                cl.push_back(v);
            }
        }
        for (int i = 0; i < cl.size(); ++i) {
            st.erase(cl[i]);
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, x, u, v; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        edge.clear();
        while (m --) {
            scanf("%d%d", &u, &v);
            edge[pii(u, v)] = edge[pii(v, u)] = 1;
        }
        scanf("%d", &x);
        bfs(x);
        bool first = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == x) continue;
            if (!first) putchar(' ');
            if (first) first = 0;
            printf("%d", dis[i]);
        }
        putchar('\n');
    }
    return 0;
}
