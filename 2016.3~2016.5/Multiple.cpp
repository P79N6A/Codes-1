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
const int MAXN = 1e6 + 111;

int num[11], ans[6000];
bool vis[6000];
struct P {
    int num;
    int pre;
    int mod;
}q[6000];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < m; ++i) {
            scanf("%d", &num[i]);
        }
        sort(num, num + m);

        if (n == 0) {
            printf("0\n");
            continue;
        }

        P st;
        st.mod = 0;
        st.pre = -1;
        int head = 0, tail = 0;
        q[tail++] = st;
        memset(vis, 0, sizeof vis);
        bool ok = 1;
        while (head < tail) {
            P cur = q[head++];
            if (cur.mod == 0 && cur.pre != -1) {
                ok = 0;
                int cnt = 0;
                while (cur.pre != -1) {
                    ans[cnt++] = cur.num;
                    cur = q[cur.pre];
                }
                for (int i = cnt - 1; i >= 0; --i) printf("%d", ans[i]);
                break;
            }

            int temp = cur.mod;
            for (int i = 0; i < m; ++i) {
                if (cur.pre == -1 && num[i] == 0) continue;
                cur.num = num[i];
                cur.pre = head - 1;
                cur.mod = (cur.mod * 10 + num[i]) % n;
                if (!vis[cur.mod]) {
                    vis[cur.mod] = 1;
                    q[tail++] = cur;
                }
                cur.mod = temp;
            }
        }
        if (ok) printf("0");
        putchar('\n');
    }
    return 0;
}
