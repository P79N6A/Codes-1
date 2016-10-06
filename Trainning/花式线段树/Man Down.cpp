/*
  �����뵽���������Ҫ���ܰ�ÿ�������Ӧ��������һ���ߣ�
  ������һ��DAG��Ȼ��DPһ���¾ͺ��ˡ�����n^2���߲���
  ���ܣ�����������ôȷ��һ������������ʲô���ӣ����ִ�
  �ʹ����ߴ������߶Σ�Ȼ�󵥵��ѯ���ÿ��ԡ���������
  �����������£������ѯ�ˡ�
  ǧ��Ҫע�⣺���������[l, r]�����·���ָ������l������
  r����������
  4 2 4 100
  2 2 4 100
  �����300��
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
#define root 1, n, 1
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct P {
    int l, r, h, v;
    void read() {
        scanf("%d%d%d%d", &h, &l, &r, &v);
    }
    bool operator < (const P& rhs)const {
        return h < rhs.h;
    }
}plk[MAXN];
int lazy[MAXN << 3];
vector<int> G[MAXN];
int dp[MAXN];

void build(int l, int r, int rt) {
    lazy[rt] = -1;
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson);
    build(rson);
}

void push_down(int rt) {
    if (~lazy[rt]) {
        lazy[ls] = lazy[rs] = lazy[rt];
        lazy[rt] = -1;
    }
}

int query(int p, int l, int r, int rt) {
    if (l == r) return lazy[rt];
    push_down(rt);
    int mid = l + r >> 1;
    if (p <= mid) return query(p, lson);
    else return query(p, rson);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if (L <= l && r <= R) {
        lazy[rt] = v;
        return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (L <= mid) update(L, R, v, lson);
    if (mid < R) update(L, R, v, rson);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, x;
    while (~scanf("%d", &m)) {
        n = 0;
        for (int i = 0; i < m; ++i) {
            plk[i].read();
            G[i].clear();
            dp[i] = -1;
            n = max(n, plk[i].r);
        }
        sort(plk, plk + m);
        build(root);
        for (int i = 0; i < m; ++i) {
            x = query(plk[i].l, root);
            G[i].push_back(x);
            x = query(plk[i].r, root);
            G[i].push_back(x);
            update(plk[i].l, plk[i].r, i, root);
        }
        dp[m - 1] = 100 + plk[m - 1].v;
        int ans = -1;
        for (int i = m - 1; i >= 0; --i) {
            if (dp[i] <= 0) continue;
            for (int j = 0; j < G[i].size(); ++j) {
                int v = G[i][j];
                if (~v) dp[v] = max(dp[v], dp[i] + plk[v].v);
                else ans = max(ans, dp[i]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
