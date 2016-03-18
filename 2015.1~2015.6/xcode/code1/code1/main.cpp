#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define bug puts("I am bug")
#define xy(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;

int num[2];


int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] - '0')
        {
            ++num[1];
        }
        else ++num[0];
    }
    cout << abs(num[1] - num[0]) << '\n';
    return 0;
}
