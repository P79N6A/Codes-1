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

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int a, v1, v2;
    while (cin >> a >> v1 >> v2) {
        if (a == 0) {
            cout << "0.00000000\n";
            continue;
        }
        if (v1 <= v2) {
            cout << "Infinity\n";
            continue;
        }
        printf("%.9f\n", 1.0 * a * v1 / (v1 + v2) / (v1 - v2));
    }
    return 0;
}
