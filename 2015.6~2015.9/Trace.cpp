#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const double PI = acos(-1);
const int MAXN = 111;
double r[MAXN];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> r[i];
    sort(r, r + n);
    double ans = 0;
    double a = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        ans += PI * a * r[i] * r[i];
        a = -a;
    }
    printf("%.9lf\n", ans);
	return 0;
}

