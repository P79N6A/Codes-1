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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int n;
ll ans;
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

void dfs(int dep, ll temp, int num) {
    if (num > n) return;
    if (num == n && temp < ans) ans = temp;
    for (int i = 1; i < 64; ++i) {
        if (ans / p[dep] <= temp) break;
        dfs(dep + 1, temp *= p[dep], num * (i + 1));
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cin >> n;
    ans = 1e18;
    dfs(0, 1, 1);
    cout << ans << '\n';
    return 0;
}
