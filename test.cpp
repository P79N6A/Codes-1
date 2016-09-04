#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#define lson l, m , rt << 1
#define rson m + 1, r, rt << 1 | 1
#define maxn 50010
using namespace std;
struct people{
    int id,loty,abty;
    bool operator < (const people& cmp)const {
        return abty > cmp.abty;//能力从大到小排列
    }
}emp[maxn];
int Max[maxn << 2],t,n,m,ans[maxn],L[maxn],R[maxn],head[maxn],tot,ed;
map <int, int> mp;
struct Edge{
    int v,next;
}edge[maxn];
void add(int u,int v){
    edge[ed].v = v;
    edge[ed].next = head[u];
    head[u] = ed ++;
}
void dfs(int rt){//这个是电脑的dfs，两个dfs都能过！
    L[rt] = tot ++;
    for(int i = head[rt]; i != -1; i = edge[i].next){
        dfs(edge[i].v);
    }
    R[rt] = tot;
}

int query(int L, int R, int l, int r, int rt){//区间询问
    if(L > R) return -1;
    if(L <= l && r <= R){
        return Max[rt];
    }int m = (l + r) >> 1;
    int ll = -1, rr = -1;
    if(L <= m) ll = query(L,R,lson);
    if(R > m) rr = query(L,R,rson);
    return max(ll,rr);
}
void update(int &pos, int &val, int l, int r, int rt){//单点更新
    if(l == r){
        Max[rt] = val;  return ;
    }int m = (l + r) >> 1;
    if(pos <= m) update(pos,val,lson);
    else update(pos,val,rson);
    Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
}
void pre(){//预处理
    mp.clear(); mp[-1] = -1;    tot = ed = 0;
    memset(L,0,sizeof(L));  memset(R,0,sizeof(R));
    memset(head,-1,sizeof(head));   memset(Max,-1,sizeof(Max));//相当于build。

    for(int i = 1,fa; i < n; i ++){
        scanf("%d%d%d",&fa,&emp[i].loty, &emp[i].abty);
        add(fa,i);
        mp[emp[i].loty] = i;
        emp[i].id = i;
    }
    dfs(0);

    sort(emp + 1,emp + n);
}
void showans(){
    int fired;
    while(m --){
        scanf("%d",&fired);
        printf("%d\n",ans[fired]);
    }
}
int main(){
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d",&t);
    while(t --){
        scanf("%d%d",&n,&m);
        pre();
        emp[0].abty = -1;
        for(int i = 1, j; i < n; i = j){
            if (emp[i].abty == emp[i - 1].abty) continue;
            j = i;
            while(j < n && emp[j].abty == emp[i].abty){
                int id = emp[j].id;
                int lo = query(L[id] + 1,R[id] - 1,0,tot - 1, 1);
                ans[id] = mp[lo];
                j ++;
            }
            j = i;
            while(j < n && emp[j].abty == emp[i].abty){
                int id = emp[j].id;
                printf("%d\n", id);
                update(L[id],emp[j].loty,0,tot - 1, 1);
                j ++;
            }
        }
        showans();
    }
    return 0;
}
