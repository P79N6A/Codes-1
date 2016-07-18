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
const int MAXN = 111;

char mp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, m, ins, x1, x2, y1, y2;
    char c;
    int t; cin >> t;
    while (t --) {
        cin >> n >> m >> ins;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) mp[i][j] = '.';
        }
        while (ins --) {
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    mp[i][j] = c;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << mp[i][j];
            cout << '\n';
        }
    }
    return 0;
}
