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
typedef long long ll;
using namespace std;

const int MAXN = 2e5 + 111;

struct Island{
    int id;
    ll l, r;
    bool operator < (const Island& t)const{
        return r > t.r;
    }
}island[MAXN];

bool cmp(const Island& a, const Island& b){
    return a.l < b.l;
}

struct B{
    ll len;
    int id;
    bool operator < (const B& t)const{
        return len < t.len;
    }
}b[MAXN];

int ans[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld %lld", &island[i].l, &island[i].r);
    for (int i = 1; i <= n - 1; ++i) //循环利用数组，将岛屿的左右转换为岛屿间的最小间隔与最大间隔~
    {
        ll mi = island[i + 1].l - island[i].r, mx = island[i + 1].r - island[i].l;
        island[i].l = mi, island[i].r = mx;
        island[i].id = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%lld", &b[i].len);
        b[i].id = i;
    }
    sort(island + 1, island + n, cmp);
    sort(b + 1, b + m + 1);
    priority_queue<Island> q;
    int cnt = 1, num = 0;
    for (int i = 1; i <= m; ++i)
    {
        while (!q.empty() && q.top().r < b[i].len) //如果比当前桥长度都小，那么肯定比后面桥还短
            q.pop();
        while (cnt <= n - 1 && island[cnt].l <= b[i].len && b[i].len <= island[cnt].r) //能在岛间搭桥
            q.push(island[cnt++]);
        if (q.empty())
            continue;
        Island tem = q.top(); q.pop(); //取出能搭桥的岛中，r最小的
        ans[tem.id] = b[i].id;
        ++num;
    }
    if (num == n - 1)
    {
        printf("Yes\n");
        for (int i = 1; i < n - 1; ++i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[n - 1]);
    }
    else puts("No");
    return 0;
}
