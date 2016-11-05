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

bool is[MAXN];
vector<int> v;

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    for (int i = 2; i <= 1e6; ++i) {
    	if (!is[i]) {
    		v.push_back(i);
    		for (int j = i + i; j <= 1e6; j += i) {
    			is[j] = 1;
    		}
    	}
    }
    int n, t;
    cin >> t;
    while (t --) {
    	cin >> n;
    	cout << v[n - 1] << '\n';
    }
    return 0;
}