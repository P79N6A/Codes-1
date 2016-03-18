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
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define BUG puts("I am bug")
#define XY(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
const int MAXN = 1e5 + 111;

pair<int, int> cow[MAXN];
priority_queue<int> q, qq;
int lower[MAXN], upper[MAXN];

int main() {
    int n, c, f; scanf("%d %d %d", &n, &c, &f);
    int half = n / 2;
    for (int i = 0; i < c; ++i)
        scanf("%d %d", &cow[i].first, &cow[i].second);
    sort(cow, cow + c);
    int total = 0;
    for (int i = 0; i < c; ++i)
    {
        lower[i] = q.size() == half ? total : 0x3f3f3f3f;
        q.push(cow[i].second);
        total += cow[i].second;
        if (q.size() > half)
        {
            total -= q.top();
            q.pop();
        }
    }
    total = 0;
    for (int i = c - 1; i >= 0; --i)
    {
        upper[i] = qq.size() == half ? total : 0x3f3f3f3f;
        qq.push(cow[i].second);
        total += cow[i].second;
        if (qq.size() > half)
        {
            total -= qq.top();
            qq.pop();
        }
    }
    int ans = -1;
    for (int i = c - 1; i >= 0; --i)
        if (lower[i] + upper[i] + cow[i].second <= f)
        {
            ans = cow[i].first;
            break;
        }
    printf("%d\n", ans);
    return 0;
}
