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
const int MAXN = 21;

int a[MAXN], b[MAXN];
int val[MAXN];

vector<int> G[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        --u, --v;
        if (u < v)
            G[u].push_back(v);
        else
            G[v].push_back(u);
    }
    int up = 1 << n;
    int ans = -INF;
    for (int i = 0; i < up; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                val[j] = a[j];
            }
            else val[j] = b[j];
        }
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            int mi = val[j], mx = val[j];
            for (int k = 0; k < G[j].size(); ++k) {
                int v = G[j][k];
                mi = min(mi, val[v]);
                mx = max(mx, val[v]);
            }
            double x = mx - mi;
            //pr(x)pr(val[j])
            if (G[j].size()) {
                //pr(temp)
               // pr(x)
                //pr(ceil(x / 1000.0))
                temp = temp + (val[j] - ceil(x / 1000.0) * 666 * (j + 1));
                //pr(temp)
            }
            else temp += val[j];
        }
        ans = max(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}
