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
const int MAXN = 2e5 + 111;

int a[MAXN];
int dis[MAXN];
bool in[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        dis[i] = INF;
    }
    queue<int> q;
    in[1] = 1;
    dis[1] = 0;
    q.push(1);
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        int v = a[u];
        if (u + 1 <= n) {
            if (dis[u + 1] > dis[u] + 1) {
                dis[u + 1] = dis[u] + 1;
                if (!in[u + 1]) {
                    in[u + 1] = 1;
                    q.push(u + 1);
                }
            }
        }
        if (u - 1 >= 1) {
            if (dis[u - 1] > dis[u] + 1) {
                dis[u - 1] = dis[u] + 1;
                if (!in[u - 1]) {
                    in[u - 1] = 1;
                    q.push(u - 1);
                }
            }
        }
        if (dis[v] > dis[u] + 1) {
            dis[v] = dis[u] + 1;
            if (!in[v]) {
                in[v] = 1;
                q.push(v);
            }
        }
    }
    printf("%d", dis[1]);
    for (int i = 2; i <= n; ++i) {
        printf(" %d", dis[i]);
    }
    return 0;
}
