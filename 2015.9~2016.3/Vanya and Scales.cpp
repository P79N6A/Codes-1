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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

int num[MAXN];

int main()
{
    int w, m;
    while (cin >> w >> m) {
        int top = 0;
        int x = m;
        while (x) {
            num[top++] = x % w;
            x /= w;
        }

        num[top] = 0;
        bool ok = 1;
        for (int i = 0; i <= top; ++i) {
            if (num[i] != 0 && num[i] != 1 && num[i] != w && num[i] != w - 1) {
                ok = 0;
                break;
            }
            if (num[i] == w || num[i] == w - 1) ++num[i + 1];
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
