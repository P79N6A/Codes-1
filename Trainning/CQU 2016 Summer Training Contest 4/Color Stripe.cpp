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
const int MAXN = 5e5 + 111;

string s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k >> s;
    if (k == 2) {
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2) {
                if (s[i] == 'A') ++ans1;
                else ++ans2;
            }
            else {
                if (s[i] == 'A') ++ans2;
                else ++ans1;
            }
        }
        if (ans1 > ans2) {
            cout << ans2 << '\n';
            for (int i = 0; i < n; ++i) {
                if (i % 2) cout << 'A';
                else cout << 'B';
            }
        }
        else {
            cout << ans1 << '\n';
            for (int i = 0; i < n; ++i) {
                if (i % 2) cout << 'B';
                else cout << 'A';
            }
        }
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ++ans;
            bool flag = 0;
            for (int j = 0; j < k; ++j) {
                if (j != s[i - 1] - 'A' && j != s[i + 1] - 'A') {
                    s[i] = j + 'A';
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                s[i] = s[i + 1];
            }
        }
    }
    cout << ans << '\n';
    cout << s << '\n';
    return 0;
}
