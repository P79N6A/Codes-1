/*
  bug��¼���������if����˸�else
  lazy���£�ֱ��Ĭ��Ϊ1�ˡ�����Ӧ����lazy = 1 - lazy
  ��ϯ��pushdown��ʱ�������ŵ������䶼��Ҫpushdown���������Ӷ�̫��
  ��������lazy�Ǳ�����䷭ת�����ģ����Կ���ֱ���ۼ���ȥ����Ҫ��ʱ���ټ��㡣
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
const int MAXN = 1e6 + 111;

struct SegT {
    int ls, rs, sum, lazy;
}tree[MAXN * 22];
int tol, root[MAXN * 22];

inline int get(int l, int r, int rt) {
    int ret = tree[rt].sum;
    if (tree[rt].lazy) ret =  r - l + 1 - ret;
    return ret;
}

int build(int l, int r) {
    int x = ++tol;
    tree[x].sum = 0;
    tree[x].lazy = 0;
    if (l == r) return x;
    int mid = (l + r) >> 1;
    tree[x].ls = build(l, mid);
    tree[x].rs = build(mid + 1, r);
    return x;
}

void push_up(int l, int r, int rt) {
    int ls = tree[rt].ls, rs = tree[rt].rs;
    int mid = l + r >> 1;
    tree[rt].sum = get(l, mid, ls) + get(mid + 1, r, rs);
}

int update(int l, int r, int rt, int pos, int val, int lz) {
    lz ^= tree[rt].lazy;
    int x = ++tol;
    tree[x] = tree[rt];
    if (l == r) {
        if (!lz) {
            tree[x].sum = val;
        }
        else tree[x].sum = !val;
        return x;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) tree[x].ls = update(l, mid, tree[rt].ls, pos, val, lz);
    else tree[x].rs = update(mid + 1, r, tree[rt].rs, pos, val, lz);
    push_up(l, r, x);
    return x;
}

int exupdate(int l, int r, int rt, int L, int R) {
    int x = ++tol;
    tree[x] = tree[rt];
    if (L <= l && r <= R) {
        tree[x].lazy ^= 1;
        return x;
    }
    int mid = l + r >> 1;
    if (L <= mid) tree[x].ls = exupdate(l, mid, tree[rt].ls, L, R);
    if (mid < R) tree[x].rs = exupdate(mid + 1, r, tree[rt].rs, L, R);
    push_up(l, r, x);
    return x;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    int len = n * m - 1;
    root[0] = build(0, len);
    int op, i, j;
    int last = 0;
    for (int x = 1; x <= q; ++x) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &i, &j);
            --i, --j;
            root[x] = update(0, len, root[last], i * m + j, 1, 0);
        }
        else if (op == 2) {
            scanf("%d%d", &i, &j);
            --i, --j;
            root[x] = update(0, len, root[last], i * m + j, 0, 0);
        }
        else if (op == 3) {
            scanf("%d", &i);
            --i;
            root[x] = exupdate(0, len, root[last], i * m, i * m + m - 1);
        }
        else {
            scanf("%d", &i);
            root[x] = root[i];
        }
        last = x;
        printf("%d\n", get(0, len, root[last]));
    }
    return 0;
}
