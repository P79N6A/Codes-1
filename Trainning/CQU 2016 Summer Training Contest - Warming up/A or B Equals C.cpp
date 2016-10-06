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
const int MOD = 1e9 + 7;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n;
    cin >> t;
    string s1, s2;
    while (t --) {
        cin >> n;
        cin >> s1 >> s2;
        string s3 = s1;
        bool flag = 0;
        ll ans = 1;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '1' && s2[i] == '0') {
                flag = 1;
                break;
            }
            if (s1[i] == '1' && s2[i] == '1') ans = (ans * 2) % MOD;
        }
        if (flag) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << ans << '\n';
        }
    }
    return 0;
}
