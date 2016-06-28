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
const int MAXN = 1e6 + 111;

char s[4] = "IDQ";

bool has[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "w", stdout);
    #endif
    srand((unsigned)time(NULL));
    int n = rand() % 100000 + 1;
    cout << n << '\n';
    for (int i = 0; i < n;) {
        int op = rand() % 3;
        if (op == 0) {
            int x = rand() % 10000 + 1;
            if (!has[x]) {
                has[x] = 1;
                cout << s[0] << ' ' << x << '\n';
                ++i;
            }
        }
        else if (op == 1) {
            int a = rand() % 10000 + 1, b = rand() % 10000 + 1;
            if (a > b) swap(a, b);
            for (int j = a; j <= b; ++j) has[j] = 0;
            cout << s[1] << ' ' << a << ' ' << b << '\n';
            ++i;
        }
        else {
            int x = rand() % 10000 + 1;
            bool flag = 0;
            for (int i = 1; i <= x; ++i) {
                if (has[i]) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                cout << s[2] << ' ' << x << '\n';
                ++i;
            }
        }
    }
    return 0;
}
