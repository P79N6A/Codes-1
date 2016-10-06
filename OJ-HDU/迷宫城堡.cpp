/*
 * ǿ��ͨ������һ������������ͼ
 * tarjan���Ӷ�: O(n + m)
 * �����ж��Ƿ�ֻ��һ����ͨ�飬����HDU 1269
 */

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 11;
const int MAXM = 1e5 + 11;

struct Edge {
    int to, next;
}edge[MAXM];
int head[MAXN], tol;
int low[MAXN], dfn[MAXN], Stack[MAXN], Belong[MAXN];
int index, top;
int block;
bool inStack[MAXN];

void add_edge(int u, int v) {
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

void init() {
    memset(head, -1, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(inStack, 0, sizeof inStack);
    index = top = block = 0;
    tol = 0;
}

void tarjan(int u) {
    int v;
    low[u] = dfn[u] = ++index;
    Stack[top++] = u;
    inStack[u] = 1;

    for (int i = head[u]; ~i; i = edge[i].next) {
        v = edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
            low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) { // ����
        ++block;
        do {
            v = Stack[--top];
            inStack[v] = 0;
            Belong[v] = block;
        }while (v != u);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    while (~scanf("%d%d", &n, &m) && (n | m)) {
        init();
        while (m --) {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
        puts(block == 1 ? "Yes" : "No");
    }
    return 0;
}
