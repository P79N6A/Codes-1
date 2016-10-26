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
const int MOD = 1e5;

int quick_pow(ll base, ll p) {
	int ret = 1;
	while (p) {
		if (p & 1) ret = ret * base % MOD;
		base = base * base % MOD;
		p >>= 1;
	}
	return ret;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, x; cin >> n;
    while (n --) {
    	cin >> x;
    	cout << (quick_pow(2, x) - 1 + MOD) % MOD<< '\n';
    }
    return 0;
}