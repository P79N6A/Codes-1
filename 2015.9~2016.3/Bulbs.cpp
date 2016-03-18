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

bool ok[MAXN];

int main()
{
    int n, m, num, x;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        for (int j = 0; j < num; ++j) {
            cin >> x;
            ok[x] = 1;
        }
    }
    bool flag = 0;
    for (int i = 1; i <= m; ++i) if (ok[i] == 0) flag = 1;
    if (flag) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
