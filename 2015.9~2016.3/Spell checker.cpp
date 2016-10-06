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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

string dir[MAXN], f[100];
int dl = 0, fl = 0;

bool ok(int x) {
    for (int i = 0; i < dl; ++i) {
        if (f[x].length() == dir[i].length() && f[x] == dir[i]) return 1;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    while (cin >> dir[dl] && dir[dl] != "#") ++dl;
    while (cin >> f[fl] && f[fl] != "#") ++fl;

    for (int i = 0; i < fl; ++i) {
        cout << f[i];
        if (ok(i)) cout << " is correct";
        else {
            cout << ':';
            int len1 = f[i].length();
            for (int j = 0; j < dl; ++j) {
                int len2 = dir[j].length();
                int cnt = 0, k1 = 0, k2 = 0;
                if (len1 - 1 == len2) {
                    while (k1 < len1) {
                        if (f[i][k1] != dir[j][k2]) {
                            ++cnt;
                            if (cnt > 1) break;
                            ++k1;
                        }
                        else ++k1, ++k2;
                    }
                }
                else if (len1 + 1 == len2) {
                    while (k2 < len2) {
                        if (f[i][k1] != dir[j][k2]) {
                            ++cnt;
                            if (cnt > 1) break;
                            ++k2;
                        }
                        else ++k1, ++k2;
                    }
                }
                else if (len1 == len2){
                    while (k1 < len1 && k2 < len2) {
                        if (f[i][k1] != dir[j][k2]) {
                            ++cnt;
                            if (cnt > 1) break;
                        }
                        ++k1, ++k2;
                    }
                }
                if (cnt == 1) cout << ' ' << dir[j];
            }
        }
        cout << '\n';
    }
    return 0;
}
