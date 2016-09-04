/*
  将答案进行二分，根据二分的答案来分配每个查询所在的区间。
 */
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
const int MAXN = 3e5 + 111;

class BIT {
public:
    int a[MAXN], n;
    void init(int len) {
        n = len;
    }
    void add(int p, int val) {
        for (int i = p; i <= n; i += i & -i) a[i] += val;
    }
    int sum(int p) {
        int ret = 0;
        for (int i = p; i > 0; i -= i & -i) ret += a[i];
        return ret;
    }
}bit;

struct P {
    int l, r, val, type, ans;
}p[MAXN];
int tol, num[MAXN];
int id[MAXN], temp[MAXN];

void cdq(int L, int R, int low, int high) {
    if (L > R) return;
    if (low == high) {
        while (L <= R) {
            p[id[L++]].ans = low;
        }
        return;
    }
    int mid = low + high >> 1, l = L, r = R, cur;
    // 根据答案划分到左右区间
    for (int i = L; i <= R; ++i) {
        cur = id[i];
        if (p[cur].type == 2) {
            int number = bit.sum(p[cur].r) - bit.sum(p[cur].l - 1);
            if (number < p[cur].val) {
                p[cur].val -= number;
                temp[r--] = cur;
            }
            else temp[l++] = cur;
        }
        else if (p[cur].val <= mid) {
            bit.add(p[cur].l, p[cur].type);
            temp[l++] = cur;
        }
        else temp[r--] = cur;
    }
    for (int i = L; i <= R; ++i) {
        cur = id[i];
        if (p[cur].type != 2 && p[cur].val <= mid) {
            bit.add(p[cur].l, -p[cur].type);
        }
    }
    int i;
    // 保证子区间出现顺序从小到大
    for (i = L; i < l; ++i) {
        id[i] = temp[i];
    }
    for (r = R; i <= R; ++i) {
        id[i] = temp[r--];
    }
    cdq(L, l - 1, low, mid);
    cdq(l, R, mid + 1, high);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (tol = 0; tol < n; ++tol) {
            scanf("%d", &p[tol].val);
            num[tol + 1] = p[tol].val;
            p[tol].type = 1;
            p[tol].l = tol + 1;
        }
        int q, pos, val;
        scanf("%d", &q);
        while (q --) {
            scanf("%d", &p[tol].type);
            if (p[tol].type == 1) {
                scanf("%d%d", &pos, &val);
                p[tol].l = pos;
                p[tol].type = -1;
                p[tol++].val = num[pos];
                p[tol].l = pos;
                p[tol].type = 1;
                p[tol++].val = val;
                num[pos] = val;
            }
            else {
                scanf("%d%d%d", &p[tol].l, &p[tol].r, &p[tol].val);
                ++tol;
            }
        }
        bit.init(tol - 1);
        for (int i = 0; i < tol; ++i) {
            id[i] = i;
        }
        cdq(0, tol - 1, 0, 1e9);
        for (int i = 0; i < tol; ++i) {
            if (p[i].type == 2) {
                printf("%d\n", p[i].ans);
            }
        }
    }
    return 0;
}
