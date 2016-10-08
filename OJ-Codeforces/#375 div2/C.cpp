#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2011;

int a[MAXN];
struct P {
    int id;
    vector<int> pos;
    bool operator < (const P& t)const {
        return pos.size() < t.pos.size();
    }
}p[MAXN];
vector<int> num[MAXN];
bool use[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        p[i].id = i;
        p[i].pos.clear();
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= m) {
            p[a[i]].pos.push_back(i);
            use[i] = 1;
        }
    }
    sort(p + 1, p + 1 + m);
    int cnt = 0;
    int len = 0;
    int need = n / m;
    for (int i = m; i >= 1; --i) {
        while (p[i].pos.size() > need) {
            use[p[i].pos.back()] = 0;
            p[i].pos.pop_back();
        }
        while (p[i].pos.size() < need) {
            for (int j = 1; j <= n; ++j) {
                if (!use[j]) {
                    use[j] = 1;
                    a[j] = p[i].id;
                    p[i].pos.push_back(j);
                    break;
                }
            }
            ++cnt;
        }
    }
    cout << n / m << ' ' << cnt << '\n';
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}
