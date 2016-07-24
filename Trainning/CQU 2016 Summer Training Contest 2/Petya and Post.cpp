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
const int MAXN = 1e5 + 111;

int a[MAXN], dis[MAXN];
ll l[MAXN], r[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    ll fuel = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        fuel += a[i];
        r[i] = l[i] = -a[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &dis[i]);
        sum += dis[i];
    }
    for (int i = 0; i < n; ++i) {
        r[0] += a[i];
        if (r[0] < dis[i]) {
            r[0] = dis[i];
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= l[i] || a[i] >= r[i]) ans.push_back(i + 1);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
    return 0;
}
