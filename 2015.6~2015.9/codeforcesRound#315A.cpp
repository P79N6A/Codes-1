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
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
	double t, s, q;
	cin >> t >> s >> q;
	double v = 1, vd = (q - 1.0)/ q;
	double total = (t - s) / vd;
	int ans = 1;
	double tt = s / (v - vd);
    while(total - tt > 1e-7)
    {
        ++ans;
        s += s/(v - vd) * v;
        tt += s / (v - vd);
    }
    cout << ans << '\n';
	return 0;
}

