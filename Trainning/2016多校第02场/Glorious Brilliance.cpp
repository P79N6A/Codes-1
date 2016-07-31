/*
  ������ǲ��ϵĽ������ϵ����㣬ʹ��ͼ����
  ����ͼȾɫ�������ٵĽ���������
  һ���㣬Ҫô�Ǻ�ɫ��Ҫô�ǰ�ɫ���Ǿ�����
  ��һ���㡣
  �����Ǹõ��Ǻ�ɫ��ͼȾɫһ�Σ���ʱ��ͼ��
  �Ĳ��Ϸ����ҳ�����ɫ���ɫ���ߣ��ߵľ���
  ������Ҫ�����Ĵ��������ж���ͼ��СȨƥ��
  ���ɡ�Ȼ���ٿ��Ǹõ��ǰ�ɫ����ƥ�䣬ѡ��
  ƥ��ֵ��С����Ϊ�𰸡�
  Ⱦɫ������˳�����¸�ͼ�Ƿ��Ƕ���ͼ���ж�
  ����ȷ��case��
  ������ʹ��·���޹ص���ɫ����ķ�����A��Bƥ��Ϊ������
  ��ѡһ����Ϊ��㣬����ΪA�㣬A->B��·�����ҵ���һ��
  ��A��ɫ��ͬ�ĵ�C��Ȼ��һ·������ȥ������ΪA->C���·
  �����ȣ������м����ɫ����ͬ����������ɫ��ͬ������ֻ
  �ı���A��C����ɫ������C����ɫ�����A�������ɫ������
  ��C��ʼ�����ҵ���һ����ɫ��ͬ�ĵ�D�����ѭ�������ܱ�
  ֻ֤�ж˵����ɫ���ı��ˡ�
 */
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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 511;

//********* KM BN ***************
int nx, ny; // ���ߵĵ���
int g[MAXN][MAXN];
int linker[MAXN], lx[MAXN], ly[MAXN];
int slack[MAXN];
int visx[MAXN], visy[MAXN];

bool dfs(int x, int flag) {
    visx[x] = flag;
    for (int y = 0; y < ny; ++y) {
        if (visy[y] == flag) continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if (tmp == 0) {
            visy[y] = flag;
            if (linker[y] == -1 || dfs(linker[y], flag)) {
                linker[y] = x;
                return 1;
            }
        }
        else if (slack[y] > tmp) slack[y] = tmp;
    }
    return 0;
}

int KM() {
    memset(linker, -1, sizeof linker);
    memset(ly, 0, sizeof ly);
    memset(visx, 0, sizeof visx);
    memset(visy, 0, sizeof visy);
    for (int i = 0; i < nx; ++i) {
        lx[i] = -INF;
        for (int j = 0; j < ny; ++j) if (g[i][j] > lx[i]) {
            lx[i] = g[i][j];
        }
    }
    int cnt = 0;
    for (int x = 0; x < nx; ++x) {
        for (int i = 0; i < ny; ++i) slack[i] = INF;
        while (1) {
            if (dfs(x, ++cnt)) break;
            int d = INF;
            for (int i = 0; i < ny; ++i) {
                if (visy[i] != cnt && d > slack[i])
                    d = slack[i];
            }
            for (int i = 0; i < nx; ++i) {
                if (visx[i] == cnt) lx[i] -= d;
            }
            for (int i = 0; i < ny; ++i) {
                if (visy[i] == cnt) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < ny; ++i) {
        if (linker[i] != -1)
            res += g[linker[i]][i];
    }
    return -res;
}
//********* KM EN ***************

char s[MAXN];
vector<int> G[MAXN];
int col[MAXN];
vector<int> black, white;
int dis[MAXN][MAXN];
int pre[MAXN][MAXN];
int ans[2][1000000], acnt;

inline void init(int n) {
    acnt = 0;
    memset(dis, 0x3f, sizeof dis);
    memset(pre, -1, sizeof pre);
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        col[i] = -1;
    }
}

bool dye(int u, int c) {
    col[u] = c;
    if (c) white.push_back(u);
    else black.push_back(u);
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (col[v] == -1 && !dye(v, 1 - c)) return 0;
        if (col[v] == col[u]) return 0;
    }
    return 1;
}

bool in[MAXN];
void spfa(int s) {
    dis[s][s] = 0;
    queue<int> q;
    q.push(s);
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (dis[s][v] > dis[s][u] + 1) {
                pre[s][v] = u;
                dis[s][v] = dis[s][u] + 1;
                if (!in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
}

int match[2][MAXN];

int getCost(vector<int> &x, vector<int> &y, int tag) {
    vector<int> l, r;
    for (int i = 0; i < x.size(); ++i) {
        if (s[x[i]] == '1') l.push_back(x[i]);
    }
    for (int i = 0; i < y.size(); ++i) {
        if (s[y[i]] == '0') r.push_back(y[i]);
    }
    for (int i = 0; i < l.size(); ++i) {
        for (int j = 0; j < r.size(); ++j) {
            g[i][j] = -dis[l[i]][r[j]];
        }
    }
    nx = l.size(), ny = r.size();
    int cost = KM();
    for (int i = 0; i < r.size(); ++i) {
        int u = l[linker[i]], v = r[i];
        match[tag][u] = v, match[tag][v] = u;
    }
    return cost;
}

int sta[MAXN];
void getMatch(vector<int> &tem, int tag) {
    vector<int> t;
    for (int i = 0; i < tem.size(); ++i) {
        if (s[tem[i]] == '1') t.push_back(tem[i]);
    }
    char temp[555];
    memcpy(temp, s, sizeof s);
    for (int i = 0; i < t.size(); ++i) {
        int u = t[i], v = match[tag][u], pr = -1;
        int top = 0;
        sta[top++] = v;
        do {
            pr = pre[u][v];
            sta[top++] = pr;
            v = pr;
        } while (pr != u);
        int pos = 0;
        for (int i = 1; i < top; ++i) {
            if (temp[sta[i]] != temp[sta[pos]]) {
                for (int j = i; j > pos; --j) {
                    ans[0][acnt] = sta[j], ans[1][acnt++] = sta[j - 1];
                    swap(temp[sta[j]], temp[sta[j - 1]]);
                }
                pos = i;
            }
        }
    }
}

bool solve(int bg) {
    black.clear(), white.clear();
    if (!dye(bg, 0)) return 0;
    int cost1 = INF, cost2 = INF;
    int zero = 0;
    for (int i = 0; i < black.size(); ++i) {
        if (s[black[i]] == '0') ++zero;
    }
    for (int i = 0; i < white.size(); ++i) {
        if (s[white[i]] == '0') ++zero;
    }
    if (black.size() == zero) {
        cost1 = getCost(black, white, 0);
    }
    if (white.size() == zero) {
        cost2 = getCost(white, black, 1);
    }
    if (cost1 == INF && cost2 == INF) return 0;
    if (cost1 > cost2) getMatch(white, 1);
    else getMatch(black, 0);
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m, u, v;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d%s", &n, &m, s + 1);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) spfa(i);
        bool flag = 1;
        for (int i = 1; i <= n; ++i) {
            if (col[i] == -1 && !solve(i)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d\n", acnt);
            for (int i = 0; i < acnt; ++i) {
                printf("%d %d\n", ans[0][i], ans[1][i]);
            }
        }
        else puts("-1");
    }
    return 0;
}
