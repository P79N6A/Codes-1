#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 11;
int mp[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; cin >> t;
    while (t --)
    {
        for (int i = 1; i <= 9; i += 2)
            for (int j = 1; j <= i; j += 2)
                cin >> mp[i][j];
        for (int i = 9; i >= 3; i -= 2)
            for (int j = 1; j <= i - 2; j += 2)
            {
                int a = mp[i][j], b = mp[i][j + 2], c = mp[i - 2][j];
                mp[i][j + 1] = (c - a - b) / 2;
                mp[i - 1][j] = a + mp[i][j + 1];
                mp[i - 1][j + 1] = b + mp[i][j + 1];
            }
        for (int i = 1; i <= 9; ++i)
        {
            cout << mp[i][1];
            for (int j = 2; j <= i; ++j)
                cout << ' ' << mp[i][j];
            cout << '\n';
        }
    }
    return 0;
}
