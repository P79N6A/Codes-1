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
    Ma[l] = 0; // Ma[0] �� Ma[l] ��ֵ����Է�ֹ����ƥ��Խ��

    int mx = 0, id = 0; // mx: id����쵽��λ�� id: mx������λ��

    for (int i = 0; i < l; ++i)
    {
        // ���������1.i�Գ�λ�û�����mx��Χ֮��
        //           2.i�Գ�λ�û��Ĳ�����mx��Χ֮��
        //           3.iλ��ֱ����mx��Χ֮�⣬ֱ�Ӵ�i��ʼƥ��
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
