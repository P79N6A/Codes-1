#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int x[MAXN], y[MAXN];    // Ϊ1�ı����ӵ�����
int ex[MAXN], ey[MAXN];  // Ϊ0�ı����ӵ�����
struct Edge
{
    int w, id;
    bool in;
    Edge(int _w = 0, bool _in = 0, int _id = 0):w(_w), in(_in), id(_id){}
    bool operator < (const Edge &t)const
    {
        if (w == t.w) return in > t.in;  // ע�⻹Ҫ��0��1����
        return w < t.w;
    }
}edge[MAXN];

int main()
{
    int n, m, u, w; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &u, &w);
        edge[i] = Edge(u, w, i);
    }
    sort(edge, edge + m);

    bool flag = 0;
    // cnt:1->2->3->..   cnt2:ͳ�Ƶ���cnt2Ϊֹ��Ҫ�����������
    // ecnt:���Թ����ı�
    int cnt = 1, cnt2 = 0, ecnt = 0;
    for (int i = 0; i < m; ++i)
    {
        int id = edge[i].id;
        if (edge[i].in)
        {
            x[id] = cnt, y[id] = ++cnt;
            if (ecnt > 1e5) continue; // �����Թ���n * n����Ȼ��1e5�͹���
            for (int j = 1; j <= cnt - 2; ++j) // ÿ��һ�������½����ı�
            {
                ex[ecnt] = cnt, ey[ecnt++] = j;
                if (ecnt > 1e5) break;
            }
        }
        else
        {
            x[id] = ex[cnt2], y[id] = ey[cnt2];
            ++cnt2;
            if (ecnt < cnt2) // �ɽ����ı��� < ��Ҫ����֮���ȻΥ��MST����
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag) printf("-1\n");
    else
    {
        for (int i = 0; i < m; ++i)
            printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}
