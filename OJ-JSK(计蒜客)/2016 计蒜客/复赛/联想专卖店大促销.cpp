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
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, a, b, c; scanf("%d", &t);
    while (t --) {
        scanf("%d%d%d", &a, &b, &c);
        int tempa = a, tempb = b, tempc = c;
        int ans = 0;
        int ans2 = 0;
        int pre = -1;
        if (a > b && a > 1 && b) {
            a -= 2, --b;
            ++ans;
            pre = 1;
        }
        else if (b > 1 && a) {
            b -= 2; --a;
            ++ans;
            pre = 2;
        }
        while (1) {
            bool ok = 1;
            //pr(pre)
            if (pre != 0 && c && b && a) {
                --c, --b, --a;
                ++ans;
                pre = 0;
                ok = 0;
            }
            else {
                if (a > b) {
                    if (a > 1 && b && pre != 1) {
                        a -= 2, --b;
                        ++ans;
                        pre = 1;
                        ok = 0;
                    }
                    else if (b > 1 && a && pre != 2) {
                        --a, b -= 2;
                        ++ans;
                        pre = 2;
                        ok = 0;
                    }
                }
                else {
                    if (b > 1 && a && pre != 2) {
                        --a, b -= 2;
                        ++ans;
                        pre = 2;
                        ok = 0;
                    }
                    else if (a > 1 && b && pre != 1) {
                        a -= 2, --b;
                        ++ans;
                        pre = 1;
                        ok = 0;
                    }
                }
            }
            if (ok) break;
        }
        a = tempa, b = tempb, c = tempc;
        pre = -1;
        while (1) {
            bool ok = 1;
            //pr(pre)
            if (pre != 0 && c && b && a) {
                --c, --b, --a;
                ++ans2;
                pre = 0;
                ok = 0;
            }
            else {
                if (a > b) {
                    if (a > 1 && b && pre != 1) {
                        a -= 2, --b;
                        ++ans2;
                        pre = 1;
                        ok = 0;
                    }
                    else if (b > 1 && a && pre != 2) {
                        --a, b -= 2;
                        ++ans2;
                        pre = 2;
                        ok = 0;
                    }
                }
                else {
                    if (b > 1 && a && pre != 2) {
                        --a, b -= 2;
                        ++ans2;
                        pre = 2;
                        ok = 0;
                    }
                    else if (a > 1 && b && pre != 1) {
                        a -= 2, --b;
                        ++ans2;
                        pre = 1;
                        ok = 0;
                    }
                }
            }
            if (ok) break;
        }
        printf("%d\n", max(ans2, ans));
    }
    return 0;
}
