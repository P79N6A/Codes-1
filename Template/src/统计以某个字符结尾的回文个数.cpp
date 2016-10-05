/*
 * 原题HDU5785：任意给定三元组i<j<=k,使得s[i,j - 1],s[j, k]
 * 均为回文串，问这样的三元组值的和？(i,j,k)值为i*k
 *
 * 主要思想就是回文中心+1，回文边界-1，然后累加和即可，代码
 * 中cnt数组即可求某个结尾的回文个数
 * 对称点下标 = 回文中心 * 2 - 当前点的下标
 * 所以在回文中心加上一个中心*2,边界减去这个值
 * suml代表：以i开头的回文串值的和
 * sumr代表：以i结尾的回文串值的和
 */
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
const int MOD = 1000000007;

char Ma[MAXN << 1];
int Mp[MAXN << 1];
char s[MAXN];
ll suml[MAXN], sumr[MAXN], cnt[MAXN];

int Manacher(int len) {
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for (int i = 0; i < len; ++i) {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0, cnt = 0;
    for (int i = 0; i < l; ++i) {
        Mp[i] = mx > i ? min(Mp[2*id - i], mx - i) : 1;
        while (Ma[i + Mp[i]]==Ma[i - Mp[i]]) ++Mp[i];
        if (i + Mp[i] > mx) {
            mx = i + Mp[i];
            id = i;
        }
    }
    return l;
}

int main()
{
    while (~scanf("%s", s)) {
        int n = strlen(s);
        int l = Manacher(n);
        memset(cnt, 0, sizeof cnt);
        memset(sumr, 0, sizeof sumr);
        for (int i = 2; i < l; ++i) {
            int len = (Mp[i] - 1) / 2;
            if (i % 2 == 0) {
                int base = i / 2;
                ++cnt[base];
                --cnt[base + len + 1];
                sumr[base] += 2 * base;
                sumr[base + len + 1] -= 2 * base;
            }
            else {
                int base = i / 2;
                ++cnt[base + 1];
                --cnt[base + len + 1];
                sumr[base + 1] += 2 * base + 1;
                sumr[base + len + 1] -= 2 * base + 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            sumr[i] += sumr[i - 1];
            cnt[i] += cnt[i - 1];
            cnt[i] %= MOD;
            sumr[i] %= MOD;
        }
        for (int i = 1; i <= n; ++i) {
            sumr[i] = (sumr[i] - i * cnt[i]) % MOD;
            sumr[i] += MOD;
        }
        memset(cnt, 0, sizeof cnt);
        memset(suml, 0, sizeof suml);
        for (int i = l - 2; i >= 2; --i) {
            int len = (Mp[i] - 1) / 2;
            if (i % 2 == 0) {
                int base = i / 2;
                ++cnt[base];
                --cnt[base - len - 1];
                suml[base] += 2 * base;
                suml[base - len - 1] -= 2 * base;
            }
            else {
                int base = i / 2;
                ++cnt[base];
                --cnt[base - len];
                suml[base] += 2 * base + 1;
                suml[base - len] -= 2 * base + 1;
            }
        }
        for (int i = n; i >= 1; --i) {
            suml[i] += suml[i + 1];
            cnt[i] += cnt[i + 1];
            cnt[i] %= MOD;
            suml[i] %= MOD;
        }
        for (int i = n; i >= 1; --i) {
            suml[i] = (suml[i] - i * cnt[i]) % MOD;
            suml[i] += MOD;
        }
        ll ans = 0;
        for (int i = 1; i < n; ++i) {
            //printf("%lld %lld\n", sumr[i], suml[i + 1]);
            ans = (ans + sumr[i] * suml[i + 1]) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
