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
const int MAXN = 211;

double x[MAXN], y[MAXN];
const double eps = 1e-6;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    double k;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            if (x[j] == x[i]) {
                for (int l = j + 1; l < n; ++l) {
                    if (x[l] == x[j]) ++cnt;
                }
            }
            else {
                k = (y[j] - y[i]) / (x[j] - x[i]);
                for (int l = j + 1; l < n; ++l) {
                    if (x[l] == x[j]) continue;
                    double temp = (y[l] - y[j]) / (x[l] - x[j]);
                    if (fabs(temp - k) < eps) ++cnt;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans + 2 << '\n';
    return 0;
}
