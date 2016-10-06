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
    int n;
    cin >> n;
    if (n % 2) {
        int x = (n - 1) / 2;
        for (int i = 0; i < x; ++i) {
            cout << "I hate that I love that ";
        }
        cout << "I hate it\n";
    }
    else {
        int x = (n - 2) / 2;
        for (int i = 0; i < x; ++i) {
            cout << "I hate that I love that ";
        }
        cout << "I hate that I love it\n";
    }
    return 0;
}
