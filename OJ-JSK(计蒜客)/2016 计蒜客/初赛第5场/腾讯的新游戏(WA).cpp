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
const int MAXN = 111 + 1e3;

int m[MAXN];
int evil[MAXN][MAXN];
int temp[MAXN];
int temp2[MAXN];
struct P {
    int mi, num;
    bool operator < (const P&t)const {
        if (mi == t.mi) return num > t.num;
        return mi < t.mi;
    }
}p[MAXN];
int n, q;

int solve() {
    for (int i = 1; i <= n; ++i) {
        p[i].mi = 0;
        for (int j = 0; j < m[i]; ++j) {
            p[i].mi = max(p[i].mi, evil[i][j] - j);
        }
        p[i].num = m[i];
    }
    sort(p + 1, p + n + 1);
    int ret = p[1].mi;
    int sum = p[1].num;
    for (int i = 2; i <= n; ++i) {
        if (ret + sum < p[i].mi) {
            ret = p[i].mi;
        }
        sum += p[i].num;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m[i]);
        for (int j = 0; j < m[i]; ++j) {
            scanf("%d", &evil[i][j]);
        }
    }
    int x, a, y, b;
    scanf("%d", &q);
    while (q --) {
        scanf("%d%d%d%d", &x, &a, &y, &b);
        int cnt = 0, cnt2 = 0;
        for (int i = 0; i < min(m[x], a); ++i) {
            temp[cnt++] = evil[x][i];
        }
        for (int i = b; i < m[y]; ++i) {
            temp[cnt++] = evil[y][i];
        }
        for (int i= 0; i < min(m[y], b); ++i) {
            temp2[cnt2++] = evil[y][i];
        }
        for (int i = a; i < m[x]; ++i) {
            temp2[cnt2++] = evil[x][i];
        }
        for (int i = 0; i < cnt; ++i) {
            evil[y][i] = temp[i];
        }
        m[y] = cnt;
        for (int i = 0; i < cnt2; ++i) {
            evil[x][i] = temp2[i];
        }
        m[x] = cnt2;
        /*for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m[i]; ++j) {
                cout << evil[i][j] << ' ';
            }
            cout << '\n';
        }*/
        printf("%d\n", solve());
    }
    return 0;
}
