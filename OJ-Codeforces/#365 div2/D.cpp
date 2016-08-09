/*
  离线处理区间，右端点排序。
  让数字出现在它最新出现的位置。
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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

struct BIT {
    int val[MAXN], n;
    void add(int x, int v) {
        for (int i = x; i <= n; i += i & -i) val[i] ^= v;
    }
    int sum(int x) {
        int ret = 0;
        for (int i = x; i > 0; i -= i & -i) ret ^= val[i];
        return ret;
    }
}bit;
int a[MAXN];
int sum[MAXN];
int ans[MAXN];
map<int, int> mp;
vector<pii> query[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, q, l, r; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i] ^ sum[i - 1];
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &l, &r);
        query[r].push_back(make_pair(l, i));
    }
    bit.n = n;
    for (int i = 1; i <= n; ++i) {
        if (mp.count(a[i])) bit.add(mp[a[i]], a[i]);
        bit.add(i, a[i]);
        mp[a[i]] = i;
        for (int j = 0; j < query[i].size(); ++j) {
            int l = query[i][j].first, id = query[i][j].second;
            ans[id] = sum[i] ^ sum[l - 1] ^ (bit.sum(i) ^ bit.sum(l - 1));
        }
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}
