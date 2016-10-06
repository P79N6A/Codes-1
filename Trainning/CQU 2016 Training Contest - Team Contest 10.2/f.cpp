#include<algorithm>
#include<bitset>
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
const int maxn = 1e6 + 111;
int p[maxn];
int find(int x){
   // prln(x);
    return p[x]=p[x] == x?x:find(p[x]);
}
int n, m;

int u[maxn], v[maxn], c[maxn], vis[maxn];
int get(int x){
    for(int i = 0; i <= n; ++i){
        p[i] = i;
        vis[i] = false;
    }
    for(int i = 0; i < m; ++i){
        if((c[i]&x) == 0) continue;
        int uu = find(u[i]);
        int vv = find(v[i]);
        if(uu != vv) p[uu] = vv;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        int uu = find(i);
        if(!vis[uu]) cnt++;
        vis[uu] = true;
    }
    return cnt;
}
int pp[maxn], pcnt;
void init(){
    pp[0] = 1, pp[1] = 1;
    pcnt = 2;
    for(int i = 2; i < 35 ; ++i){
        pp[pcnt] = pp[pcnt-1] + pp[pcnt-2];
        pcnt++;
       // prln(pp[pcnt-1]);
        if(pp[pcnt]>4e5) break;
    }
}
int ok(int x){
    int pos = lower_bound(pp, pp + pcnt, x) - pp;
    return pp[pos];
}
int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    init();
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        scanf("%d%d",&n,&m);
        printf("Case #%d: ",++kase);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d",&u[i], &v[i], &c[i]);
            c[i] = 1<<c[i];
        }
        int wcnt = get(2);
        int mawcnt = n-wcnt;
        int bcnt = get(1);
        int cnt = get(3);
        int need = wcnt-1;
        int ziyou = n-bcnt-need;
        int miwcnt = mawcnt - ziyou;
        int mi = ok(miwcnt);
      //  pr(wcnt);pr(bcnt);pr(cnt);pr(ziyou);pr(miwcnt);prln(mi);
        if(cnt==1&&mi<=mawcnt){
            printf("Yes\n");
        }else printf("No\n");

    }
    return 0;
}
