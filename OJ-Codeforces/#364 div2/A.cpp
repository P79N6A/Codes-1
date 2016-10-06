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
const int MAXN = 111;

int a[MAXN];
bool use[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; cin >> n;
    int sum = 0, peo = n / 2;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    int ever = sum / peo;

    for (int i = 0; i < peo; ++i) {
        int lef = 0;
        for (int j = 0; j < n; ++j) {
            if (!use[j]) {
                use[j] = 1;
                cout << j + 1 << ' ';
                lef = ever - a[j];
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!use[j] && a[j] == lef) {
                use[j] = 1;
                cout << j + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
