#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
int v[MAXN], day[MAXN];
struct N
{
    ll v, day;
    N(ll a, ll b):v(a),day(b){}
    bool operator <(const N& t)const
    {
        return v > t.v;
    }
};

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i) scanf("%d", v + i);
        for (int i = 1; i <= n; ++i) scanf("%d", day + i);
        ll temp = v[1];
        priority_queue<N> pq;
        pq.push(N(temp, day[1])); //use it to store the statues
        for (int i = 2; i <= n; ++i)
        {
            pq.push(N(temp + v[i], i + day[i] - 1));
            while(pq.top().day < i) pq.pop();
            temp = pq.top().v;
        }
        printf("%lld\n", temp);
    }
    return 0;
}
