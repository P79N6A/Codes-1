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
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

char s[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d%s", &n, s);
        stack<char> st, st2;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else if (st.size()) {
                st.pop();
                ++cnt;
            }
            else {
                st2.push(s[i]);
            }
        }
        if (st2.size() > 2 || st.size() > 2 || st.size() != st2.size() || (cnt == 1 && st2.size() == 0)) puts("No");
        else puts("Yes");
    }
    return 0;
}
