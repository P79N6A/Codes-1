#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

vector<int> v[MAXN];

struct P{
    int h, num;
    bool operator < (const P& t)const
    {
        return h < t.h;
    }
};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, kase, n;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            v[i].claer();
            scanf("%d%d", &v[i].h, &v[i].num);
        }
        sort(v, v + n);
    }
    return 0;
}
