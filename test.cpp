#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<cctype>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<sstream>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int MOD= 72807249;
const int maxn = 200010;
const int maxm = 2e6+10;
struct Edge{
   ll a,b;
}numb[maxn];
struct Node{
    ll l , r;
    ll sum;
}tree[2*maxn+100];
ll ans = 1;
void build(ll l,ll r,ll cur){
    if(l > r) return ;
    tree[cur].l=l;
    tree[cur].r=r;
   // tree[cur].flag=false;
    if(l==r){
        if (numb[l].a==1) tree[cur].sum = numb[l].b%MOD;
        else tree[cur].sum = 1;
        return ;
    }
    build(l,(l+r)>>1,cur*2);
    build(((l+r)>>1)+1,r,cur*2+1);
    tree[cur].sum = (tree[cur*2].sum%MOD)*(tree[cur*2+1].sum%MOD);
    tree[cur].sum %= MOD;
}
void update(ll l,ll r,ll cur)
{
    if (tree[cur].l > r || tree[cur].r < l) return;
    if (tree[cur].l >= l && tree[cur].r <= r)
    {
        tree[cur].sum = 1;
        return;
    }
    update(l,r,cur*2);
    update(l,r,cur*2+1);
    tree[cur].sum = (tree[cur*2].sum%MOD)*(tree[cur*2+1].sum%MOD);
    tree[cur].sum %= MOD;
}
void query(ll l,ll r,ll cur)
{
     if(tree[cur].l > r || tree[cur].r < l) return;
     if(tree[cur].l >= l && tree[cur].r <= r){
            ans *= tree[cur].sum;
            ans %= MOD;
            return;
     }
    query(l,r,cur*2);
    query(l,r,cur*2+1);
}
int main(){
#ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
           scanf("%lld %lld",&numb[i].a,&numb[i].b);
        }
        build(1,n,1);
        ans = 1;
        for(int i = 1; i <= n; i++)
        {
           if (numb[i].a == 1)
           {
               ans *= (numb[i].b%MOD);
               ans %= MOD;
           }
           else
           {
                update(numb[i].b,numb[i].b,1);
                ans = 1;
                query(1,i,1);  //cout<<l << " "<<r<<" "<<ans <<endl;
           }
            printf("%lld\n",ans);
        }
    }
	return 0;
}
