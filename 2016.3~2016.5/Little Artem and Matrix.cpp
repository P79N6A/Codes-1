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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

int mp[MAXN][MAXN];
pii org[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, q;
    while (~scanf("%d%d%d", &n, &m, &q)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mp[i][j] = 0;
                org[i][j] = pii(i, j);
            }
        }

        int op, u, v, w;
        while (q --) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &w);
                --w;
                pii temp = org[w][0];
                for (int i = 0; i < m - 1; ++i) {
                    org[w][i] = org[w][i + 1];
                }
                org[w][m - 1] = temp;
            }
            else if (op == 2) {
                scanf("%d", &w);
                --w;
                pii temp = org[0][w];
                for (int i = 0; i < n - 1; ++i) {
                    org[i][w] = org[i + 1][w];
                }
                org[n - 1][w] = temp;
            }
            else {
                scanf("%d%d%d", &u, &v, &w);
                --u, --v;
                pii temp = org[u][v];
                u = temp.first, v = temp.second;
                mp[u][v] = w;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << mp[i][j];
                if (j != m - 1) cout << ' ';
                else cout << '\n';
            }
        }
    }
    return 0;
}
