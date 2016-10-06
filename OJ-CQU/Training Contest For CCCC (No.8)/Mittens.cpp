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
const int MAXN = 5e3 + 111;

int col[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> col[i];
    }
    sort(col, col + n);
    int ans = 0;
    // (i + n / 2) % n: i 的个数如果小于 n / 2，那么肯定不会匹配到自己
    for (int i = 0; i < n; ++i) {
        if (col[i] != col[(i + n / 2) % n]) ++ans;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        cout << col[i] << ' ' << col[(i + n / 2) % n] << '\n';
    }
    return 0;
}
