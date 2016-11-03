#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pic pair<int, char>
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 511;

ll b[MAXN];
vector<int> a;

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, x, k;
    ll asum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a.push_back(x);
        asum += x;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
        if (i)
            b[i] += b[i - 1];
    }
    int len = 0, pos = 0, sum = 0, off = 0, l = 0;
    vector<pic> ans;
    bool flag = false;
    while (pos != a.size()) {
        sum += a[pos];
        if (sum == b[len]) {
            if (pos - l == 0) {
                ++len;
                l = pos + 1;
                ++pos;
                continue;
            }
            int mx = 0;
            for (int j = l; j <= pos; ++j) {
                if (a[j] > mx) {
                    mx = a[j];
                }
            }
            int wei = -1;
            int op = 0;
            for (int j = l; j <= pos; ++j) {
                if (a[j] == mx) {
                    if (j > l && a[j - 1] != mx) {
                        wei = j;
                        break;
                    }
                    if (j < pos && a[j + 1] != mx) {
                        wei = j;
                        op = 1;
                        break;
                    }
                }
            }
            if (wei == -1) {
                flag = true;
                break;
            }
            int r = pos;
            if (op) {
                while (wei < r) {
                    ans.push_back(make_pair(wei - off, 'R'));
                    --r;
                }
                while (wei > l) {
                    ans.push_back(make_pair(wei - off, 'L'));
                    --wei;
                }
            }
            else {
                while (wei > l) {
                    ans.push_back(make_pair(wei - off, 'L'));
                    --wei;
                    --r;
                }
                while (wei < r) {
                    ans.push_back(make_pair(wei - off, 'R'));
                    --r;
                }
            }
            ++len;
            off += pos - l;
            l = pos + 1;
        }
        ++pos;
    }
    if (asum != b[k - 1] || len != k || flag) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < ans.size(); ++i) {
            printf("%d %c\n", ans[i].first + 1, ans[i].second);
        }
    }
    return 0;
}