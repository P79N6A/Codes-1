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
#define ull unsigned long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
ull base = 1331;

char s[50];
map<ull, int> mp;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    while (n --) {
        scanf("%s", s);
        int len = strlen(s);
        ull sum = 0;
        sort(s, s + len);
        for (int i = 0; i < len; ++i) {
            sum *= base;
            sum += s[i];
        }
        printf("%d\n", mp[sum]);
        ++mp[sum];
    }
    return 0;
}
