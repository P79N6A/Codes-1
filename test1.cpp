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

bool mp[500][500];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "w", stdout);
    #endif
    cout << 50 << ' ' << 35 << '\n';
    srand((unsigned)time(NULL));
    for (int i = 0; i < 50; ) {
        int x = rand() % 500, y = rand() % 500;
        if (mp[x][y]) continue;
        ++i;
        cout << x << ' ' << y << '\n';
        mp[x][y] = 1;
    }
    return 0;
}
