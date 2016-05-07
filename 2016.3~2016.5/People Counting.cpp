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
const int MAXN = 111;

char s[MAXN][MAXN];
int dir[9][2] = {0, -1, 0, 0, 0, 1,
                 1, -1, 1, 0, 1, 1,
                 2, -1, 2, 0, 2, 1};
char mp[10] = {".O./|\\(.)"};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    int h, w;
    while (t --) {
        scanf("%d%d", &h, &w);
        for (int i = 0; i < h; ++i) scanf("%s", s[i]);
        int ans = 0;
        for (int i = -2; i < h; ++i) {
            for (int j = -2; j <= w; ++j) {
                bool flag = 0;
                for (int k = 0; k < 9; ++k) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                        if (s[nx][ny] != '.' && s[nx][ny] == mp[k]) {
                            s[nx][ny] = '.';
                            flag = 1;
                        }
                    }
                }
                if (flag) ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
