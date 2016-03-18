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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 1e5 + 111;

int n, k, x;

struct P {
    int id; // ��¼ԭλ��
    int sum[30];
    bool operator < (const P &t)const {
        for (int i = 0; i < k; ++i) {
            if (sum[i] != t.sum[i]) return sum[i] < t.sum[i];
        }
        return id < t.id;
    }
}p[MAXN];

int pos[MAXN]; // ��¼������ﱾͷţ��Զ������ֵ��ͬ��ţλ�á�0����û��

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &k);
    p[0].id = 0;
    for (int i = 0; i < k; ++i) p[0].sum[i] = 0;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        p[i].id = i;
        for (int j = 0; j < k; ++j) {
            p[i].sum[j] = p[i - 1].sum[j] + (x & 1);
            x >>= 1;
        }
        if (p[i].sum[0]) { // �����һ�����ж�������ֱ�Ӽ�ȥ��һλ
            for (int j = 0; j < k; ++j) p[i].sum[j] -= 1;
        }
    }

    sort(p, p + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        bool flag = 1;
        for (int j = 0; j < k; ++j) {
            //printf("%d ", p[i].sum[j]);
            if (p[i].sum[j] != p[i - 1].sum[j]) {
                flag = 0;
                break;
            }
        }
        //printf("%d\n", p[i].id);
        if (flag) { // ���������ͬ
            if (pos[i - 1] == 0) pos[i] = i - 1;
            else pos[i] = pos[i - 1];
            ans = max(ans, p[i].id - p[pos[i]].id);
        }
    }
    printf("%d\n", ans);
    return 0;
}
