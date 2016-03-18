#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 11;
char mp[MAXN];
char ss[MAXN];

int main() {
    int t, k, ca = 0;
    scanf("%d",&t);
    getchar();
    while (t --)
    {
        char s[MAXN];
        gets(s);
        cin >> k;
        getchar();
        int l = strlen(s);
        int len = ceil(l/(float)k);
        int cnt = 0;
        int left = k - k * len + l;
        int remain = left;
        for (int i = 0; i < k; ++i)
        {
            if (left)
            {
                for (int j = 0; j < len; ++j)
                    mp[i * k + j] = s[cnt++];
                --left;
            }
            else{
                for (int j = 0; j < len - 1; ++j)
                    mp[i * k + j] = s[cnt++];
            }
        }
        cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            if (i != len - 1)
            {
                for (int j = 0; j < k; ++j)
                    ss[cnt++] = mp[j * k + i];
            }
            else{
                for (int j = 0; j < remain; ++j)
                    ss[cnt++] = mp[j * k + i];
            }
        }
        printf("Case #%d:\n",++ca);
        for(int i = 0; i < cnt; ++i)
            printf("%c",ss[i]);
        printf("\n");
    }
    return 0;
}