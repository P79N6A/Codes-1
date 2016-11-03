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
const int MAXN = 5e5 + 111;

vector<int> w[MAXN];
int sum[1000020];

void update(int l, int r) {
	++sum[l];
	--sum[r];
	// pr(l)prln(r - 1)
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, c, len, x, tol = 0;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &len);
    	while (len --) {
    		scanf("%d", &x);
    		--x;
    		w[i].push_back(x);
    	}
    }
    bool flag = true;
    for (int i = 1; i < n; ++i) {
    	bool in = false;
    	for (int j = 0; j < w[i].size(); ++j) {
    		if (w[i - 1].size() > j) {
	    		int u = w[i][j], v = w[i - 1][j];
	    		if (u > v) {
	    			in = true;
	    			++tol;
	    			// pr(u)prln(v)
	    			update(0, c - u);
	    			u = (u + c - v) % c;
	    			update(c - v, min(c, c - v + c - u));
	    			break;
	    		}
	    		else if (u < v) {
	    			in = true;
	    			// pr(u)prln(v)
	    			++tol;
	    			u = u + c - v;
	    			update(c - v, min(c, c - v + c - u));
	    			break;
	    		}
	    		else continue;
    		}
    	}
    	if (!in && w[i].size() < w[i - 1].size()) {
    		flag = false;
    		break;
    	}
    }
    int ans = -1;
    for (int i = 0; i < c; ++i) {
    	if (i) sum[i] += sum[i - 1];
    	// pr(sum[i])
    	if (sum[i] == tol) {
    		ans = i;
    		break;
    	}
    }
    if (!flag) ans = -1;
    printf("%d\n", ans);
    return 0;
}