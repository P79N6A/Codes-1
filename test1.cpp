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
const double PI = acos(-1);

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "w", stdout);
    #endif
    int n = 10, m = 10, q = 100;
    cout << n << ' ' << m << ' ' << q << '\n';
    int op, a, b;
    srand((unsigned)time(NULL));
    for (int i = 1; i <= q; ++i) {
        op = rand() % 4 + 1;
        cout << op << ' ';
        if (op == 1 || op == 2) {
            cout << rand() % n + 1 << ' ' << rand() % n + 1 << '\n';
        }
        else if (op == 3) cout << rand() % n + 1 << '\n';
        else cout << rand() % i << '\n';
    }
    return 0;
}
