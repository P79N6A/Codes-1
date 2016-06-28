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
const int MAXN = 3e5 + 111;

struct Trie {
    int nxt[MAXN][26];
    int time[MAXN];
    int len = -1, rt = 0;

    Trie() {
        add();
    }

    int add() {
        ++len;
        time[len] = 0;
        for (int i = 0; i < 26; ++i) {
            nxt[len][i] = -1;
        }
        return len;
    }

    void insert(char *s) {
        int l = strlen(s);
        int x = 0;
        for (int i = 0; i < l; ++i) {
            int p = s[i] - 'a';
            if (~nxt[x][p]) x = nxt[x][p];
            else x = nxt[x][p] = add();
            time[x] += 1;
        }
    }

    int query(char *s) {
        int l = strlen(s);
        int x = 0;
        for (int i = 0; i < l; ++i) {
            int p = s[i] - 'a';
            if (~nxt[x][p]) x = nxt[x][p];
            else return 0;
        }
        return time[x];
    }
};

char s[20];
Trie ac;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        ac.insert(s);
    }
    scanf("%d", &n);
    while (n --) {
        scanf("%s", s);
        printf("%d\n", ac.query(s));
    }
    return 0;
}
