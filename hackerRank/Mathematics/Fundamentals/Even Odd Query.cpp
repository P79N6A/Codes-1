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

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, q, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &q);
	while (q --) {
		scanf("%d%d", &x, &y);
		if (x > y) {
			puts("Odd");
			continue;
		}
		if (a[x] % 2) {
			puts("Odd");
		}
		else {
			if (x == y) puts("Even");
			else {
				if (x != n && !a[x + 1]) puts("Odd");
				else puts("Even");
			}
		}
	}
    return 0;
}