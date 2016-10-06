/*
 * 多重匹配其实和二分差不多，也可用网络流求解
 * 本题求是否能够全部都能匹配上，所以只要一个不匹配即可返回
 */
const int MAXN = 100010;
const int MAXM = 12;
int n, m;
int g[MAXN][MAXM];
int linker[MAXM][MAXN];
bool used[MAXM];
int num[MAXM];//右边最大的匹配数
bool dfs(int u) {
    for(int v = 0; v < m;v++) {
        if(g[u][v] && !used[v]) {
            used[v] = true;
            if(linker[v][0] < num[v]) {
                linker[v][++linker[v][0]] = u;
                return true;
            }
            else {
                for(int i = 1;i <= num[v]; ++i) {
                    if(dfs(linker[v][i])){
                        linker[v][i] = u;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int hungary() {
    int res = 0;
    for(int i = 0;i < m; ++i) linker[i][0] = 0;
    for(int u = 0; u < n; ++u) {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
        else return false;
    }
    return true;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &g[i][j]);
            }
        }
        for(int i = 0;i < m; ++i) scanf("%d", &num[i]);
        if(hungary())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
