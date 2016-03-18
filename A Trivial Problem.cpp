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
#define ll unsigned long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    int m;
    while (cin >> m) {
        int r = 5e5, l = 1, ans = 0;
        while (l < r) {
            int mid = (l + r) / 2;
            int t = mid;
            int sum = 0;
            while (t / 5 != 0) {
                t /= 5;
                sum += t;
            }
            if (sum > m) r = mid - 1;
            else if (sum < m) l = mid + 1;
            else {
                ans = mid;
                break;
            }
        }
        if (ans) {
            cout << 5 << '\n';
            if (ans % 10 < 5) {
                ans /= 10;
                for (int i = 0; i < 5; ++i) {
                    if (ans) cout << ans;
                    cout << i;
                    if (i != 4) cout << ' ';
                    else cout << '\n';
                }
            }
            else {
                ans /= 10;
                for (int i = 5; i < 10; ++i) {
                    if (ans) cout << ans;
                    cout << i;
                    if (i != 9) cout << ' ';
                    else cout << '\n';
                }
            }
        }
        else cout << ans << '\n';
    }
    return 0;
}
