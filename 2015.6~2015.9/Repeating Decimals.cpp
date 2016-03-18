#include<iostream>
#include<cctype>
#include<cstdio>
#include<map>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 1e4 + 111;
int up[MAXN], deci[MAXN]; //up:分子 deci:整除后结果

int main()
{
    int a, b, cycle, s, ed; //这里的s、ed都是要最终记录下来的，以便之后的输出
    while (~scanf("%d%d", &a, &b))
    {
        map<int, bool> mp;
        up[0] = a, deci[0] = a / b;
        for (ed = 1; ; ++ed)
        {
            up[ed] = (up[ed - 1] - b * deci[ed - 1]) * 10; //得到当前分母
            deci[ed] = up[ed] / b;
            if (mp[up[ed]])
            {
                for (s = ed - 1; s; --s)
                {
                    if (up[ed] == up[s])
                    {
                        cycle = ed - s;
                        goto label;
                    }
                }
            }
            mp[up[ed]] = 1;
        }
    label:
        printf("%d/%d = %d.", a, b, deci[0]);
        for (int i = 1; i < s; ++i) printf("%d", deci[i]);
        putchar('(');
        for (int i = s; i < ed; ++i)
        {
            if (i > 50)
            {
                printf("...");
                break;
            }
            printf("%d", deci[i]);
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", cycle);
    }
    return 0;
}
