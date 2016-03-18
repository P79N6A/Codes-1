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
const int MAXN = 1e5 + 111;

int main()
{
    string s;
    char sta[MAXN];
    while (cin >> s) {
        int top = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (top == 0) {
                sta[top++] = s[i];
            }
            else {
                char temp = sta[top - 1];
                if (temp != s[i]) {
                    sta[top++] = s[i];
                }
                else --top;
            }
        }
        if (top == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
