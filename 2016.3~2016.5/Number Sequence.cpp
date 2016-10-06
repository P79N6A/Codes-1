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

const int MAXN = 1e6 + 111;

int s[MAXN], p[MAXN], nxt[MAXN];
int n, m;

void init() {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < m - 1;) {
        while (k != -1 && p[i] != p[k]) k = nxt[k];
        ++i;
        ++k;
        if (p[i] != p[k]) nxt[i] = k;
        else nxt[i] = nxt[k];
    }
}

int solve() {
    int j = 0;
    int i = 0;
    while (i < n && j < m) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++j;
        ++i;
    }
    if (j == m) return i - m + 1;
    return -1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t --) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> s[i];
        for (int i = 0; i < m; ++i) cin >> p[i];
        init();
        cout << solve() << '\n';
    }
    return 0;
}
