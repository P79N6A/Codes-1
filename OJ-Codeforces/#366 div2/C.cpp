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
const int MAXN = 3e5 + 111;

int val[MAXN], n, q, cnt;
int len[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
vector<int> G[MAXN];

void add(int x, int add) {
    for (int i = x; i <= cnt; i += i & -i) {
        val[i] += add;
    }
}

int get(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ret += val[i];
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int mx = 0, x, type;
    scanf("%d%d", &n, &q);
    cnt = 0;
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] == 1) {
            c[i] = ++cnt;
        }
    }
    for (int i = 1; i <= q; ++i) {
        type = a[i], x = b[i];
        if (type == 1) {
            G[x].push_back(c[i]);
            add(c[i], 1);
        }
        else if (type == 2) {
            for (int &j = len[x]; j < G[x].size(); ++j) {
                int v = G[x][j];
                add(v, -1);
            }
        }
        else {
            mx = max(mx, x);
        }
        printf("%d\n", get(cnt) - get(mx));
    }
    return 0;
}
