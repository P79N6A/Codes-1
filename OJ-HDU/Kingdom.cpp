#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 505;

int n;
char mp[MAXN][MAXN];
int deg[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        memset(deg, 0, sizeof deg);
        for (int i = 0; i < n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j < n; ++j) {
                if (mp[i][j] == '1') ++deg[j];
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int w = 0, mx = -1;
            for (int j = 0; j < n; ++j) {
                if (deg[j] > mx) {
                    mx = deg[j];
                    w = j;
                }
            }
            ans.push_back(w + 1);
            for (int j = 0; j < n; ++j) {
                if (mp[w][j] == '1') --deg[j];
            }
            deg[w] = -1;
        }
        printf("%d", ans[n - 1]);
        for (int i = n - 2; i >= 0; --i) printf(" %d", ans[i]);
        putchar('\n');

    }
    return 0;
}
