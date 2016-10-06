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
#define double long double
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct V
{
    double v;
    int id;
    V(double _v = 0, int _id = 0): v(_v), id(_id){}
    bool operator < (const V t)const
    {
        return v < t.v;
    }
}vec[MAXN];
double x, y;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        vec[i] = V(atan2(y , x), i + 1);
    }

    sort(vec, vec + n);

    int ansl = vec[n - 1].id, ansr = vec[0].id;
    double ans = 2 * acos(-1) - vec[n - 1].v + vec[0].v;
    for (int i = 0; i < n - 1; ++i)
    {
        double del = vec[i + 1].v - vec[i].v;
        if (ans > del)
        {
            ans = del;
            ansl = vec[i + 1].id, ansr = vec[i].id;
        }
    }
    cout << ansl << ' ' << ansr << '\n';
    return 0;
}
