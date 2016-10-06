#include <stdio.h>
#include <iostream>
const int MAXN=100005;
char s[MAXN];
int main()
{
        int n,cnt=0;
        scanf("%d%s",&n,s);
        for(int i=0;i<n;i++)
                if(s[i]!=s[i+1])
                        cnt++;
        printf("%d\n",std::min(cnt + 2, n));
        return 0;
}
