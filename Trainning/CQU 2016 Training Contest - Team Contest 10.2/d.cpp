#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int maxn = 400;

int head[maxn];
int p[6][105];
int dp[6][105][5][205];

struct Node {
    int u, v, w, cost, nxt;
}node[maxn * 2];

struct Po {
    int uni, city, bag, time;
    Po (int uni = 0, int city = 0, int bag = 0, int time = 0) :
        uni(uni), city(city), bag(bag), time(time) {}
    bool operator < (const Po& rh) const {
        return time > rh.time;
    }
};

void add_edge(int u, int v, int w, int cost, int tot) {
    node[tot].u = u; node[tot].v = v;
    node[tot].w = w; node[tot].cost = cost;
    node[tot].nxt = head[u];
    head[u] = tot;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    int kase = 1;
    while(t--) {
        int n, m, b, k, r, t;
        scanf("%d%d%d%d%d%d", &n, &m, &b, &k, &r, &t);
        for(int i = 0; i < k; i++)
            for(int j = 1; j <= n; j++) scanf("%d", &p[i][j]);
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= m; i++) {
            int u, v, w, cost;
            scanf("%d%d%d%d", &u, &v, &w, &cost);
            add_edge(u, v, w, cost, i);
        }
        memset(dp, -1, sizeof(dp));
        priority_queue<Po> pq;
        dp[0][1][0][0] = r;
        pq.push(Po(0, 1, 0, 0));
        while(pq.size()) {
            Po temp = pq.top(); pq.pop();
            int uni = temp.uni;
            int city = temp.city;
            int bag = temp.bag;
            int time = temp.time;
            int money = dp[uni][city][bag][time];

            for(int i = head[city]; i != -1; i = node[i].nxt) {
                int v = node[i].v;
                if(v != n && v != 1 && bag < b && money >= p[uni][v] + node[i].cost && time + node[i].w <= t) {
                    if(dp[uni][v][bag + 1][time + node[i].w] < money - node[i].cost - p[uni][v]) {
                        dp[uni][v][bag + 1][time + node[i].w] = money - node[i].cost - p[uni][v];
                        pq.push(Po(uni, v, bag + 1, time + node[i].w));
                    }
                }
                if(v != 1 && v != n && money >= node[i].cost && time + node[i].w <= t && bag) {
                    if(dp[uni][v][bag - 1][time + node[i].w] < money - node[i].cost + p[uni][city]) {
                        dp[uni][v][bag - 1][time + node[i].w] = money - node[i].cost + p[uni][city];
                        pq.push(Po(uni, v, bag - 1, time + node[i].w));
                    }
                }
                if(money >= node[i].cost && time + node[i].w <= t) {
                    if(dp[uni][v][bag][time + node[i].w] < money - node[i].cost) {
                        dp[uni][v][bag][time + node[i].w] = money - node[i].cost;
                        pq.push(Po(uni, v, bag, time + node[i].w));
                    }
                }
            }
            if(time < t) {
                int taruni = (uni + 1) % k;
                if(dp[taruni][city][bag][time + 1] < money) {
                    time++; uni = taruni;
                    int v = city;
                    if(v != n && v != 1 && bag < b && money >= p[uni][v] && time <= t) {
                        if(dp[uni][v][bag + 1][time] < money - p[uni][v]) {
                            dp[uni][v][bag + 1][time] = money - p[uni][v];
                            pq.push(Po(uni, v, bag + 1, time));
                        }
                    }
                    if(v != 1 && v != n && money >= 0 && time <= t && bag) {
                        if(dp[uni][v][bag - 1][time] < money + p[uni][city]) {
                            dp[uni][v][bag - 1][time] = money + p[uni][city];
                            pq.push(Po(uni, v, bag - 1, time));
                        }
                    }
                    if(money >= 0 && time <= t) {
                        if(dp[uni][v][bag][time] < money) {
                            dp[uni][v][bag][time] = money;
                            pq.push(Po(uni, v, bag, time));
                        }
                    }
                }
            }
        }
        int ans = -1;
        for(int i = 0; i <= t; i++) ans = max(ans, dp[0][n][0][i]);
        printf("Case #%d: ", kase++);
        if(ans == -1)
            printf("Forever Alone\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
