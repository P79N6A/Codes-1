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
const int MAXN = 1e5 + 111;

string s;
char d[5] = "UDLR";
int dir[4];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i] == d[j]) {
                ++dir[j];
                break;
            }
        }
    }
    int l = abs(dir[0] - dir[1]), r = abs(dir[2] - dir[3]);
    int ans = l / 2 + r / 2;
    if (l % 2 == r % 2)
        cout << ans + l % 2 << '\n';
    else cout << -1 << '\n';
    return 0;
}
