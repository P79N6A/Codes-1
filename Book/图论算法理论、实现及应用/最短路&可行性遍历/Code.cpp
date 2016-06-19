/* 题意：
 * 输出字典序最小的数字串，使得每向右移动一位构成的n个数是全排列中的数
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

// 结点代表的是长度为n - 1的状态
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
        // 最后的n - 1个0和最后的n - 2个9是不会到达的状态，因为除mod取第一个数字的关系
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
        for (int i = 1; i < n; ++i) mx *= 10; // pow(10, n - 1) 有精度误差我去= =
        sum = mx * 10;
        mod = mx / 10;
        for (int i = 0; i < mx; ++i) {
            for (int j = 9; j >= 0; --j) {
                addedge(i, (i % mod) * 10 + j); // 链式前向星，这样字典序最小
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
