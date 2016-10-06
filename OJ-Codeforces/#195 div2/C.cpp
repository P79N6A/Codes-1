/*
  观察发现，取了某一位为1的，所有这种类型都要添加才是最优的。
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
const int MAXN = 1e5 + 111;

vector<int> ans[32];
int sum[32];

void work(int x) {
    for (int i = 0; i < 32; ++i) {
        if (x & (1 << i)) {
            if (!sum[i]) sum[i] = x;
            else sum[i] &= x;
            ans[i].push_back(x);
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        work(x);
    }
    for (int i = 31; i >= 0; --i) {
        if (!sum[i]) continue;
        bool flag = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (sum[i] & (1 << j)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << ans[i].size() << '\n';
            for (int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << ' ';
            }
            break;
        }
    }
    return 0;
}
