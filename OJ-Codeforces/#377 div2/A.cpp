#include <bits/stdc++.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int k, r; cin >> k >> r;
    int sum = 0;
    for (int i = 1; ; ++i) {
        sum += k;
        sum %= 10;
        if (sum == r || !sum) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
