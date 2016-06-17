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

int num[111];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> num[i];
    int ans = (num[x] == 1);
    int l = x - 1, r = x + 1;
    while (l >= 1 || r <= n) {
        if (l >= 1) {
            if (r <= n) {
                if (num[r] == num[l] && num[r] == 1) ans += 2;
                --l, ++r;
            }
            else ans += (num[l] == 1), --l;
        }
        else {
            ans += (num[r] == 1);
            ++r;
        }
    }
    cout << ans << '\n';
    return 0;
}
