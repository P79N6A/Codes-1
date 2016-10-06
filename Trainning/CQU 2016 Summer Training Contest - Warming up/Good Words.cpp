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
    int t;
    cin >> t;
    string a, b;
    while (t --) {
        cin >> a >> b;
        if (a.find(b) != -1) {
            cout << "good\n";
        }
        else {
            bool flag = 0;
            for (int i = 0; i < 4; ++i) {
                string temp = b;
            b.erase(i, 1);
//                    pr(b)
                if (a.find(b) != -1) {
                    flag = 1;
                    break;
                }
                b = temp;
            }
            if (flag) cout << "almost good\n";
            else cout << "none\n";
        }
    }
    return 0;
}
