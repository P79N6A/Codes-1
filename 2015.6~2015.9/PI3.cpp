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
const int MAXN = 2e5 + 111;
typedef long long ll;
int n, k;
struct N{
    int id;
    ll num;
    bool operator < (const N& t)const
    {
        return (num == t.num ? id < t.id : num < t.num);
    }
}node[MAXN];

ll solve(int n)
{
    ll a, b;
    int p1 = lower_bound(node, node + n, n * k) - node;
    int p2 = upper_bound(node, node + n, n * k) - node;
    int p3 = lower_bound(node, node + n, n / k) - node;
    int p4 = upper_bound(node, node + n, n / k) - node;
    
    a = upper_bound(node, node + n, n * k) - lower_bound(node, node + n, n * k);
    b = upper_bound(node, node + n, n / k) - lower_bound(node, node + n, n / k);
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
	{
	    cin >> node[i].num;
        node[i].id = i;
    }
    sort(node, node + n);
    ll ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += solve(node[i].num);
    }
	return 0;
}


