#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct Interval {
    int ans, up, down;
    bool operator < (const Interval &t)const {
        if (down == t.down) return up < t.up;
        return down < t.down;
    }
}inter[1011];

int main()
{
    int n, m, r; scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &inter[i].down, &inter[i].up, &inter[i].ans);
        inter[i].up += r;
    }
    sort(inter, inter + m);

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int mx = 0;
        for (int j = 0; j < i; ++j) {
            if (inter[j].up <= inter[i].down && inter[j].ans > mx)
                mx = inter[j].ans;
        }
        inter[i].ans += mx;
        ans = max(ans, inter[i].ans);
    }
    printf("%d\n", ans);
    return 0;
}
