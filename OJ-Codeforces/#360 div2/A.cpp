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
const int MAXN = 111;

string s[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, d;
    while (cin >> n >> d) {
        for (int i = 1; i <= d; ++i) cin >> s[i];
        int ans = 0, num = 0;
        for (int i = 1; i <= d; ++i) {
            bool ok = 0;
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == '0') {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                ans = max(ans, ++num);
            }
            else num = 0;
        }
        ans = max(ans, num);
        cout << ans << '\n';
    }
    return 0;
}
