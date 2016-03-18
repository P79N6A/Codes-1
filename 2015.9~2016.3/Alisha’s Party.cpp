#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 6e4;

int open[MAXN];
char mp[MAXN][200];

struct People{
    char name[200];
    int v, id;
    bool operator <(const People &t)const{
        if (v == t.v) return id > t.id;
        return v < t.v;
    }
}people[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int kase; scanf("%d", &kase);
    while (kase --)
    {
        int k, m, q;
        scanf("%d%d%d", &k, &m, &q);
        for (int i = 1; i <= k; ++i)
        {
            scanf("%s %d", people[i].name, &people[i].v);
            people[i].id = i;
            open[i] = 0;
        }
        while (m --)
        {
            int t, p;
            scanf("%d %d", &t, &p);
            open[t] = p;
        }

        priority_queue<People> pq;
        int cnt = 1;
        for (int i = 1; i <= k; ++i)
        {
            pq.push(people[i]);
            while (open[i]-- && pq.size())
            {
                People tem = pq.top(); pq.pop();
                strcpy(mp[cnt++],tem.name);
            }
        }
        while (pq.size())
        {
            People tem = pq.top(); pq.pop();
            strcpy(mp[cnt++],tem.name);
        }

        while (q --)
        {
            int x;
            scanf("%d", &x);
            printf("%s", mp[x]);
            if (q) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
