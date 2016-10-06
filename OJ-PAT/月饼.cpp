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
const int MAXN = 1111;

struct P {
    double num;
    double gain;
    bool operator < (const P& t)const {
        return num * t.gain < t.num * gain;
    }
}p[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> p[i].num;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].gain;
    }
    sort(p, p + n);
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (d >= p[i].num) {
            ans += p[i].gain;
            d -= p[i].num;
        }
        else {
            ans += 1.0 * p[i].gain / p[i].num * d;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
