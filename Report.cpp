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
const int MAXN = 2e5 + 111;

int a[MAXN], b[MAXN], t[MAXN], r[MAXN];

int main()
{
    int n, m, s = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        int ri, ti;
        scanf("%d%d", &ti, &ri);
        while (s > 0 && r[s - 1] <= ri) --s;
        t[s] = ti, r[s] = ri, ++s;
    }

    sort(a, a + r[0]);
    for (int i = 0; i < r[0]; ++i) b[i] = a[i];

    int bl = 0, br = r[0];
    r[s] = 0;
    ++s;
    for (int i = 1; i < s; ++i) {
        for (int j = r[i - 1]; j > r[i]; --j)
            a[j - 1] = (t[i - 1] == 1) ? b[--br] : b[bl++];
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
