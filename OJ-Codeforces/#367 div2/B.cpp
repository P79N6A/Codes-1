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
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int sum[MAXN];

void add(int x, int val) {
    for (int i = x; i < MAXN; i += i & -i) {
        sum[i] += val;
    }
}

int get(int x) {
    int ret = 0;
    for (int i = x; i >= 1; i -= i & -i) {
        ret += sum[i];
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, x, q; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        add(x, 1);
    }
    cin >> q;
    while (q --) {
        cin >> x;
        x = min(x, MAXN - 10);
        cout << get(x) << '\n';
    }
    return 0;
}
