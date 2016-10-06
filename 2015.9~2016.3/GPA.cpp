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

double getmark(string s) {
    if (s == "A") return 4.0;
    else if (s == "A-") return 3.7;
    else if (s == "B+") return 3.3;
    else if (s == "B") return 3.0;
    else if (s == "B-") return 2.7;
    else if (s == "C+") return 2.3;
    else if (s == "C") return 2.0;
    else if (s == "C-") return 1.7;
    else if (s == "D") return 1.3;
    else if (s == "D-") return 1.0;
    else return 0;
}

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        double x;
        string s;
        double up = 0, down = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x >> s;
            up += x * getmark(s);
            if (s != "P" && s != "N")
                down += x;
        }
        if (down == 0) printf("0.00\n");
        else printf("%.2f\n", up / down);
    }
    return 0;
}
