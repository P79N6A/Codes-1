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

int x, y;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int step = INF;
    for (int i = 0; i < k; ++i)
    {
        cin >> x >> y;
        step = min(step, min(min(x - 1, n - x), min(y - 1, m - y)));
    }
    if (step > 4) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
