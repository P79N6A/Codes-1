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
int cnt[MAXN]; // i~n�ĵ㼯���ɵ��������Ŀ
int id[MAXN]; // ����Ԫ�صı��
int group[MAXN]; // ������е�Ԫ��

// ��ǰ���Ϊu�� ����Ԫ�ظ���Ϊtol
bool dfs(int u, int tol) {
    for (int i = u + 1, j; i < n; ++i) {
        // ���ȡ��i���ǵ�i�ܴﵽ������Ŀǰ����ӱȴ𰸻�С������ֱ�ӷ����ˡ�
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
    // ÿ����һ���㣬����Ÿ��������1������ȴ𰸴�˵������Ŀǰ�����ˡ�
    if (tol > ans) {
// ��¼·����
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
        if (ans == n) return; // �ﵽ�Ͻ�ͱ������ȥ��
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
