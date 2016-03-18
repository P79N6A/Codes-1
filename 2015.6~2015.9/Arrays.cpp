#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e5 + 111;
int a[MAXN], b[MAXN], k, m, na, nb;

int main()
{
    cin >> na >> nb >> k >> m;
    for (int i = 0; i < na; ++i) cin >> a[i];
    for (int i = 0; i < nb; ++i) cin >> b[i];
    sort(a, a + na);
    sort(b, b + nb);
    if (a[k - 1] < b[nb - m])
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
