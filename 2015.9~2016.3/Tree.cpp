#include<cstring>
#include<iostream>
#include<queue>
#include<sstream>
#include<string>
#define VI vector<int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

string inorder, posorder;
int x, ans, ansdep;
VI G[MAXN], in, pos;

void build(VI &a, VI &b)
{
    if (a.size() <= 1 || b.size() <= 1) return;
    int rt = b.back();

    VI::iterator it = find(a.begin(), a.end(), rt);
    VI la(a.begin(), it);
    VI ra(it + 1, a.end());

    int l = la.size(), r = ra.size();
    VI lb(b.begin(), b.begin() + l);
    VI rb(b.begin() + l, b.begin() + l + r);

    if (lb.size()) G[rt].push_back(lb.back());
    if (rb.size()) G[rt].push_back(rb.back());

    build(la, lb); build(ra, rb);
}

void dfs(int s, int dep)
{
    if (!G[s].size() && dep < ansdep) ansdep = dep, ans = s;
    else if (!G[s].size() && dep == ansdep) ans = min(ans, s);
    for (int i = 0; i < G[s].size(); ++i)
    {
        int v = G[s][i];
        dfs(v, dep + v);
    }
}

void init()
{
    in.clear(), pos.clear();
    stringstream ss(inorder);
    while (ss >> x) in.push_back(x);

    stringstream ss2(posorder);
    while (ss2 >> x) pos.push_back(x);

    for (int i = 1; i <= 1e4 + 11; ++i) G[i].clear();
    build(in, pos);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (getline(cin, inorder))
    {
        getline(cin, posorder);
        init();

        ansdep = INF;
        dfs(pos.back(), pos.back());
        cout << ans << '\n';
    }
    return 0;
}
