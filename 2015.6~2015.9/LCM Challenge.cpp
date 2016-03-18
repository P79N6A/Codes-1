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
const int MAXN = 1e6 + 111;

int main()
{
    ll ans = 0, n;
    cin >> n;
    if (n <= 2) ans = n;
    else if (n % 2) ans = n * (n - 1) * (n -2);
    else
    {
        ans = max(n * (n - 1) * (n - 2) / 2, (n - 1) * (n - 2) * (n - 3));
        if (n % 3) ans = max(ans, n * (n - 1) * (n - 3));
    }
    cout << ans << '\n';
	return 0;
}


