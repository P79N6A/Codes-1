#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int ans[12];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s1, s2;
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        ans[i] = sum % 7;
        sum += month[i];
    }
    while (cin >> s1 >> s2) {
        int a = 0, b = 0;
        for (int i = 0; i < 7; ++i) {
            if (s1 == day[i]) a = i;
            if (s2 == day[i]) b = i;
        }
        bool flag = 0;
        for (int i = 0; i < 12; ++i) {
            if (ans[i] - ans[(i + 1) % 12] == a - b) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}
