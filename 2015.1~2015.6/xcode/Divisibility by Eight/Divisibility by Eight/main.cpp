#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    string s; cin >> s;
    bool flag = 1;
    
    for (int i = 0; i < s.size() && flag; ++i)
    {
        //判断1位数时是否满足被8整除
        if (s[i] == '0' || s[i] == '8')
        {
            cout << "YES\n" << s[i] << '\n';
            flag = 0;
        }
        for (int j = i + 1; j < s.size() && flag; ++j)
        {
            //判断2位数时是否满足被8整除
            int b = (s[i] - '0') * 10 + (s[j] - '0');
            if (b % 8 == 0)
            {
                cout << "YES\n" << b << '\n';
                flag = 0;
            }
            for (int k = j + 1; k < s.size() && flag; ++k)
            {
                //判断3位数时是否满足被8整除
                int a = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
                if (a % 8 == 0)
                {
                    cout << "YES\n" << a << '\n';
                    flag = 0;
                }
            }
        }
    }
    if (flag)
        cout << "NO\n";
    return 0;
}
