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
const int MAXN = 111;

int p[MAXN];
string name[MAXN];
map<string, int> id;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        id[s] = i;
        cin >> s;
        p[i] = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '.') continue;
            p[i] *= 10;
            p[i] += s[j] - '0';
        }
    }
    cin.ignore();
    for (int i = 1; i <= m; ++i) {
        getline(cin, s);
        int cnt = 0;
        stringstream ss(s);
        do {
            ss >> name[cnt++];
        }while (ss);
        --cnt;
        int sum = 0;
        for (int j = 0; j < cnt - 2; j += 2) {
            sum += p[id[name[j]]];
        }
        int cmp = 0;
        for (int j = 0; j < name[cnt - 1].length(); ++j) {
            cmp *= 10;
            cmp += name[cnt - 1][j] - '0';
        }
        bool flag;
        s = name[cnt - 2];
        cmp *= 10;

        if (s == "<") flag = (sum < cmp);
        else if (s == ">") flag = (sum > cmp);
        else if (s == "<=") flag = (sum <= cmp);
        else if (s == ">=") flag = (sum >= cmp);
        else flag = (sum == cmp);

        cout << "Guess #" << i << " was ";
        cout << (flag == 1 ? "correct." : "incorrect.") << '\n';
    }
    return 0;
}
