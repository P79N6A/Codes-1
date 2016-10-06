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
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    string s;
    while (cin >> s) {
        string num;
        int i, p = 0, judge = 1;
        for (i = 0; i < s.length(); ++i) {
            if (s[i] == 'e') {
                num = s.substr(0, i);
                ++i;
                break;
            }
            if (s[i] == '.') {
                p = i;
            }
        }
        string base = s.substr(i, s.length() - i);
        int x = 0;
        for (int j = p + 1; j < i - 1; ++j) {
            if (s[j] != '0') {
                judge = 0;
                break;
            }
        }
        for (int i = 0; i < base.length(); ++i) {
            x *= 10;
            x += base[i] - '0';
        }
        int lef = num.length() - p - 1;
        if (lef <= x) {
            for (int i = 0; i < num.length(); ++i) {
                if (num[i] == '.') continue;
                cout << num[i];
            }
            for (int i = 0; i < x - lef; ++i) cout << 0;
        }
        else {
            int cnt = 0;
            p += x;
            for (int i = 0; i < num.length(); ++i) {
                if (num[i] == '.') continue;
                cout << num[i];
                if (++cnt == p) {
                    if (judge) {
                        break;
                    }
                    cout << '.';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
