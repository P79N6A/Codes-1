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

int x[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s;
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int ans = INF;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            ans = min(ans, x[i + 1] - x[i]);
        }
    }
    if (ans == INF) cout << -1 << '\n';
    else cout << ans / 2 << '\n';
    return 0;
}
