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

const int MAXN = 111;

char s[MAXN], t[MAXN];
int ans = 0;

struct Trie {
    int next[50000][26], end[50000];
    int root, L;
    int newnode() {
        for (int i = 0; i < 26; ++i) next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; ++i) {
            int &x = next[now][buf[i] - 'a'];
            if (x == -1)
                x = newnode();
            now = x;
        }
        end[now]++;
        if (end[now] == 1) ++ans;
    }
};

Trie ac;

int main()
{
    int kase; scanf("%d", &kase);
    while (kase --) {
        scanf("%s", s);
        ac.init();
        ans = 0;
        memset(t, 0, sizeof t);
        int len = strlen(s);

        for (int pos = 1; pos < len; ++pos) {
            reverse(s, s + pos);
            ac.insert(s); // 转+不转
            reverse(s + pos, s + len);
            ac.insert(s); // 转+转
            reverse(s, s + pos);
            ac.insert(s); // 不转+转
            reverse(s + pos, s + len);

            int cnt = 0;
            for (int i = pos; i < len; ++i) t[cnt++] = s[i];
            for (int i = 0; i < pos; ++i) t[cnt++] = s[i];
            ac.insert(t); // 交换后啥都不干
            reverse(t, t + len - pos);
            ac.insert(t); // 转+不转
            reverse(t + len - pos, t + len);
            ac.insert(t); // 转+转
            reverse(t, t + len - pos);
            ac.insert(t); // 不转+转
        }
        printf("%d\n", ans);
    }
    return 0;
}
