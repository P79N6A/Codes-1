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
const int MAXN = 1111;

int a[MAXN];
int b[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> b[i], a[i] = i;
    for (int i = n; i >= 1; --i) {
        if (b[i]) {
            int num = i + k;
            for (int j = i; j < n; ++j) {
                swap(a[j], a[j + 1]);
                if (a[j] >= num) {
                    if (--b[i] == 0) break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}
