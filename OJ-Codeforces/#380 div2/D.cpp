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
const int MAXN = 1e3 + 111;

string s;

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, a, b, k;
    cin >> n >> a >> b >> k >> s;
    int num = 0;
    for (int i = 0; i < n; ) {
    	if (s[i] == '0') {
    		int sum = 0;
    		while (s[i] == '0' && i < n) {
    			++sum;
    			++i;
    		}
    		num += sum / b;
    	}
    	else ++i;
    }
    int ans = num - a + 1;
    cout << ans << '\n';
    for (int i = 0; i < n; ) {
    	if (s[i] == '0') {
    		int bg = i;
    		int sum = 0;
    		while (s[i] == '0' && i < n) {
    			++sum;
    			++i;
    		}
    		int base = 1;
    		while (ans && sum / b != 0) {
    			--ans;
    			cout << bg + base * b << ' ';
    			++base;
    			sum -= b;
    		}
    	}
    	else ++i;
    }
    return 0;
}