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

string org[4];
string mp[4];
int ans;

bool judge() {
    char jd = mp[0][0];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) if (mp[i][j] != jd)
            return 0;
    return 1;
}

int main()
{
    for (int i = 0; i < 4; ++i) cin >> org[i];
    ans = INF;
    int up = 1 << 16;
    for (int i = 0; i < up; ++i) {

        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                mp[j][k] = org[j][k];

        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k) {
                if (i & (1 << (j * 4 + k))) {
                    mp[j][k] = (mp[j][k] == 'b' ? 'w' : 'b');
                    if (j > 0) mp[j - 1][k] = (mp[j - 1][k] == 'b' ? 'w' : 'b');
                    if (j < 3) mp[j + 1][k] = (mp[j + 1][k] == 'b' ? 'w' : 'b');
                    if (k > 0) mp[j][k - 1] = (mp[j][k - 1] == 'b' ? 'w' : 'b');
                    if (k < 3) mp[j][k + 1] = (mp[j][k + 1] == 'b' ? 'w' : 'b');
                }
            }

        if (judge()) ans = min(ans, __builtin_popcount(i));
    }
    if (ans == INF) cout << "Impossible\n";
    else cout << ans << '\n';
    return 0;
}
