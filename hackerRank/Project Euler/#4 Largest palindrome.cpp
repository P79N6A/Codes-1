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
const int MAXN = 1e6 + 111;

int ans[MAXN];
char s[10];

bool ok() {
    for (int i = 0; i < 3; ++i) {
        if (s[i] != s[5 - i]) return false;
    }
    return true;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int t, n; cin >> t;
    for (int i = 100; i < 1000; ++i) {
    	for (int j = 100; j < 1000; ++j) {
    		int cur = i * j;
    		sprintf(s, "%d", cur);
            if (strlen(s) == 6 && ok()) {
                ans[cur + 1] = cur;
            }
    	}
    }
    for (int i = 1; i <= 1e6; ++i) {
        ans[i] = max(ans[i], ans[i - 1]);
    }
    while (t --) {
    	cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}