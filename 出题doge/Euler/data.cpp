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
const int MAXN = 1e6 + 111;

bool vis[511][511];
int u[500], v[500];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    srand((unsigned)time(NULL));
    for (int i = 0; i < 30; ++i) {
        int n = rand() % 40 + 1;
        int m = rand() % ((n * (n - 1) / 2) + 1);
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            u[cnt] = rand()%n + 1, v[cnt] = rand()%n + 1;
            if (vis[u[cnt]][v[cnt]] || u[cnt] == v[cnt]) continue;
            ++cnt;
        }
        cout << n << ' ' << cnt << "\n";
        for (int j = 0; j < cnt; ++j) {
            cout << u[j] << ' ' << v[j] << '\n';
        }
        cout << '\n';
    }
    return 0;
}
