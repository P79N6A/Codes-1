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
const int MAXN = 1e4 + 111;

string s;
bool vis[MAXN];

int main()
{
    cin >> s;
    int len = s.length();
    vis[0] = vis[len - 1] = 1;
    if (s[0] == '\"') {
        if (s[len - 1] == '\"') {
            int i;
            for (i = 1; i < len - 1; ++i) {
                if (vis[i]) continue;
                if (s[i] == '\"') break;
                if (s[i] == '\\' && islower(s[i + 1])) break;
                if (s[i] == '\\' && vis[i + 1]) break;
                if (s[i] == '\\') vis[i] = vis[i + 1] = 1;
            }
            if (i == len - 1) puts("Yes");
            else puts("No");
        }
        else puts("No");
    }
    else if (s[0] == '\'') {
        if (s[len - 1] == '\'') {
            int i;
            for (i = 1; i < len - 1; ++i) {
                if (vis[i]) continue;
                if (s[i] == '\'') break;
                if (s[i] == '\\' && islower(s[i + 1])) break;
                if (s[i] == '\\' && vis[i + 1]) break;
                if (s[i] == '\\') vis[i] = vis[i + 1] = 1;
            }
            if (i == len - 1) puts("Yes");
            else puts("No");
        }
        else puts("No");
    }
    else puts("No");
    return 0;
}
