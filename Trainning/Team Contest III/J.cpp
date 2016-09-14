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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const ll INF = 1e18+100;
const int maxn = 1e6 + 111;
ll dp[maxn];
struct Node{
    int dis, c;
    bool operator < (const Node& rhs)const{
        return c < rhs.c;
    }
}node[maxn], q[maxn];
typedef pair<ll,ll> P;
//P p[maxn];
ll tt[maxn], t;
int n;
bool getok(int k){
   // prln(k);
    for(int i = 0; i <= n; ++i){
        dp[i] = INF;
    }
    priority_queue<P, vector<P>, greater<P> > p;
    p.push(P(0,1));
    for(int i = 2; i <= n; ++i){
        while(p.size() && i-p.top().second>k) p.pop();
        P u = p.top();
        dp[i] = min(dp[i], u.first);
        p.push(P(dp[i]+tt[i], i));
    }
   // prln(dp[n]);
    if(dp[n] <= t) return true;
    return false;
}
int main()
{
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);

    cin>>n>>t;
    memset(tt,0,sizeof tt);
    t-=n-1;
    for(int i = 1; i < n; ++i){
        scanf("%d",&node[i].c);
        node[i].dis = i;
    }
    for(int i = 2; i < n; ++i){
        scanf("%d", &tt[i]);
    }
    sort(node+1, node+n);
    int cntq = 0;
    for(int i = 1; i < n; ++i){
        while(cntq && i < n && node[i].dis < q[cntq-1].dis) ++i;
        if(i==n) continue;
        q[cntq++] = node[i];
    }

    int l = 0, r = cntq;
    while(l < r){
        int mid = (l+r)>>1;
        if(getok(q[mid].dis)) r = mid;
        else l = mid+1;
    }
    printf("%d\n", q[l].c);

    return 0;
}
