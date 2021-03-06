#include <algorithm>
#include <bitset>
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
const int MAXN = 2e6 + 111;

bool is[MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int t; cin >> t;
    ll n;
    vector<int> prime;
    for (int i = 2; i <= 2e6; ++i) {
    	if (!is[i]) {
    		prime.push_back(i);
    		for (int j = i + i; j <= 2e6; j += i) {
    			is[j] = 1;
    		}
    	}
    }
    while (t --) {
        cin >> n;
        int cnt = 0;
        ll ans = n;
        while (n != 1) {
        	while (n % prime[cnt] == 0) {
        		n /= prime[cnt];
        		ans = prime[cnt];
        	}
        	if (++cnt == prime.size()) break;
        }
        ans = max(ans, n);
        cout << ans << '\n';
    }
    return 0;
}