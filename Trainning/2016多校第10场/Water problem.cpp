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
const int MAXN = 1111;

int num[22] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int num2[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
int ans[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    for (int i = 1; i < 20; ++i) {
        ans[i] = ans[i - 1] + num[i];
    }
    for (int i = 20; i <= 1000; ++i) {
        ans[i] = ans[i - 1];
        int temp = i;
        vector<int> wei;
        while (temp) {
            wei.push_back(temp % 10);
            temp /= 10;
        }
        if (wei[1] > 1) {
            ans[i] += num2[wei[1]] + num[wei[0]];
        }
        else if (wei[1] <= 1) {
            ans[i] += num[wei[1] * 10 + wei[0]];
        }
        if (wei.size() == 3) {
            ans[i] += num[wei[2]] + 7;
            if (wei[1] || wei[0]) ans[i] += 3;
        }
        else if (wei.size() == 4) {
            ans[i] += 11;
        }
    }
    while (t --) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
