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
const int MAXN = 1e3 + 111;

int x[MAXN];
pii low[MAXN * MAXN], up[MAXN * MAXN];

void preWork(int n) {
    for (int i = 0; i < n; ++i)
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
        preWork(n);
    }
    return 0;
}
