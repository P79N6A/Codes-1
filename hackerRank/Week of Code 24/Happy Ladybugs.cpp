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
const int MAXN = 26;

int num[MAXN];
string s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; cin >> t;
    while (t --) {
        memset(num, 0, sizeof num);
        bool have = 0;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            if (isalpha(s[i])) {
                ++num[s[i] - 'A'];
            }
            else have = 1;
        }
        bool flag = 1;
        if (have) {
            for (int i = 0; i < 26; ++i) {
                if (num[i] == 1) {
                    flag = 0;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (!(i > 0 && s[i] == s[i - 1]) && !(i < n - 1 && s[i] == s[i + 1])) {
                    flag = 0;
                    break;
                }
            }
        }
        cout << (flag? "YES" : "NO") << '\n';
    }
    return 0;
}
