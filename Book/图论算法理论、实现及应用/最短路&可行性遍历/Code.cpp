/* ���⣺
 * ����ֵ�����С�����ִ���ʹ��ÿ�����ƶ�һλ���ɵ�n������ȫ�����е���
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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct Edge {
    int v, nxt;
}edge[MAXN * 10];
int head[MAXN], tol, mx, mod;
bool vis[MAXN * 10];
int sta[MAXN * 10], top, sum, n;

// ��������ǳ���Ϊn - 1��״̬
void addedge(int u, int v) {
    edge[tol].v = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

void dfs(int s) {
    top = 0;
    //int ok = 0;
    sta[top++] = s;
    while (1) {
        //ok = max(top, ok); pr(ok)
        // ����n - 1��0������n - 2��9�ǲ��ᵽ���״̬����Ϊ��modȡ��һ�����ֵĹ�ϵ
        if (top == sum + n - 1 - (2 * n - 3)) break;
        int u = sta[top - 1], i;
        for (i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (!vis[i]) {
                vis[i] = 1;
                sta[top++] = v;
                break;
            }
        }
        if (i == -1) {
            --top;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    while (cin >> n && n) {
        if (n == 1) {
            cout << "0123456789\n";
            continue;
        }
        memset(head, -1, sizeof head);
        memset(vis, 0, sizeof vis);
        tol = 0;
        mx = 1;
        for (int i = 1; i < n; ++i) mx *= 10; // pow(10, n - 1) �о��������ȥ= =
        sum = mx * 10;
        mod = mx / 10;
        for (int i = 0; i < mx; ++i) {
            for (int j = 9; j >= 0; --j) {
                addedge(i, (i % mod) * 10 + j); // ��ʽǰ���ǣ������ֵ�����С
            }
        }
        dfs(0);
        for (int i = 0; i < top - 1; ++i) {
            cout << sta[i] / mod;
        }
        cout << sta[top - 1];
        for (int i = 1; i < n; ++i) cout << 0;
        cout << '\n';
    }
    return 0;
}
