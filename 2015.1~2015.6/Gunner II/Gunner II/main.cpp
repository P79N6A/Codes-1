#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 111;
typedef long long ll;

bool flag[MAXN];
int h[MAXN],q[MAXN];


int main() {
    int n, m;
    while (~scanf("%d%d",&n, &m))
    {
        multiset<int> s;
        memset(flag, 0, sizeof flag);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &h[i]);
            s.insert(h[i]);
        }
        for (int i = 1; i <= m; ++i)
            scanf("%d", &q[i]);
        for (int i = 1; i <= m; ++i)
        {
            if (!s.count(q[i]))
            {
                printf("-1\n");
                continue;
            }
            for (int j = 1; j <= n; ++j)
            {
                if (!flag[j] && h[j] == q[i])
                {
                    flag[j] = 1;
                    s.erase(s.find(h[j]));
                    printf("%d\n", j);
                    break;
                }
            }
        }
    }
    return 0;
}