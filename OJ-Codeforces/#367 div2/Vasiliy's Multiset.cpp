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
const int MAXN = 2e5 + 111;

struct Node {
    int nxt[2];
    int val, num;
    Node() {
        nxt[0] = nxt[1] = -1;
        val = 0;
        num = 0;
    }
}trie[MAXN * 30];

int pos;

int extend() {
    ++pos;
    trie[pos] = Node();
    return pos;
}

void build(int x) {
    int p = 0;
    ++trie[p].num;
    for (int i = 30; i >= 0; --i) {
        bool flag = x & (1 << i);
        if (trie[p].nxt[flag] == -1) {
            trie[p].nxt[flag] = extend();
        }
        p = trie[p].nxt[flag];
        ++trie[p].num;
    }
    trie[p].val = x;
}

void del(int x) {
    int p = 0;
    --trie[p].num;
    for (int i = 30; i >= 0; --i) {
        bool flag = x & (1 << i);
        int last = p;
        p = trie[p].nxt[flag];
        if (--trie[p].num == 0) trie[last].nxt[flag] = -1;
    }
    trie[p].val = 0;
}

int query(int x) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        bool flag = x & (1 << i);
        if (trie[p].nxt[1 - flag] != -1) p = trie[p].nxt[1 - flag];
        else p = trie[p].nxt[flag];
    }
    return x ^ trie[p].val;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int q, x; scanf("%d", &q);
    map<int, int> mp;
    pos = -1;
    extend();
    char op[2];
    while (q --) {
        scanf("%s %d", op, &x);
        if (op[0] == '+') {
            if (++mp[x] == 1) {
                build(x);
            }
        }
        else if (op[0] == '-') {
            if (--mp[x] == 0) {
                del(x);
            }
        }
        else printf("%d\n", max(x, query(x)));
    }
    return 0;
}
