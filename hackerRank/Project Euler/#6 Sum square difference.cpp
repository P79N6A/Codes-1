#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int t, n;
    cin >> t;
    while (t --) {
    	ll sum = 0, sum2 = 0;
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
    		sum += i * i;
    		sum2 += i;
    	}
    	cout << sum2 * sum2 - sum << '\n';
    }
    return 0;
}