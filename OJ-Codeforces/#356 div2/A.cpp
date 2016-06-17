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

int num[111];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int x;
    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        ++num[x];
        ans += x;
    }
    int mx = 0;
    for (int i = 100; i >= 1; --i) {
        if (num[i] >= 2) {
            mx = max(i * min(num[i], 3), mx);
        }
    }
    cout << ans - mx << '\n';
    return 0;
}
