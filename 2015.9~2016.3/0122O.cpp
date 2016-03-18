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

int a[MAXN], id[MAXN];
bool vis[MAXN];
bool cmp(int x, int y) {
    if (a[x] == a[y]) return x < y;
    else return a[x] < a[y];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, k;
    cin >> n;
    string s;
    map<string, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        mp[s] = i;
    }

    cin >> m;
    int ans = -1, p = INF;
    for (int i = 1; i <= m; ++i) {
        cin >> k;
        int cnt = 0;
        for (int j = 0; j < k; ++j) {
            cin >> s;
            if (mp[s]) {
                id[cnt] = cnt;
                a[cnt++] = mp[s];
            }
        }
        int temp = 0;

        memset(vis, 0, sizeof vis);
        sort(id, id + cnt, cmp);

        int flag = 0, pos = 0;
        int ccnt = 0;
        while (++flag <= n) {
            for (int j = 0; j < cnt; ++j) {
                if (a[id[j]] == flag) {
                    if (id[j] >= pos) {
                        vis[id[j]] = 1;
                        pos = max(id[j], pos);
                        ++ccnt;
                        break;
                    }
                    else if (j + 1 < cnt && a[id[j + 1]] == flag) {
                        continue;
                    }
                    else {
                        vis[id[j]] = 1;
                        pos = max(pos,id[j]);
                        ++ccnt;
                        break;
                    }
                }
            }
        }

        for (int j = 0; j < cnt; ++j) {
            if (!vis[j]) continue;
            for (int k = 0; k < j; ++k) {
                if (!vis[k]) continue;
                if (a[k] > a[j]) ++temp;
            }
        }
        if (ccnt == n && p > temp) {
            p = temp;
            ans = i;
        }
    }

    if (ans == -1) cout << "Brand new problem!\n";
    else {
        p = n * (n - 1) / 2 - p + 1;
        cout << ans << '\n';
        cout << "[:";
        for (int i = 0; i < p; ++i) cout << '|';
        cout << ":]\n";
    }

    return 0;
}
