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
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int x[4], y[4], rt;

inline void getans(int x1, int y1, int x2, int y2, int op, int step) {
    if (step == 4) {
        x[op * 2] = x1, x[op * 2 + 1] = x2;
        y[op * 2] = y1, y[op * 2 + 1] = y2;
        return;
    }
    if (step == 0) {
        int l = x1, r = x2, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            printf("? %d %d %d %d\n", x1, y1, mid, y2);
            fflush(stdout);
            scanf("%d", &rt);
            if (op && x1 <= x[0] && y1 <= y[0] && x[1] <= mid && y[1] <= y2) --rt;
            if (rt) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        getans(x1, y1, ans, y2, op, step + 1);
    }
    else if (step == 1) {
        int l = x1, r = x2, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            printf("? %d %d %d %d\n", mid, y1, x2, y2);
            fflush(stdout);
            scanf("%d", &rt);
            if (op && mid <= x[0] && y1 <= y[0] && x[1] <= x2 && y[1] <= y2) --rt;
            if (rt) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        getans(ans, y1, x2, y2, op, step + 1);
    }
    else if (step == 2) {
        int l = y1, r = y2, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            printf("? %d %d %d %d\n", x1, y1, x2, mid);
            fflush(stdout);
            scanf("%d", &rt);
            if (op && x1 <= x[0] && y1 <= y[0] && x[1] <= x2 && y[1] <= mid) --rt;
            if (rt) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        getans(x1, y1, x2, ans, op, step + 1);
    }
    else {
        int l = y1, r = y2, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            printf("? %d %d %d %d\n", x1, mid, x2, y2);
            fflush(stdout);
            scanf("%d", &rt);
            if (op && x1 <= x[0] && mid <= y[0] && x[1] <= x2 && y[1] <= y2) --rt;
            if (rt) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        getans(x1, ans, x2, y2, op, step + 1);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    getans(1, 1, n, n, 0, 0);
    getans(1, 1, n, n, 1, 0);
    printf("! %d %d %d %d %d %d %d %d\n", x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);
    return 0;
}
