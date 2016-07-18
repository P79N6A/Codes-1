/*
 ���ȣ����A->B��ֱ�ӵ�һ���������Ҵ���һ����������ĵ㵽��B��·�ߣ���ô����·�ߣ�
 Ҳ����A->B��ֱ���Ƕ���ġ�
 ��������۲죬Ҫ��ô�ж��أ������ó��ȳ���·�߷��ʣ�Ȼ���жϼ��ɡ���ô�ó��ȳ���
 ·���ȷ����أ�������Ȼ������߱�Ǹõ��Ѿ���ʲô����ʡ�����ʽǰ�������ȷ��ʺ�
 �ӽ�ȥ�Ľ��Ŷ~��
 PS:����ĳ��ȳ���·�߿������Ϊ��ƫ���ϵ����·��
 ��ô��ʼCODING��
*/
#include<algorithm>
#include<bitset>
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
const int MAXN = 2e4 + 111;
const int MAXM = 1e5 + 111;

struct Edge {
    int to, next;
}edge[2][MAXM];
int head[2][MAXN], tol[2];
int deg[MAXN];

void init(int n) {
    tol[0] = tol[1] = 0;
    for (int i = 1; i <= n; ++i) {
        head[0][i] = head[1][i] = -1;
        deg[i] = 0;
    }
}

void addedge(int u, int v, int who) {
    edge[who][tol[who]].to = v;
    edge[who][tol[who]].next = head[who][u];
    head[who][u] = tol[who]++;
}

int que[MAXN], l, r;
bitset<MAXN> bit[MAXN];
void topo(int n) {
    l = r = 0;
    for (int i = 1; i <= n; ++i) {
        bit[i].reset();
        bit[i][i] = 1;
        if (deg[i] == 0) {
            que[r++] = i;
            --deg[i];
        }
    }
    while (l < r) {
        int u = que[l++];
        for (int i = head[0][u]; ~i; i = edge[0][i].next) {
            int v = edge[0][i].to;
            if (--deg[v] == 0) {
                que[r++] = v;
            }
            addedge(v, u, 1);
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, u, v; scanf("%d", &t);
    while (t --) {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v, 0);
            ++deg[v];
        }
        topo(n);
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            u = que[i];
            for (int j = head[1][u]; ~j; j = edge[1][j].next) {
                v = edge[1][j].to;
                if (bit[u][v]) ++ans;
                bit[u] |= bit[v];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
