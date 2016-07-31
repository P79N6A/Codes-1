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
int avl[MAXN][MAXN]; // ÿ��Ŀ��е�
int cnt[MAXN]; // i~n�ĵ㼯���ɵ��������Ŀ
int id[MAXN]; // ����Ԫ�صı��
int group[MAXN]; // ������е�Ԫ��

// ��ǰ���н�����Ϊcur�� ����Ԫ�ظ���Ϊtol
bool dfs(int cur, int tol) {
    if (cur == 0) {
        if (tol > ans) {
            ans = tol;
            return 1;
        }
        return 0;
    }
    for (int i = 0; i < cur; ++i) {
        if (cur - i + tol <= ans) return 0;
        int u = avl[tol][i];
        // ���ȡ��i���ǵ�i�ܴﵽ������Ŀǰ����ӱȴ𰸻�С������ֱ�ӷ����ˡ�
        if (cnt[u] + tol <= ans) return 0;
        int nxt = 0;
        for (int j = i + 1; j < cur; ++j) {
            if (mp[u][avl[tol][j]])
                avl[tol + 1][nxt++] = avl[tol][j];
        }
        id[tol] = u;
        if (dfs(nxt, tol + 1)) return 1;
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
        int cur = 0;
        for (int j = i + 1; j < n; ++j) {
            if (mp[i][j]) avl[1][cur++] = j; // �ɴ�����Ӧ�÷��ʵĵ�
        }
        id[0] = i;
        dfs(cur, 1);
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
