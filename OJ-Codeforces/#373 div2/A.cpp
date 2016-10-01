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
const int MAXN = 1e6 + 111;

int a[200];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        if (a[0] == 0) {
            cout << "UP\n";
        }
        else if (a[0] == 15) {
            cout << "DOWN\n";
        }
        else cout << -1 << '\n';
    }
    else {
        if (a[n - 1] > a[n - 2]) {
            if (a[n - 1] == 15) cout << "DOWN\n";
            else cout << "UP\n";
        }
        else {
            if (a[n - 1] == 0) cout << "UP\n";
            else cout << "DOWN\n";
        }
    }
    return 0;
}
