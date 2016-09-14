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
const int MAXN = 1e5 + 111;

struct Trie{
    int num[MAXN * 3], nx[MAXN * 3][2];
    int rt, l;
    char temp[20];
    int newnode() {
        nx[l][0] = nx[l][1] = -1;
        num[l++] = 0;
        return l - 1;
    }
    void init() {
        l = 0;
        rt = newnode();
    }
    void inst(char *s) {
        int len = strlen(s);
        for (int i = 0; i < len; ++i) temp[len - i - 1] = ((s[i] - '0') % 2) + '0';
        for (int i = len; i < 18; ++i) temp[i] = '0';
        int cur = rt;
        for (int i = 0; i < 18; ++i) {
            if (nx[cur][temp[i] - '0'] == -1)
                nx[cur][temp[i] - '0'] = newnode();
            cur = nx[cur][temp[i] - '0'];
            if (i >= len - 1) ++num[cur];
        }
    }
    void del(char *s) {
        int len = strlen(s);
        for (int i = 0; i < len; ++i) temp[len - i - 1] = ((s[i] - '0') % 2) + '0';
        for (int i = len; i < 18; ++i) temp[i] = '0';
        int cur = rt;
        for (int i = 0; i < 18; ++i) {
            cur = nx[cur][temp[i] - '0'];
            if (i >= len - 1) --num[cur];
        }
    }
    int query(char *s) {
        int len = strlen(s);
        for (int i = 0; i < len; ++i) temp[len - i - 1] = ((s[i] - '0') % 2) + '0';
        for (int i = len; i < 18; ++i) temp[i] = '0';
        int cur = rt;
        for (int i = 0; i < 18; ++i) {
            if (nx[cur][temp[i] - '0'] == -1)
                break;
            cur = nx[cur][temp[i] - '0'];
        }
        return num[cur];
    }
}trie;

char s[20], op[2];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    trie.init();
    while (t --) {
        scanf("%s%s", &op, &s);
        if (op[0] == '+') {
            trie.inst(s);
        }
        else if (op[0] == '-') {
            trie.del(s);
        }
        else {
            printf("%d\n", trie.query(s));
        }
    }
    return 0;
}
