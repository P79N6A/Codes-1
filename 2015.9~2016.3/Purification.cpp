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
const int MAXN = 111;

char mp[MAXN][MAXN];
bool rok[MAXN], cok[MAXN];
int rcnt, ccnt;

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> (mp[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (mp[i][j] == '.') { rok[i] = cok[j] = 1; }

    for (int i = 1; i <= n; ++i) {
        if (rok[i]) ++rcnt;
        if (cok[i]) ++ccnt;
    }

    if (ccnt == n || rcnt == n) {
        if (ccnt == n) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j) {
                    if (mp[j][i] == '.') {
                        cout << j << ' ' << i << '\n';
                        j = n;
                    }
                }
        }
        else {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j) {
                    if (mp[i][j] == '.') {
                        cout << i << ' ' << j << '\n';
                        j = n;
                    }
                }
        }
    }
    else cout << -1 << '\n';
    return 0;
}
