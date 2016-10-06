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
const int MAXN = 1e6 + 111;

vector<int> prime, G[2000];
int dis[MAXN];

int bfs(int s, int e) {
    queue<int> q;
    memset(dis, 0x7f, sizeof dis);
    dis[s] = 0;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (u == e) return dis[u];
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    for (int i = 1000; i < 10000; ++i) {
        bool flag = 1;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) prime.push_back(i);
    }

    for (int i = 0; i < prime.size(); ++i) {
        for (int j = i + 1; j < prime.size(); ++j) {
            int cnt = 0, a = prime[i], b = prime[j];
            for (int k = 0; k < 4; ++k) {
                if (a % 10 != b % 10) ++cnt;
                a /= 10;
                b /= 10;
            }
            if (cnt == 1) {
                //cout << prime[i] << "->" << prime[j] << '\n';
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    int kase, a, b;
    scanf("%d", &kase);
    while (kase --) {
        scanf("%d%d", &a, &b);
        a = lower_bound(prime.begin(), prime.end(), a) - prime.begin();
        b = lower_bound(prime.begin(), prime.end(), b) - prime.begin();
        cout << bfs(a, b) << '\n';
    }
    return 0;
}
