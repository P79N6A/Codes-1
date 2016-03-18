#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;

int main()
{
#ifdef LOCAL
    //freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
    int n;
    int num[6];
    for (int i = 0; i < 6; ++i)
        cin >> num[i];
    int len = num[0] + num[1] + num[5];
    int sum = 0;
    for (int i = 1; i < 6; i += 2)
        sum += num[i] * num[i];
    cout << len * len - sum << '\n';
    return 0;
}
