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

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int k;
    cin >> k;
    string s;
    int mi = INF;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        cin >> s;
        int cnt = 0;
        int tol = 0;
        for (int j = s.length() - 1; j >= 0; --j) {
            if (s[j] == 'o') {
                tol += cnt;
                ans += cnt + 1;
                cnt = 0;
            }
            else ++cnt;
        }
        mi = min(tol, mi);
    }
    cout << ans + mi << '\n';
    return 0;
}
