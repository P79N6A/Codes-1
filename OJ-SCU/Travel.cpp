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
const int MAXN = 1e5 + 111;

int n, m;
ll a, b;

map<pii, bool> edge;

ll bfs(bool flag) {
    set<int> st;
    for (int i = 2; i <= n; ++i) st.insert(i);
    set<int>::iterator it, temp;
    queue<pii> q;
    q.push(pii(0, 1));
    bool ok = 0;
    int dis = 1;
    while (q.size()) {
        if (ok) break;
        pii cur = q.front(); q.pop();
        int u = cur.second;
        for (it = st.begin(); it != st.end(); ++it) {
            int v = *it;
            if (edge[pii(u, v)] == flag) {
                q.push(pii(cur.first + 1, v));
                if (v == n) {
                    dis = cur.first + 1;
                    ok = 1;
                    break;
                }
                temp = it;
                st.erase(temp);
            }
        }
    }
    if (!ok) flag = !flag;
    return flag ? dis * a : dis * b;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int u, v;
    while (~scanf("%d%d%lld%lld", &n, &m, &a, &b)) {
        edge.clear();
        ll ans = 0;
        bool con = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            edge[pii(u, v)] = edge[pii(v, u)] = 1;
            if (u == 1 && v == n) con = 1;
            if (v == 1 && u == n) con = 1;
        }
        if (con) {
            if (a <= 2 * b) printf("%lld\n", a);
            else printf("%lld\n", bfs(0));
        }
        else {
            if (b <= 2 * a) printf("%lld\n", b);
            else printf("%lld\n", bfs(1));
        }
    }
    return 0;
}
