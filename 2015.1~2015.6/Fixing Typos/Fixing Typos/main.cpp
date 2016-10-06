#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAXN = 2e5 + 111;
typedef long long ll;

char s[MAXN];
int num[MAXN];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    char f = s[0];
    int p = 0;
    num[0] = 1;
    for (int i = 1; i < len; ++i)
    {
        if (s[i] == f)
        {
            ++num[p];
        }
        else{
            f = s[i];
            p = i;
            ++num[p];
        }
    }
    int last = 1;
    for (int i = 0; i < len; ++i)
    {
        if (num[i] == 1)
        {
            printf("%c", s[i]);
            last = num[i];
        }
        else if (num[i] >= 2)
        {
            if (last != 2)
            {
                printf("%c%c", s[i], s[i]);
                last = 2;
            }
            else {
                printf("%c", s[i]);
                last = 1;
            }
        }
    }
    printf("\n");
    return 0;
}
