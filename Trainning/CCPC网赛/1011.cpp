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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

bool vis[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, kase = 0; cin >> t;
    string s;
    while (t --) {
        cin >> s;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < s.length(); ++i) {
            vis[s[i] - 'a'] = 1;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (vis[i]) ++ans;
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
