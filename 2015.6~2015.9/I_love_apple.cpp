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
const int MAXN = 1e6 + 111;

int main()
{
    int mi, mx, n, x, ans = 0; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (i == 0)
        {
            mx = x, mi = x;
        }
        else
        {
            if (x < mi) mi = x, ++ans;
            if (x > mx) mx = x, ++ans;
        }
    }
    cout << ans << '\n';
	return 0;
}

