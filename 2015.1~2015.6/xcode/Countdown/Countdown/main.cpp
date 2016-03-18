#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define BUG printf(“I am here!”)
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
using namespace std;
typedef long long ll;
int t;
int n,d;
struct Node{
    int gc=0;
    int fa=0;
    int ch=0;
    string name;
};

bool cmp(const Node &a,const Node &b){
    return a.gc>b.gc;
}

int main() {
    scanf("%d",&t);
    for (int kase=1;kase<=t;kase++){
        int cnt=1;
        Node p[1010];
        scanf("%d%d",&n,&d);
        map<string,int> mp;
      //  mp.clear();
        for (int i=1;i<=n;i++) {
            char tt[15];
            int x;
            scanf("%s %d",tt,&x);
            if (!mp.count(tt)) {
                mp[tt]=cnt;
                p[cnt].name=tt;
                p[cnt].ch=x;
                cnt++;
            }
            else {
                p[mp[tt]].ch=x;
                p[p[mp[tt]].fa].gc+=x;
            }
            int fa=mp[tt];
            for (int j=1;j<=x;j++){
                char nn[15];
                scanf("%s",nn);
                if ( !mp.count(nn)){
                    mp[nn]=cnt;
                    p[cnt].name=nn;
                    cnt++;
                }
                else {
                    p[fa].gc+=p[mp[nn]].ch;
                }
                p[mp[nn]].fa=fa;
            }
        }
        sort(p+1,p+1+cnt,cmp);
 //      printf("cnt=%d",cnt);
        printf("Tree %d:\n",kase);
        for (int i=1;i<cnt;i++) {
       //     printf("here\n");
            if (p[i].gc>=d)
                cout << p[i].name << " " << p[i].gc << endl;
            else break;
        }
        printf("\n");
    }
    
    return 0;
}
