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
const int MAXN = 111;

char mp[MAXN][50] = {
"+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n",
"|...|:::|...|:::|...|:::|...|:::|\n",
"+---+---+---+---+---+---+---+---+\n",
"|:::|...|:::|...|:::|...|:::|...|\n",
"+---+---+---+---+---+---+---+---+\n"};

void solve(string s, int offset) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ':' || s[i] == ',') {
            s[i] = ' ';
        }
    }
    stringstream ss(s);
    string t;
    while (ss >> t) {
        if (t == "White" || t == "Black") continue;
        int x, y;
        if (t.length() == 3) {
            x = t[2] - '0';
            x = 8 - x + 1;
            y = t[1] - 'a' + 1;
            mp[2 * x - 1][4 * y - 2] = t[0] + offset;
        }
        else {
            x = t[1] - '0';
            x = 8 - x + 1;
            y = t[0] - 'a' + 1;
            mp[2 * x - 1][4 * y - 2] = 'P' + offset;
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s;
    getline(cin, s);
    solve(s, 0);
    getline(cin, s);
    solve(s, 32);

    for (int i = 0; i < 17; ++i)
        printf("%s", mp[i]);
    return 0;
}
