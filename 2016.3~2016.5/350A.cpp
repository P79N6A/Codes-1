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

int main()
{
    int n;
    while (cin >> n) {
        cout << n / 7 * 2 + (n % 7 == 6) << ' ';
        if (n >= 2) {
            n -= 2;
            cout << 2 + n / 7 * 2 + (n % 7 == 6) << '\n';
        }
        else cout << 1 << '\n';
    }
    return 0;
}
