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

string col = "ROYGBIV";
string temp = "ROYG";

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (cin >> n) {
        int x = (n - 3) / 4;
        int lef = n - 4 * x;
        for (int i = 0; i < x; ++i) cout << temp;
        for (int i = 0; i < lef - 3; ++i) cout << col[i];
        for (int i = 4; i < 7; ++i) cout << col[i];
        cout << '\n';
    }
    return 0;
}
