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
const int MAXN = 1e3 + 111;

int num[MAXN];

int main()
{
    int n, x, up = 0;
    cin >> n;
    memset(num, 0, sizeof num);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++num[x];
        up = max(up, num[x]);
    }
    int ans = 0;
    for (int i = 0; i < up; ++i) {
        int cnt = 0;
        for (int i = 1; i <= 1000; ++i) {
            if (num[i]) {
                ++cnt;
                --num[i];
            }
        }
        ans += cnt - 1;
    }
    cout << ans << endl;
    return 0;
}
