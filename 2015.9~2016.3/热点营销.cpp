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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int p[MAXN];
bool has[MAXN];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int i = 1; i < MAXN; ++i) p[i] = i;
    int u, v;
    while (~scanf("%d%d", &u, &v)) {
        //has[u] = has[v] = 1;
        u = find(u);
        v = find(v);
        if (u != v) p[u] = v;
    }

    set<int> st;
    for (int i = 1; i <= 1e5; ++i) {
        //if (has[i]) {
            st.insert(find(i));
       // }
    }

    cout << st.size() << endl;
    return 0;
}
