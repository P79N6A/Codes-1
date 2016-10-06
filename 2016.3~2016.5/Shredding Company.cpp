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

bool flag;
string b;
int ans, a;
vector<int> apos;

void dfs(int p, int sum, vector<int> pos) {
    if (p == b.length()) {
        int last = pos.back(), tsum = 0;
        for (int i = last; i < p; ++i) {
            tsum *= 10;
            tsum += b[i] - '0';
        }
        sum += tsum;
        if (sum <= a) {
            if (sum > ans) {
                ans = sum;
                apos = pos;
                flag = 0;
            }
            else if (sum == ans) {
                flag = 1;
            }
        }
        return;
    }

    // ²»È¡
    dfs(p + 1, sum, pos);

    // È¡
    if (p != 0) {
        int last = pos.back(), tsum = 0;
        for (int i = last; i < p; ++i) {
            tsum *= 10;
            tsum += b[i] - '0';
        }
        pos.push_back(p);
        dfs(p + 1, sum + tsum, pos);
    }
    return;
}

int main()
{
    while (cin >> a >> b) {
        if (a == 0 && b == "0") break;
        ans = -1;
        apos.clear();
        vector<int> pos;
        pos.push_back(0);
        dfs(0, 0, pos);

        if (ans == -1) cout << "error\n";
        else if (flag) cout << "rejected\n";
        else {
            apos.push_back(b.length());
            cout << ans;
            for (int i = 1; i < apos.size(); ++i) {
                cout << ' ';
                for (int j = apos[i - 1]; j < apos[i]; ++j)
                    cout << b[j];
            }
            cout << '\n';
        }
    }
    return 0;
}
