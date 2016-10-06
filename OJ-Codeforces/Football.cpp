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
const int MAXN = 1111;

bool mp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    if (n * (n - 1) / 2 < n * k) cout << -1 << '\n';
    else {
        cout << n * k << '\n';
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int j = 1; j <= n; ++j) {
                if (i == j || mp[i][j]) continue;
                mp[i][j] = mp[j][i] = 1;
                cout << i << ' ' << j << '\n';
                if (++cnt == k) break;
            }
        }
    }
    return 0;
}
