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

string s;
int num[26];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> s) {
        if (s.length() < 26) {
            cout << -1 << '\n';
            continue;
        }
        bool have = 1;
        int l = 0, r = 25;
        memset(num, 0, sizeof num);
        for (int i = 0; i < 26; ++i) {
            if (s[i] == '?') continue;
            int u = s[i] - 'A';
            if (++num[u] > 1) {
                have = 0;
            }
        }
        if (!have) {
            for (int i = 26; i < s.length(); ++i) {
                if (s[i] != '?') {
                    int v = s[i] - 'A';
                    ++num[v];
                }
                if (s[i - 26] != '?') {
                    int v = s[i - 26] - 'A';
                    --num[v];
                }
                bool flag = 1;
                for (int j = 0; j < 26; ++j) {
                    if (num[j] > 1) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    have = 1;
                    l = i - 25, r = i;
                    break;
                }
            }
        }
        if (!have) cout << -1 << '\n';
        else {
            memset(num, 0, sizeof num);
            for (int i = l; i <= r; ++i) if (s[i] != '?') ++num[s[i] - 'A'];
            for (int i = l; i <= r; ++i) {
                if (s[i] == '?') {
                    for (int j = 0; j < 26; ++j) {
                        if (++num[j] == 1) {
                            s[i] = j + 'A';
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < s.length(); ++i) if (s[i] == '?') s[i] = 'A';
            cout << s << '\n';
        }
    }
    return 0;
}
