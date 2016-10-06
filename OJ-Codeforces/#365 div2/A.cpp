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
    int n, a, b;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    while (n --) {
        cin >> a >> b;
        if (a > b) ++ans1;
        else if (a < b) ++ans2;
    }
    if (ans1 > ans2) {
            cout << "Mishka\n";
        }
        else if (ans1 < ans2) cout << "Chris\n";
        else cout << "Friendship is magic!^^\n";
    return 0;
}
