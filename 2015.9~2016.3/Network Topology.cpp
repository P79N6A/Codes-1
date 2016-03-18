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
const int MAXN = 1e5 + 111;

int in[MAXN], out[MAXN];

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        ++out[u];
        ++in[u];
        ++out[v];
        ++in[v];
    }

    int x = 0, y = 0, z = 0, mx = 1;
    for (int i = 1; i <= n; ++i) {
        //cout << in[i] << ' ' << out[i] << endl;
        if (in[i] > in[mx]) mx = i;
        if (in[i] == 2 && out[i] == 2) {
            ++x;
        }
        else if (in[i] + out[i] == 2) {
            if (in[i] == 1) ++y;
        }
    }

    if (x == n) {cout << "ring topology\n"; return 0;}
    if (y == 2 && x == n - 2) {cout << "bus topology\n"; return 0;}
    if (y == n - 1 && in[mx] == n - 1) {cout << "star topology\n"; return 0;}
    cout << "unknown topology\n"; return 0;
}
