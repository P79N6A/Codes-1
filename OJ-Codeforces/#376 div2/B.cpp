#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            ok = 0;
            break;
        }
        if (i != n - 1) {
            if (a[i] % 2) --a[i + 1];
        }
        else if (a[i] % 2) {
            ok = 0;
            break;
        }
    }
    printf("%s\n", ok? "YES" : "NO");
    return 0;
}
