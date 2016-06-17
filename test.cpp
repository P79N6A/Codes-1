#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, mod, head[100005];
int idx, lim, edge, top;
int stk[1000100];

struct Edge {
    int v, next;
}e[1000100]; // 每个节点只能够引出10条边

char vis[1000100];

void insert(int a, int b) {
    e[idx].v = b;
    e[idx].next = head[a];
    head[a] = idx++;
}

void dfs() {
    stk[top++] = 0;
    while (1) {
        int flag = 0;
        int v = stk[top-1]; // 取出栈顶元素
        if (top == edge-(N-2)) { // 由于遍历的是点，因此从一个点N个9到N个0最终无法到达，中间也就少了N-2个状态
            return;
        }
        for (int i = head[v]; i != -1; i = e[i].next) {
            if (!vis[i]) {
                flag = 1;
                vis[i] = 1;
                //if (top < 4) printf("%d\n", e[i].v);
                stk[top++] = e[i].v;
                break;
            }
        }
        if (!flag) {
            --top;
        }
    }
}

int main() {
    while (scanf("%d", &N), N) {
        if (N == 1) {
            printf("0123456789\n");
            continue;
        }
        idx = top = 0;
        memset(head, 0xff, sizeof (head));
        memset(vis, 0, sizeof (vis));
        lim = 1;
        for (int i = 1; i < N; ++i) {
            lim *= 10;
        }
        edge = lim * 10;
        mod = lim / 10; // mod用来提取后后几位
        printf("%d\n", mod);
        for (int i = 0; i < lim; ++i) {
            for (int j = 9; j >= 0; --j) { // 十个状态转移
                insert(i, (i%mod)*10+j);
            }
        }
        dfs();
        for (int i = 0; i < top-1; ++i) {
            //if (i < 5) printf("\n test = %d \n", stk[i]);
            printf("%d", stk[i]/mod);
        }
        printf("%d", stk[top-1]);
        for (int i = 1; i < N; ++i) {
            printf("0");
        }
        puts("");
    }
    return 0;
}
