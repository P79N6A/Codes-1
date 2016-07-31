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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 210;

struct P {
    int cap, id;
    double x, y, z;
    P() {}
    P(int a, int b, double c) {
        id = a; cap = b; x = c;
    }
    void read() {
        scanf("%d%d%lf%lf%lf", &id, &cap, &x, &y, &z);
    }
    bool operator < (const P&t)const {
        if (x == t.x) return cap > t.cap;
        return x < t.x;
    }
}boy[MAXN], girl[MAXN];

int len[MAXN];
vector<P> glike[MAXN], blike[MAXN];
int match[MAXN], n;

double getdis(int a, int b) {
    P &t1 = boy[a], &t2 = girl[b];
    double dx = t1.x - t2.x;
    double dy = t1.y - t2.y;
    double dz = t1.z - t2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// 不断给男士匹配女士，用len数组记录下标，已经被拒绝过的女士不可能再匹配了。
void GaleShapley(){
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        match[i] = -1;
        len[i] = 0;
        q.push(i);
    }
    while (q.size()) {
        int bid = q.front(); q.pop();
        for (int &i = len[bid]; i < blike[bid].size(); ++i) {
            int gid = blike[bid][i].id;
            if (match[gid] == -1) {
                match[gid] = bid;
                break;
            }
            int j;
            for (j = 0; j < n; ++j) {
                if (glike[gid][j].id == bid || glike[gid][j].id == match[gid])
                    break;
            }
            if (glike[gid][j].id == bid) {
                q.push(match[gid]);
                match[gid] = bid;
                break;
            }
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int t, kk = scanf("%d", &t); kk <= t; ++kk) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) boy[i].read(), blike[i].clear();
        for (int i = 1; i <= n; ++i) girl[i].read(), glike[i].clear();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                double dis = getdis(i, j);
                blike[boy[i].id].push_back(P(girl[j].id, girl[j].cap, dis));
                glike[girl[j].id].push_back(P(boy[i].id, boy[i].cap, dis));
            }
        }
        for (int i = 1; i <= n; ++i) {
            sort(blike[i].begin(), blike[i].end());
            sort(glike[i].begin(), glike[i].end());
        }
        GaleShapley();
        for (int i = 1; i <= n; ++i) {
            printf("%d %d\n", match[i], i);
        }
        putchar('\n');
    }
    return 0;
}
