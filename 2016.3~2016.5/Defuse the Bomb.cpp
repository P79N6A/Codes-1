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

int lable[5];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int d, t;
    cin >> t;
    while (t --) {
        vector<int> step;
        cin >> d;
        for (int i = 1; i <= 4; ++i) cin >> lable[i];
        if (d == 1) {
            cout << 2 << ' ' << lable[2] << '\n';
            step.push_back(2);
            for (int j = 1; j <= 4; ++j) {
                if (lable[j] == 4) {
                    cout << j << ' ' << 4 << '\n';
                    step.push_back(j);
                    break;
                }
            }
            cout << step[1] << ' ' << lable[step[1]] << '\n';
            for (int j = 0; j < 2; ++j)
                cout << step[0] << ' ' << lable[step[0]] << '\n';
        }
        else if (d == 2) {
            for (int j = 0; j < 3; ++j)
                cout << 2 << ' ' << lable[2] << '\n';
            cout << 1 << ' ' << lable[1] << '\n';
            cout << 2 << ' ' << lable[2] << '\n';
        }
        else if (d == 3) {
            cout << 3 << ' ' << lable[3] << '\n';
            step.push_back(3);
            cout << 1 << ' ' << lable[1] << '\n';
            cout << 3 << ' ' << lable[3] << '\n';
            for (int j = 0; j < 2; ++j)
                cout << 1 << ' ' << lable[1] << '\n';
        }
        else if (d == 4) {
            for (int j = 0; j < 2; ++j)
                cout << 4 << ' ' << lable[4] << '\n';
            int j;
            for (j = 1; j <= 4; ++j) {
                if (lable[j] == 4) {
                    cout << j << ' ' << 4 << '\n';
                    break;
                }
            }
            cout << 4 << ' ' << lable[4] << '\n';
            cout << j << ' ' << 4 << '\n';
        }
    }
    return 0;
}
