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
const int MAXN = 1e5 + 111;

ll a[MAXN], b[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        b[i] = a[i] + a[i + 1];
    }
    for (int i = 0; i < n; ++i) cout << b[i] << ' ';
    return 0;
}
