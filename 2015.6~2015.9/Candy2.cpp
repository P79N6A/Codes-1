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
bool like[20][20], used[20];
int n, m, k, b[20], t;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &like[i][j]);
        memset(used, 0, sizeof used);
        for (int i = 0; i < n; ++i)
        {
            int p = 0, mx = 1, vis = 0;
            for (int j = 0; j < m; ++j)
            {
                if (like[j][i] && b[j] > mx)
                {
                    vis = 1;
                    mx = b[j];
                    p = j;
                }
                else if (like[j][i] && b[j] == mx)
                {
                    int cnt1 = 0, cnt2 = 0;
                    for (int l = i; l < n; ++l) if(like[p][l])
                        ++cnt1;
                    for (int l = i; l < n; ++l) if(like[j][l])
                        ++cnt2;
                    if (cnt1 > cnt2)
                    {
                        vis = 1;
                        p = j;
                    }
                }
            }
            if (vis) b[p] -= k, used[i] = 1;
        }
        int lefcandy = 0, lef = 0;
        for (int i = 0; i < n; ++i) if(!used[i])
            ++lefcandy;
        for (int i = 0; i < m; ++i) if (b[i] > 0)
            lef += b[i];
        //cout << lefcandy << ' ' << lef << endl;
        printf("Case #%d: ", kase);
        if (lef > lefcandy)
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

