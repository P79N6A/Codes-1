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
    string s;
    getline(cin, s);
    int add = 1, mis = 0;
    int i;
    for (i = 0; i < s.length(); ++i) {
        if (s[i] == '+') ++add;
        if (s[i] == '-') ++mis;
        if (s[i] == '=') break;
    }
    i += 2;
    int sum = 0;
    for (; i < s.length(); ++i) {
        sum *= 10;
        sum += s[i] - '0';
    }

    int ans1[200];
    int ans2[200];
    if (add * sum - mis < sum || add - mis * sum > sum) cout << "Impossible\n";
    else {
        cout << "Possible\n";
        for (int i = 0; i < add; ++i) ans1[i] = sum;
        for (int i = 0; i < mis; ++i) ans2[i] = sum;
        int l = add * sum;
        int r = sum + mis * sum;
        int i = 0, j = 0;
        while (l != r) {
            if (l < r) {
                for (; i < mis; ++i) {
                    if (ans2[i] > 1) {
                        --ans2[i];
                        --r;
                        break;
                    }
                }
            }
            else {
                for (; j < add; ++j) {
                    if (ans1[j] > 1) {
                        --ans1[j];
                        --l;
                        break;
                    }
                }
            }
        }
        cout << ans1[0];
        i = 1, j = 0;
        for (int k = 1; k < s.length(); ++k) {
            if (s[k] == '?') {
                if (s[k - 2] == '+') cout << ans1[i++];
                else cout << ans2[j++];
            }
            else cout << s[k];
        }
        putchar('\n');
    }
    return 0;
}
