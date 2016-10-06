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

int par[MAXN];
map<int, bool> mp;
set<int>::iterator it;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x;
    while (~scanf("%d", &n)) {
        int rt = -1;
        set<int> s;
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            if (i == 1) rt = x;
            else {
                it = s.lower_bound(x);
                if (it == s.end()) {
                    --it;
                    par[i] = *it;
                }
                else {
                    if (!mp[*it]) par[i] = *it, mp[*it] = 1;
                    else {
                        --it;
                        par[i] = *it;
                    }
                }
            }
            s.insert(x);
        }
        for (int i = 2; i <= n; ++i) {
            printf("%d", par[i]);
            if (i != n) putchar(' ');
            else putchar('\n');
        }
    }
    return 0;
}
