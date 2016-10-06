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

const int INF = 0x7f7f7f7f;
const int MAXN = 51;

int n, m, top, seq[MAXN];
vector<int> G[MAXN];
int in[MAXN], tin[MAXN];

int topsort() {
    bool uncer = 0;
    top = 0; // ��ջ��ʼ��
    for (int i = 0; i < n; ++i) tin[i] = in[i]; // ������ȣ����ں��ڴ�������ԭ������ƻ�

    queue<int> q;
    int cnt = 0; // ��ǰ״̬��Ҫ����ĵ����
    for (int i = 0; i < n; ++i) {
        if (tin[i] == 0) q.push(i); // Ѱ�ҳ�ʼ��
        if (G[i].size()) ++cnt;
    }

    if (q.empty()) return 1;

    while (q.size()) {
        if (q.size() > 1) uncer = 1; // ���Ϊ0�����1�������ڣ����Բ�ȷ��
        int u = q.front(); q.pop();
        seq[top++] = u; // �洢��
        --cnt;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (--tin[v] == 0) {
                q.push(v);
            }
        }
    }

    if (cnt > 0) return 1; // û������ȫ����˵����ì�ܳ���
    if (uncer) return 0;
    else return 2; // ȫ�������ˣ���û��ì�ܣ��������
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    char s[5];
    while (~scanf("%d%d", &n, &m) && (n | m)) {
        for (int i = 0; i < n; ++i) G[i].clear(), in[i] = 0;
        int sta = 0, ans;
        for (int i = 1; i <= m; ++i) {
            scanf("%s", s);
            if (sta) continue; // 1����2ȷ����Ϳɲ��ü��������ж���
            int a = s[2] - 'A', b = s[0] - 'A';
            G[a].push_back(b);
            ++in[b];
            sta = topsort();
            if (sta) ans = i; // ��¼�ǵڼ��仰
        }

        if (sta == 0) printf("Sorted sequence cannot be determined.\n");
        else if (sta == 1) printf("Inconsistency found after %d relations.\n", ans);
        else {
            printf("Sorted sequence determined after %d relations: ", ans);
            for (int i = top - 1; i >= 0; --i) printf("%c", seq[i] + 'A');
            printf(".\n");
        }
    }
    return 0;
}
