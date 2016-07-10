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

int ok[10][4];
bool okk[4];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    string s;
    cin >> n >> s;
    ok[0][0] = 1;
    ok[1][1] = ok[1][2] = 1;
    ok[2][1] = ok[2][2] = ok[2][3] = 1;
    ok[3][2] = ok[3][3] = 1;
    ok[4][0] = ok[4][1] = ok[4][2] = 1;
    ok[5][0] = ok[5][1] = ok[5][2] = ok[5][3] = 1;
    ok[6][0] = ok[6][2] = ok[6][3] = 1;
    ok[7][0] = ok[7][1] = 1;
    ok[8][0] = ok[8][1] = ok[8][2] = ok[8][3] = 1;
    ok[9][0] = ok[9][3] = 1;
    okk[0] = okk[1] = okk[2] = okk[3] = 1;
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';
        for (int j = 0; j < 4; ++j) {
            okk[j] &= ok[x][j];
        }
    }
    bool flag = 0;
    for (int i = 0; i < 4; ++i) {
        flag |= okk[i];
    }
    if (!flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
