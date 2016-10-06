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
const int MAXN = 111;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (cin >> n) {
        int day = 0, relex = 1;
        a[n] = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i == 0) {
                if (a[i] == 0) {
                    ++day;
                }
                else {
                    relex = 0;
                }
            }
            else {
                switch(a[i]) {
                    case 0: {
                        ++day;
                        relex = 1;
                        break;
                    }
                    case 1: {
                        if (relex) {
                            relex = 0;
                        }
                        else {
                            if (a[i - 1] == 1) {
                                ++day;
                                relex = 1;
                            }
                        }
                        break;
                    }
                    case 2: {
                        if (relex) {
                            relex = 0;
                        }
                        else {
                            if (a[i - 1] == 2) {
                                ++day;
                                relex = 1;
                            }
                        }
                        break;
                    }
                    case 3: {
                        if (relex) {
                            relex = 0;
                            if (a[i + 1] == 1) a[i] = 2;
                            else if (a[i + 1] == 2) a[i] = 1;
                        }
                        else {
                            if (a[i - 1] == 1) {
                                a[i] = 2;
                            }
                            else if (a[i - 1] == 2) {
                                a[i] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout << day << '\n';
    }
    return 0;
}
