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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string a, b;
    while (cin >> a >> b) {
        int suma = 0, sumb = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] > b[i]) ++suma;
            if (a[i] < b[i]) ++sumb;
            printf("%d %d\n", a[i], b[i]);
        }
        if (suma > sumb) cout << "TEAM 1 WINS\n";
        else if (suma < sumb) cout << "TEAM 2 WINS\n";
        else cout << "TIE\n";
    }
    return 0;
}
