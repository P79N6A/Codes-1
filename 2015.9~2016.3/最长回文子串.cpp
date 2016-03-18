#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

char Ma[MAXN * 2];
int Mp[MAXN * 2], ans;

void Manacher(char s[], int len)
{
    int l = 0;
    Ma[l++] = '$'; Ma[l++] = '#';
    for (int i = 0; i < len; ++i)
    {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0; // Ma[0] 和 Ma[l] 赋值后可以防止后期匹配越界

    int mx = 0, id = 0; // mx: id最长延伸到的位置 id: mx的中心位置

    for (int i = 0; i < l; ++i)
    {
        // 三种情况：1.i对称位置回文在mx范围之内
        //           2.i对称位置回文部分在mx范围之内
        //           3.i位置直接在mx范围之外，直接从i开始匹配
        Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;

        while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) ++Mp[i];
        ans = max(ans, Mp[i] - 1);
        if (i + Mp[i] > mx)
        {
            mx = i + Mp[i];
            id = i;
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    char s[MAXN];
    while (t --)
    {
        scanf("%s", &s);
        ans = 0;
        Manacher(s, strlen(s));
        printf("%d\n", ans);
    }
    return 0;
}
