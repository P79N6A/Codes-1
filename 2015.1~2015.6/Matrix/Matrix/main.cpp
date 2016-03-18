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
using namespace std;
typedef long long ll;

ll a;
ll sum[4010];  //记录前n项和
ll total[40100]; //total用来存储，和出现的次数，降低n大小(因为s最大4000而里面的数字最大为9，所以4W够矣
string s;

int main() {
    cin >> a >> s;
    sum[0] = 0;
    for (int i = 1; i <= s.size(); ++i) //构造前n项和
        sum[i] += s[i - 1] - '0' + sum[i - 1];
    
    for (int i = 0; i <= s.size(); ++i)
        for (int j = i + 1; j <= s.size(); ++j)
            ++total[sum[j] - sum[i]]; //枚举所有的组合，将结果存到total中
    
    ll ans = 0;
    if(a == 0) //a为0的时候特判，因为后方 a % i 无法判断0.
        for(int i = 0; i < 40000; i++)
            ans += total[0] * total[i];
    for (int i = 1; i <= 40000; ++i)
        if (a % i == 0)
        {
            if (a / i <= 40000) //数字最大不会超过4W
                ans += total[a / i] * total[i];
        }
    cout << ans << '\n';
    return 0;
}
