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
const int MAXN = 4e5 + 111;

int nxt[MAXN];
char p[MAXN];

void getNext(int len) {
    int k = -1;
    nxt[0] = -1;
    for (int i = 0; i < len; nxt[++i] = ++k) {
        while (k != -1 && p[k] != p[i]) k = nxt[k];
        //printf("%d ", nxt[i]);
    }
    //putchar('\n');
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%s", p)) {
        int len = strlen(p);
        getNext(len);
        vector<int> ans;
        ans.push_back(len);
        int t = nxt[len - 1];
        while (t != -1) {
            //pr(p[t]);
            if (p[t] == p[len - 1]) {
                ans.push_back(t + 1);
            }
            t = nxt[t];
        }
        for (int i = ans.size() - 1; i >= 0; --i) {
            printf("%d", ans[i]);
            if (i == 0) putchar('\n');
            else putchar(' ');
        }
    }
    return 0;
}
