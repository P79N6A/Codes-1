/*
 很容易想到缩点和标记块中最大值，然后答案的左边一定是
 桥两边最大值的最小值。然后到这里队友问：可是桥两边的
 块不是还要延伸出去= =。然后我就被问住了。
 其实，延伸出去的部分可以根据树的特点从最高值的块向下
 遍历。答案是：两边最大值的最小值， 两边最大值的最小值+1
 这点根据树边划分树为两块可以知道。
 dp实在太机智了，从最高值向下，一次即可完成。
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

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct Edge {
    int from, to, next;
}edge[MAXN << 1];
int head[MAXN], tol;
vector<int> G[MAXN];
void addedge(int u, int v) {
    edge[tol].from = u;
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

int id[MAXN], dfn[MAXN], low[MAXN], sta[MAXN], top, indx, scc, mx[MAXN];
bool in[MAXN];

inline void init(int n) {
    tol = top = indx = scc = 0;
    for (int i = 1; i <= n; ++i) {
        dfn[i] = 0;
        mx[i] = 0;
        G[i].clear();
        head[i] = -1;
    }
}

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++indx;
    sta[top++] = u;
    in[u] = 1;
    int v;
    for (int i = head[u]; ~i; i = edge[i].next) {
        v = edge[i].to;
        if (f == v) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            v = sta[--top];
            in[v] = 0;
            mx[scc] = max(mx[scc], v);
            id[v] = scc;
        } while (u != v);
    }
}

void dfs(int u, int f) {
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == f) continue;
        dfs(v, u);
        mx[u] = max(mx[u], mx[v]);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        init(n);
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        tarjan(1, 1);
        for (int i = 0; i < m; ++i) {
            u = edge[i * 2].from, v = edge[i * 2].to;
            u = id[u], v = id[v];
            if (u != v) {
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
//        for (int i = 1; i <= n; ++i) pr(mx[i]);
        int rt = 0;
        for (int i = 1; i <= scc; ++i) if (mx[i] == n) rt = i;
        dfs(rt, rt);
//        for (int i = 1; i <= n; ++i) pr(mx[i]);
        for (int i = 0; i < m; ++i) {
            int x = i * 2;
            u = edge[x].from, v = edge[x].to;
            u = id[u], v = id[v];
            int mi = min(mx[u], mx[v]);
            if (u == v) printf("0 0\n");
            else printf("%d %d\n", mi, mi + 1);
        }
    }
    return 0;
}

/*
                   @,
                '@' @
              @@     @
            @@        @                      .
           @@         @@@@@@@@@@@@@@@@@      @@
         @@                         .@      @@  @@
        @@                         `@.      @   @@
       @;@@               @    @@@@@.       @, @@
      @@@ @@@@@@@@@@#   ;@'@ ,@@@@ @@`    `@@@    @@,
     @@#;@@      @@#@@@, @:, @. `@  :@`     #,  +@@
     @ ;@,        .#: ;@             ,@        @@
    @@ @.         @@`                 '@      @'
    @ @@                       @@@;    @@     @  `#@@
   #@ @             ,@@@@      `;+@@@@, @`    @@@@@`
   @.;@          +@@@+`         `..  +@@@@    @'
   @          ,@@@.     `'@@@@@@@@@@    @@     .
  +@        ;@@:    .@@@@          @:    @@@'  @@@@@@
  @:       @@`     @@#`            +@    @@ @` @   `'
  @      '@,      ,@               `@    @@ '@ @@,  ;
 .@     @          @'               @     @@#     `@@
 ,@   @@@@         .@               @`    ;@
 .@  @@  @'         @.              @:    :@
  @ `@  :@          '@              @#    ;@
  @  @@@@`           @              +@    +@
  @@                  @             `@    @
   @;                  @             @   @:
   `@                  @+            @  #@
     @,                 @#           @ @,
      @@               @ @@          @ @ ;@@@@@@@@@
       @@@@@@@@'       @# @         `@`@@@@+,`    @#
        @@  @ ,@@@      @ #@        .@`@          @#
         @@ @    @@@    @# @#       #@`@     @ ,@@@
           @@     @ `@'  @@ .@     :@ @@ @@.:@  @
            @'    @       @@ ,@+  .@` @@@ #@@@ @@
           `@@'   @        @@  @@@@, @@ @,  .:@@
            @+@@  @         @@@`   @@@  ,@@@@@:
            @'@@@ @;@         @@@@@@     @
            @:@ @#@#@                    #@
            @:@@` @,@                     `@@;
*/
