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
const int MAXN = 1e3 + 111;

int l[MAXN], r[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, x; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int root = -1;
        string ans[MAXN];
        set<int> s;
        set<int>::iterator it;
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (root == -1) root = x;
            else {
                it = s.upper_bound(x);
                if (it == s.end()) {
                    --it;
                    l[*it] = x;
                    ans[x] = ans[*it] + "W";
                }
                else {
                    if (r[*it] == 0) {
                        r[*it] = x;
                        ans[x] = ans[*it] + "E";
                    }
                    else {
                        --it;
                        l[*it] = x;
                        ans[x] = ans[*it] + "W";
                    }
                }
            }
            s.insert(x);
        }
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            cout << ans[x] << '\n';
        }
    }
    return 0;
}
