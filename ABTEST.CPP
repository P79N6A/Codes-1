/***************************************
      zzblack                         **
      2016-03-11                      **
      Orz                             **
****************************************/
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id<<1,l,mid
#define rs id<<1|1,mid+1,r
#define OFF(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(x) memset(x,0x3f,sizeof x)
typedef long long ll ;
typedef pair<int,int> pii ;
const int maxn = 1e5 + 50 ;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f ;
const int MOD = 1e9+7 ;

inline int read(){
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int Hash[maxm];

int Lv[maxn], head[maxn], st, ed, cnt;
int cap[maxm], pnt[maxm], nxt[maxm], cur[maxn];

void add_edge(int u, int v, int c) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    cap[cnt] = c;
    head[u] = cnt++;
}

void add_edges(int u, int v, int c) {
    add_edge(u, v, c);
    add_edge(v, u, 0);
}

bool bfs(){
    CLR(Lv);
    Lv[st] = 1;
    queue<int> q;
    q.push(st);
    while (q.size()) {
        int u = q.front();q.pop();
        for (int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            if (Lv[v] || cap[i] <= 0) continue ;
            Lv[v] = Lv[u] + 1;
            q.push(v);
        }
    }
    return Lv[ed];
}

int dfs(int u, int f) {
    if (f == 0 || u == ed) return f;
    int left = f;
    for (int i = head[u]; ~i; i = nxt[i]) {
//        cur[u] = i;
        int v = pnt[i];
        if (Lv[v] != Lv[u] + 1 || cap[i] <= 0) continue ;
        int d = dfs(v, min(cap[i], left));
        if (d > 0) {
            cap[i] -= d;
            cap[i ^ 1] += d;
            left -= d;
            if (left == 0) break;
        } else Lv[v] = 0;
    }
    return f - left;
}

int Max_Flow(){
    int res = 0;
    while (bfs()) {
//        for (int i = 0; i <= n; i++)
//            cur[i] = head[i];
        res += dfs(st, inf);
    }
    return res;
}

void init() {
    OFF(head);
    cnt = 0;
    CLR(Hash);
}

int s[maxn], e[maxn];
int dur[maxn];
int n, m;

int main () {
#ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif

    while (~scanf("%d%d", &n, &m)) {
        init();
        st = 0;
        Hash[1] = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            int num, t;
            s[i] = read(), num = read();
            e[i] = read(), t = read();
            add_edges(st, i, num * t);
            sum += num * t;
            Hash[s[i]]++; Hash[e[i]]++;
        }
        int tot = 2 * n + 1 - Hash[1], last = 1;
        int Cnt = 1;
        for (int i = 2; tot; i++) {
            if (!Hash[i]) continue;
            tot -= Hash[i];
            dur[Cnt] = i - last;
            last = i;
            Hash[i] = Cnt++;
        }
        Hash[1] = 0;
        ed = n + Cnt;
        for (int i = 1; i < Cnt; i++) add_edges(i + n, ed, dur[i] * m);

        for (int i = 1; i <= n; i++) {
            for (int j = Hash[s[i]] + 1; j <= Hash[e[i]]; j++)
                add_edges(i, j + n, dur[j] * m);
        }
        int ans = Max_Flow();
        if( ans == sum) puts("Yes");
        else puts("No");

    }

	return 0;
}
