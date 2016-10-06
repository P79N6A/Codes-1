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
const int MAXN = 1e7 + 111;

int ans[MAXN];

void init() {
    int base2 = 1, base3 = 1;
    ans[1] = 1;
    for (int i = 2; i <= 1e7; ++i) {
        int x = ans[base2] * 2 + 1, y = ans[base3] * 3 + 1;
        ans[i] = min(x, y);
        if (ans[i] == x) ++base2;
        if (ans[i] == y) ++base3;
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", ans[n]);
    }
    return 0;
}
