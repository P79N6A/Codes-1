#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 1111;
double ans1, ans2; //左边最大y值，右边最大y值
bool flag, vis[MAXN];
struct Circle{
    double x, y, r;
    void read()
    {
        scanf("%lf%lf%lf", &x, &y, &r);
    }
}circle[MAXN];

vector<int> G[MAXN];

double DIS(int a, int b) //圆心间距离
{
    double dx = circle[a].x - circle[b].x;
    double dy = circle[a].y - circle[b].y;
    return sqrt(dx * dx + dy * dy);
}

void dfs(int u)
{
    if (flag || vis[u]) return;
    vis[u] = 1;
    if (circle[u].y <= circle[u].r)
    {
        flag = 1; return;
    }
    //如果和最左边或者最右边相交，则更新
    if (circle[u].x <= circle[u].r) ans1 = min(ans1, circle[u].y - sqrt(circle[u].r*circle[u].r - circle[u].x*circle[u].x));
    if (circle[u].x + circle[u].r >= 1000) ans2 = min(ans2, circle[u].y - sqrt(circle[u].r*circle[u].r - (1000 - circle[u].x)*(1000 - circle[u].x)));
    for (int i = 0; i < G[u].size(); ++i)
    {
        dfs(G[u][i]);
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        ans1 = ans2 = 1000.0;
        for (int i = 0; i < n; ++i)
        {
            circle[i].read();
            G[i].clear();
        }
        for (int i = 0; i < n; ++i) //预处理出圆与圆间的连接关系，方便dfs访问
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (DIS(i, j) <= circle[i].r + circle[j].r)
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        flag = 0;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; ++i)
        {
            if (circle[i].r + circle[i].y >= 1000)
                dfs(i);
        }
        if (flag) printf("IMPOSSIBLE\n");
        else printf("%.2f %.2f %.2f %.2f\n", 0.0, ans1, 1000.0, ans2);
    }
    return 0;
}
