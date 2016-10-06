#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int p[MAXN];
int qt[MAXN], qv[MAXN], mark[MAXN];
int t;

int find(int x) {
    return mark[x] < t ? x : p[x] = find(p[x]); // С����˵���ڲ�ѯ֮ǰ�Ѿ�Ⱦ����ɫ
}

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q) && (n | q)) {
        for (int i = 2; i <= n; ++i) {
            scanf("%d", p + i);
            mark[i] = INF;
        }

        int cnt = 0, x;
        char op[2];
        for (int i = 1; i <= q; ++i) {
            scanf("%s%d", op, &x);
            if (op[0] == 'M') mark[x] = min(mark[x], i); // ��¼����Ⱦɫʱ��
            else {
                qt[cnt] = i;
                qv[cnt++] = x;
            }
        }

        ll ans = 0;
        while (cnt --) {
            t = qt[cnt]; // ��ѯ������ʱ��
            ans += find(qv[cnt]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
