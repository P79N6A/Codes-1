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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 51;

int n, ans;
int mp[MAXN][MAXN];
int cnt[MAXN]; // i~n的点集构成的最大团数目
int id[MAXN]; // 团中元素的标号
int group[MAXN]; // 最大团中的元素

// 当前结点为u， 团中元素个数为tol
bool dfs(int u, int tol) {
    for (int i = u + 1, j; i < n; ++i) {
        // 如果取点i但是点i能达到的最大和目前的相加比答案还小，可以直接返回了。
        if (cnt[i] + tol <= ans) return 0;
        if (mp[u][i]) {
            for (j = 0; j < tol; ++j) {
                if (!mp[i][id[j]]) break;
            }
            if (j == tol) {
                id[tol] = i;
                if (dfs(i, tol + 1)) return 1;
            }
        }
    }
    // 每增加一个点，最大团个数至多加1，如果比答案大，说明就是目前最优了。
    if (tol > ans) {
// 记录路径用
//        for (int i = 0; i < tol; ++i)
//            group[i] = id[i];
        ans = tol;
        return 1;
    }
    return 0;
}

void MaxClique() {
    ans = -1;
    for (int i = n - 1; i >= 0; --i) {
        id[0] = i;
        dfs(i, 1);
        cnt[i] = ans;
        if (ans == n) return; // 达到上界就别计算下去了
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &mp[i][j]);
        MaxClique();
        printf("%d\n", ans);
    }
    return 0;
}
