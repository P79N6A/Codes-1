/* 题意：
 * 求从s到t的最短时间，期间道路会开放和关闭
 */
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
    int v, t;
    vector<int> time;
};
vector<P> G[MAXN];
int temp[MAXN], dis[MAXN];
bool in[MAXN];

void spfa(int s, int t) {
    memset(in, 0, sizeof in);
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    q.push(s);
    in[s] = 1;
    dis[s] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            P p = G[u][i];
            int v = p.v, t = p.t;
            for (int j = 0; j < p.time.size(); j += 2) {
                int open = p.time[j], close = p.time[j + 1];
                int base = max(dis[u], open); // 等到开放时间进入
                if (base + t > close) continue; // 从开放时间进入但无法出来
                if (dis[v] > base + t) {
                    dis[v] = base + t;
                    if (!in[v]) {
                        in[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    if (dis[t] == INF) cout << "*\n";
    else cout << dis[t] << '\n';
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, m, st, ed, x;
    while (cin >> n >> m >> st >> ed) {
        cin.ignore();
        for (int i = 1; i <= n; ++i) G[i].clear();
        string s;
        while (m --) {
            getline(cin, s);
            stringstream ss(s);
            P p;
            int cnt = 0;
            while (ss >> temp[cnt]) ++cnt;
            p.time.push_back(0); // 添加开放时间,这样偶数是开放，奇数是关闭
            for (int i = 3; i < cnt; ++i) p.time.push_back(temp[i]);
            p.time.push_back(INF);
            p.v = temp[1], p.t = temp[2];
            /*for (int i = 0; i < cnt; ++i) cout << temp[i] << ' ';
            cout << '\n';*/
            G[temp[0]].push_back(p);
            p.v = temp[0];
            G[temp[1]].push_back(p);
        }
        spfa(st, ed);
    }
    return 0;
}
