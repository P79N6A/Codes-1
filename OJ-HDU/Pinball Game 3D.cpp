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
#define pil pair<int, ll>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
const int mod = 1 << 30;

struct P {
    int x, y, z, id;
    void read() {
        scanf("%d%d%d", &x, &y, &z);
    }
    bool operator < (const P&t) const {
        if (x != t.x) return x < t.x;
        if (y != t.y) return y < t.y;
        return z < t.z;
    }
}p[MAXN];

int id[MAXN], all[MAXN];
pil dp[MAXN];

void getMax(pil &a, pil b) {
    if (a.first < b.first) a = b;
    else if (a.first == b.first) {
        a.second += b.second;
    }
}

// 寻找区间最大dp
class BIT {
public:
    pil node[MAXN];
    int n;
    void init(int len) {
        n = len;
        for (int i = 1; i <= n; ++i) node[i] = pil(0, 0);
    }
    void add(int p, pil val) {
        for (int i = p; i <= n; i += i & -i) getMax(node[i], val);
    }
    void clear(int p) {
        for (int i = p; i <= n; i += i & -i) node[i] = pil(0, 0);
    }
    pil query(int p) {
        pil ret = pil(0, 0);
        for (int i = p; i >= 1; i -= i & -i) getMax(ret, node[i]);
        return ret;
    }
}bit;

bool cmp(P a, P b) {
    return a.y == b.y ? a.z < b.z : a.y < b.y;
}

void cdq(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    cdq(l, mid);
    sort(p + l, p + mid + 1, cmp);
    sort(p + mid + 1, p + r + 1, cmp);
    int j = l;
    for (int i = mid + 1; i <= r; ++i) {
        for (; j <= mid && p[j].y <= p[i].y; ++j)
            bit.add(p[j].z, dp[p[j].id]);
        pil temp = bit.query(p[i].z);
        ++temp.first;
        getMax(dp[p[i].id], temp);
    }
    for (int i = l; i < j; ++i) bit.clear(p[i].z);
    sort(p + mid + 1, p + r + 1); // 还原X轴排序
    cdq(mid + 1, r);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        bit.init(n);
        for (int i = 0; i < n; ++i) {
            p[i].read();
            dp[i] = pil(1, 1);
            all[i] = p[i].z;
        }
        sort(p, p + n);
        sort(all, all + n);
        for (int i = 0; i < n; ++i) {
            p[i].z = lower_bound(all, all + n, p[i].z) - all + 1;
            p[i].id = i;
        }
        cdq(0, n - 1);
        pil ans = pil(0, 0);
        for (int i = 0; i < n; ++i) {
            getMax(ans, dp[i]);
        }
        printf("%d %I64d\n", ans.first, ans.second % mod);
    }
    return 0;
}
