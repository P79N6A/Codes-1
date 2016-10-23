#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 3e5 + 111;

ll up[MAXN], tol;
int n, len, pos;

struct P {
	int id;
	ll t, w;
	void read(int d) {
		id = d;
		scanf("%lld %lld", &t, &w);
	}
	bool operator < (const P& temp)const {
		if (t == temp.t) {
			if (w == temp.w) return id > temp.id;
			return w < temp.w;
		}
		return t < temp.t;
	}
}team[MAXN];


int check(ll final) {
	team[pos].t = final;
	sort(team, team + n);
    pos = 0;
    for (; pos < n; ++pos) {
    	if (team[pos].id == 0) break;
    }
    len = 0;
    int ret = n - pos;
    for (int i = pos + 1; i < n; ++i) {
    	up[len++] = team[i].w - team[i].t + 1;
    }
    sort(up, up + len);
    ll use = tol - final;
    for (int i = 0; i < len; ++i) {
    	if (use >= up[i]) {
    		--ret;
    		use -= up[i];
    	}
    	else break;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    	team[i].read(i);
    sort(team, team + n);
    pos = 0;
    for (; pos < n; ++pos) {
    	if (team[pos].id == 0) break;
    }
    ll l = 0, r = team[pos].t;
    tol = team[pos].t;
    int ans = n - pos;
    while (l < r) {
    	ll mid = (l + r) / 2;
    	ll mmid = (mid + r) / 2;
    	int x = check(mid);
    	int y = check(mmid);
    	if (x <= y) {
    		ans = min(ans, x);
    		r = mmid;
    	}
    	else {
    		ans = min(ans, y);
    		l = mid;
    	}
    }
    printf("%d\n", ans);
    return 0;
}