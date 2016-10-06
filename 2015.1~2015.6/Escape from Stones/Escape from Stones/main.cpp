#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 1e6 + 11;

char s[MAXN];

int main()
{
     scanf("%s", s+1);
     int len = strlen(s+1);
     int a[len];
     int left = 1, right = len;
     for (int i = 1; i <= len; ++i)
     {
         if (s[i] == 'l')
             a[right--] = i;
         else a[left++] = i;
     }
     for (int i = 1; i <= len; ++i)
         printf("%d\n", a[i]);
 
     return 0;
}