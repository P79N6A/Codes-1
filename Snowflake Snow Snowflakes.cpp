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
const int BASE = 99991;

struct Snow {
    int len[6];
}snow;

vector<Snow> hashtable[BASE];

bool ok(Snow &a, Snow &b) {
    for (int i = 0; i < 6; ++i) {
        // 顺序比较
        bool flag = 1;
        for (int j = 0; j < 6; ++j) {
            if (a.len[j] != b.len[(j + i) % 6]) {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;

        // 逆序比较
        flag = 1;
        for (int j = 0; j < 6; ++j) {
            if (a.len[5 - j] != b.len[(j + i) % 6]) {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    while (n --) {
        int sum = 0;
        for (int i = 0; i < 6; ++i) {
            scanf("%d", &snow.len[i]);
            sum += snow.len[i];
            sum %= BASE;
        }
        hashtable[sum].push_back(snow);
    }
    for (int i = 0; i < BASE; ++i) {
        if (hashtable[i].size() > 1) {
            for (int j = 0; j < hashtable[i].size(); ++j) {
                for (int k = j + 1; k < hashtable[i].size(); ++k) {
                    if (ok(hashtable[i][j], hashtable[i][k])) {
                        printf("Twin snowflakes found.\n");
                        return 0;
                    }
                }
            }
        }
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
