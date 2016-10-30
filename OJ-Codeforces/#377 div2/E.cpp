#include <bits/stdc++.h>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

struct P {
    int id, power;
    bool operator < (const P &t)const {
        return power < t.power;
    }
    void read(int idd) {
        scanf("%d", &power);
        id = idd;
    }
}p[MAXN], s[MAXN];
int a[MAXN], b[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    multiset<P> ms;
    for (int i = 0; i < n; ++i) {
        p[i].read(i);
        ms.insert(p[i]);
    }
    for (int i = 0; i < m; ++i) {
        s[i].read(i);
    }
    sort(s, s + m);
    int u = 0, c = 0;
    for (int i = 0; i < m; ++i) {
        int id = s[i].id;
        int power = s[i].power;
        int cnt = 0, tol = 0;
        while (tol != 2) {
            if (power == 1) ++tol;
            auto it = ms.lower_bound(P{0, power});
            if (it != ms.end() && (*it).power == power) {
                a[id] = cnt;
                b[(*it).id] = id + 1;
                ms.erase(it);
                ++c;
                u += cnt;
                break;
            }
            power = ceil(power / 2.0);
            ++cnt;
        }
    }
    printf("%d %d\n", c, u);
    for (int i = 0; i < m; ++i) {
        printf("%d ", a[i]);
    }
    putchar('\n');
    for (int i = 0; i < n; ++i) {
        printf("%d ", b[i]);
    }
    return 0;
}
