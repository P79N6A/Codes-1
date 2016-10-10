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
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int s, t, a, b, m, n, x;
    scanf("%d%d%d%d%d%d", &s, &t, &a, &b, &m, &n);
    int apple = 0, orange = 0;
    while (m --) {
        scanf("%d", &x);
        int nx = a + x;
        if (s <= nx && nx <= t) {
            ++apple;
        }
    }
    while (n --) {
        scanf("%d", &x);
        int nx = b + x;
        if (s <= nx && nx <= t) {
            ++orange;
        }
    }
    printf("%d\n%d\n", apple, orange);
    return 0;
}
