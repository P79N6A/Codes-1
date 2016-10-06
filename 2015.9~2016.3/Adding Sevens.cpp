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
const int MAXN = 1e6 + 111;

int getn[200];
string s, num[2];
string mp[10];

void preInit() {
    getn[63] = 0, getn[10] = 1, getn[93] = 2,
    mp[0] = "063", mp[1] = "010", mp[2] = "093",
    getn[79] = 3, getn[106] =4, getn[103]= 5,
    mp[3] = "079", mp[4] = "106", mp[5] = "103",
    getn[119]= 6, getn[11] = 7, getn[127]= 8,
    mp[6] = "119", mp[7] = "011", mp[8] = "127",
    getn[107]= 9, mp[9] = "107";
}

void init() {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] < '0' || s[i] > '9') s[i] = ' ';
    }
    stringstream ss(s);
    int cnt = 0;
    while (ss >> num[cnt]) {
        ++cnt;
    }
}

int getNum(int x) {
    ll sum = 0;
    for (int i = 0; i < num[x].length(); i += 3) {
        ll tsum = 0;
        for (int j = 0; j < 3; ++j) {
            tsum += num[x][i + j] - '0';
            tsum *= 10;
        }
        sum += getn[tsum / 10];
        sum *= 10;
    }
    return sum / 10;
}

void getAns(int sum) {
    string temp;
    while (sum) {
        int x = sum % 10;
        temp += mp[x];
        sum /= 10;
    }
    for (int i = temp.length() - 3; i >= 0; i -= 3) {
        for (int j = 0; j < 3; ++j)
            cout << temp[i + j];
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    preInit();
    ios_base::sync_with_stdio(0);
    while (cin >> s && s != "BYE") {
        init();
        int a = getNum(0), b = getNum(1);
        cout << num[0] << '+' << num[1] << '=';
        getAns(a + b);
        cout << '\n';
    }
    return 0;
}
