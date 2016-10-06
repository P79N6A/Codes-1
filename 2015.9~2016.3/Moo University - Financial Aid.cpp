#include<algorithm>
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
#define ll long long
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct C {
    int s, f;
    bool operator < (const C &t)const {
        return f < t.f;
    }
}cow[MAXN];

ll l[MAXN], r[MAXN];

bool cmp(C a, C b) {
    return a.s < b.s;
}

int main()
{
    int n, c, f; scanf("%d%d%d", &n, &c, &f);
    for (int i = 0; i < c; ++i) scanf("%d%d", &cow[i].s, &cow[i].f);
    sort(cow, cow + c, cmp);

    int need = (n - 1) / 2;
    int up = c - need; // 中位数能取到的上限

    // 计算l[i]
    priority_queue<C, vector<C> > pq;
    ll sum = 0;
    for (int i = 0; i < need; ++i) {
        pq.push(cow[i]);
        sum += cow[i].f;
    }
    for (int i = need; i < up; ++i) {
        l[i] = sum;
        sum += cow[i].f;
        pq.push(cow[i]);
        sum -= pq.top().f;
        pq.pop();
    }

    // 计算r[i]
    priority_queue<C, vector<C> > pq2;
    sum = 0;
    for (int i = up; i < c; ++i) {
        pq2.push(cow[i]);
        sum += cow[i].f;
    }
    for (int i = up - 1; i >= need; --i) {
        r[i] = sum;
        sum += cow[i].f;
        pq2.push(cow[i]);
        sum -= pq2.top().f;
        pq2.pop();
    }

    int ans = -1;
    for (int i = need; i < up; ++i) {
        //cout << i << ": " << l[i] << ',' << r[i] << '\n';
        //cout << l[i] + r[i] + cow[i].f << '\n';
        if (l[i] + r[i] + cow[i].f <= f && cow[i].s > ans){
            ans = cow[i].s;
        }
    }
    printf("%d\n", ans);
    return 0;
}
