#include<algorithm>
#include<bitset>
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
    int n;
    string s;
    cin >> n >> s;
    int ans1 = 0, ans2 = 0;
    bool in = 0;
    int len = 0, num = 0;
    for (int i = 0; i < n; ++i) {
        if (isalpha(s[i])) {
            ++len;
        }
        else if (s[i] == '(') {
            in = 1;
            ans1 = max(ans1, len);
            len = 0;
        }
        else if (s[i] == ')') {
            in = 0;
            if (len)
                ++num;
            ans2 += num;
            num = 0;
            len = 0;
        }
        else {
            if (in) {
                if (len)
                    ++num;
                len = 0;
            }
            else {
                ans1 = max(ans1, len);
                len = 0;
            }
        }
    }
    cout << max(len, ans1) << ' ' << ans2 << '\n';
    return 0;
}
