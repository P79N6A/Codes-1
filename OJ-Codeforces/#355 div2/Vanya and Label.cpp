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
const int mod = 1e9 + 7;

ll num[80];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) {
            for (int k = 0; k < 64; ++k) {
                if ((k & j) == i) ++num[i];
            }
        }
        //num[i] += num[i] - 1;
        //pr(num[i]);
    }
    string s;
    while (cin >> s) {
        ll ans = 1;
        for (int i = 0; i < s.length(); ++i) {
            int x = 0;
            if (isdigit(s[i])) {
                x = s[i] - '0';
            }
            else if (isupper(s[i])) {
                x = s[i] - 'A' + 10;
            }
            else if (islower(s[i])) {
                x = s[i] - 'a' + 36;
            }
            else if (s[i] == '-') x = 62;
            else x = 63;
            ans = (ans * num[x]) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
