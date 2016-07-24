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

string jud = "aeiou", s;

bool judge(string s, int cnt) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < jud.size(); ++j) {
            if (s[i] == jud[j]) {
                ++ans;
                break;
            }
        }
    }
    return ans == cnt;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    bool flag = 1;
    getline(cin, s);
    flag &= judge(s, 5);
    getline(cin, s);
    flag &= judge(s, 7);
    getline(cin, s);
    flag &= judge(s, 5);
    cout << (flag ? "YES\n" : "NO\n");
    return 0;
}
