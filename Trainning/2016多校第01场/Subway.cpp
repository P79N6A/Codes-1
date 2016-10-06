/*
  找到两颗树的重心，如果重心有两个就选择hash值
  相同的进行处理。
  temp[i][j]:代表以第i个重心为根的树的结点j所拥
  有的子节点的hash值
  根据temp一一匹配即可。
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
#define pii pair<ll, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
const int P = 1e8 + 7;
const int Q = 1e9 + 7;

struct Edge {
    int to, next;
}edge[2][MAXN << 1];
int head[2][MAXN], tol[2], indx[2], n, cnt;
ll p[MAXN];
struct Son {
    ll h;
    int id;
    Son(){}
    Son(ll a, int b) {
        h = a;
        id = b;
    }
    bool operator < (const Son& temp) const {
        return h < temp.h;
    }
};
vector<Son> temp[4][MAXN];
map<string, int> id[2];
string u, v;
string name[2][MAXN];

void init(int n) {
    id[0].clear();
    id[1].clear();
    tol[0] = tol[1] = indx[0] = indx[1] = cnt = 0;
    for (int i = 1; i <= n; ++i) {
        head[0][i] = head[1][i] = -1;
        for (int j = 0; j < 4; ++j) {
            temp[j][i].clear();
        }
    }
}

void addedge(int u, int v, int s) {
    edge[s][tol[s]].to = v;
    edge[s][tol[s]].next = head[s][u];
    head[s][u] = tol[s]++;
}

int getid(string s, int sta) {
    int ret = id[sta][s];
    if (ret == 0) {
        ret = id[sta][s] = ++indx[sta];
        name[sta][ret] = s;
    }
    return ret;
}

int son[2][MAXN], mxson[MAXN];
int ff[5], sz;
ll ha[5][MAXN];

void dfs(int u, int f, int s) {
    son[s][u] = 0;
    int mx = 0;
    //printf("%d\n", u);
    for (int i = head[s][u]; ~i; i = edge[s][i].next) {
        int v = edge[s][i].to;
        if (v == f) continue;
        dfs(v, u, s);
        son[s][u] += son[s][v] + 1;
        mx = max(mx, son[s][v] + 1);
    }
    mx = max(mx, n - son[s][u] - 1);
    mxson[u] = mx;
    if (mx < sz) {
        sz = mx;
    }
}

ll gethash(int flag, int u, int f, int s) {
    for (int i = head[s][u]; ~i; i = edge[s][i].next) {
        int v = edge[s][i].to;
        if (v == f) continue;
        temp[flag][u].push_back(Son(gethash(flag, v, u, s), v));
    }
    sort(temp[flag][u].begin(), temp[flag][u].end());
    ll ret = 0;
    for (int i = 0; i < temp[flag][u].size(); ++i) {
        ret = (ret * P + temp[flag][u][i].h) % Q;
    }
    if (temp[flag][u].size() == 0) ret = 1;
    return ha[flag][u] = ret;
}

int ans[MAXN];

bool solve(int x, int y, int u, int u2) {
    if (temp[x][u].size() != temp[y][u2].size()) return 0;
    for(int i=0;i<temp[x][u].size();i++){
        for(int j=i;j<temp[y][u2].size()&&temp[y][u2][j].h==temp[x][u][i].h;j++){
            swap(temp[y][u2][i].id,temp[y][u2][j].id);
            if(solve(x,y,temp[x][u][i].id, temp[y][u2][i].id)){
                goto ok;
            }
        }
        return false;
ok:
        ans[temp[x][u][i].id]=temp[y][u2][i].id;
    }
    return true;
}

void debug(int x, int u) {
    printf("%d\n", ha[x][u]);
    for (int i = 0; i < temp[x][u].size(); ++i) {
        debug(x, temp[x][u][i].id);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    while (cin >> n) {
        init(n);
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            int x = getid(u, 0), y = getid(v, 0);
            addedge(x, y, 0);
            addedge(y, x, 0);
        }
        sz = INF;
        //printf("%d\n", sz);
        dfs(1, 1, 0);
        //printf("%d\n", sz);
        for (int i = 1; i <= n; ++i) {
            if (mxson[i] == sz) {
                ff[cnt++] = i;
            }
        }
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            int x = getid(u, 1), y = getid(v, 1);
            addedge(x, y, 1);
            addedge(y, x, 1);
        }
        sz = INF;
        dfs(1, 1, 1);
        for (int i = 1; i <= n; ++i) {
            if (mxson[i] == sz) {
                ff[cnt++] = i;
            }
        }
//        for (int i = 1; i <= n; ++i) {
//            prln(i);
//            prln(head[0][i])
//            for (int j = head[0][i]; ~j; j = edge[0][j].next) {
//                printf("%d ", edge[0][j].to);
//            }
//            putchar('\n');
//        }
        if (cnt == 2) {
            gethash(0, ff[0], -1, 0);
            gethash(1, ff[1], -1, 1);
            //debug(0, ff[0]);
            //debug(1, ff[1]);
//            for (int i = 0; i < 2; ++i) prln(ha[i][ff[i]])
//            for (int i = 0; i < 1; ++i) {
//                printf("%lld\n", temp[0][718][i].id);
//            }
//            printf("%d\n", temp[0][718][1].h);
//            printf("%d\n", temp[0][ff[0]].size());
//            printf("%d\n", temp[1][ff[1]].size());
//            for (int i = 0; i < 2; ++i) prln(ha[i][ff[i]])
            solve(0, 1, ff[0], ff[1]);
            ans[ff[0]] = ff[1];
        }
        else {
            gethash(0, ff[0], -1, 0);
            gethash(1, ff[1], -1, 0);
            gethash(2, ff[2], -1, 1);
//            for (int i = 0; i < 3; ++i) prln(ha[i][ff[i]])
            if (ha[0][ff[0]] == ha[2][ff[2]]) {
                solve(0, 2, ff[0], ff[2]);
                ans[ff[0]] = ff[2];
            }
            else solve(1, 2, ff[1], ff[2]), ans[ff[1]] = ff[2];
        }
        for (int i = 1; i <= n; ++i) {
            //pr(ans[i])
            cout << name[0][i] << ' ' << name[1][ans[i]] << '\n';
        }
    }
    return 0;
}
