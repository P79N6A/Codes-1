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
int a[maxn], b[maxn], c[maxn];
int dis[100][100];
int uu[maxn], vv[maxn], cc[maxn];
int edgenum = 0;
void addedge(int u, int v, int c){
    uu[edgenum] = u;
    vv[edgenum] = v;
    dis[u][v] = c;
    cc[edgenum++] = c;
}
struct Node{
    int u, v, c;
    bool operator < (const Node& rhs)const{
    return c < rhs.c;
    }
}node[maxn];
int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m;
    scanf("%d", &t);
    int kase = 0;
    while(t--){
        scanf("%d%d",&n,&m);
        printf("Case #%d:\n",++kase);
        int mi = (n)/2;
        edgenum = 0;
        mi = min(mi, (m+1)/3);
        int ma = 1;
        memset(dis, 0, sizeof dis);
        int cnta = 0, cntb = 0, cntc = 0;
        for(int i = 1; i <= m; ++i){
            if(i%3==1) a[cnta++] = i;
            if(i%3==2) b[cntb++] = i;
            if(i%3==0) c[cntc++] = i;
        }
        bool ok = true;
        if(m<n) ok = false;

        for(int i = 0; i < mi; ++i){
            addedge(i+1,i+2,a[--cnta]);
            addedge(i+1+mi,i+2+mi,b[--cntb]);

        }
        ma = 2*mi+1;
        for(int i = ma; i < n+1; ++i){
            if(cntc==0) ok = false;
            if(cntc>0) addedge(i, i+1, c[--cntc]);
        }
        for(int i = 1; i <= n+1; i++) dis[i][i] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n+1; ++j){
                dis[i][j] = dis[i][j-1] + dis[j-1][j];
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = i+2; j <= n; ++j){

                if(dis[i][j]%3==1) {
                    if(cnta>0) addedge(i, j, a[--cnta]);
                    else if(cntb>0) addedge(j, i, b[--cntb]);
                }else if(dis[i][j]%3==2){
                    if(cntb>0) addedge(i, j, b[--cntb]);
                    else if(cnta>0) addedge(j, i, a[--cnta]);
                }else{
                    if(cntc>0) addedge(i,j,c[--cntc]);
                }
            }
        }

        if(cnta>0||cntb>0||cntc>0){
            printf("-1\n");
        }else{
            for(int i = 0; i<edgenum;++i){
                node[i] = Node{uu[i],vv[i],cc[i]};
            }
            sort(node,node+edgenum);
            for(int i = 0; i < edgenum; ++i){
                int u = node[i].u;
                int v = node[i].v;
                if(u==n+1) u = 1;
                if(v==n+1) v = 1;
                printf("%d %d %d\n",u,v,node[i].c);
            }
        }
    }
    return 0;
}
