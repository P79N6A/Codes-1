#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 111;
char s[MAXN], t[MAXN];

int main()
{
	int k; scanf("%d", &k); 
	for( int kase = 1; kase <= k; ++kase )
	{
	    printf("Case %d: ", kase);
	    scanf("%s%s", s, t);
	    int s1 = 0, t1 = 0, len = strlen(s), diff0 = 0, diff1 = 0, que = 0;
	    for(int i = 0; i < len; ++i)  //ͳ��s����t����1��0���ֵĴ����� 
	    {
	        if(s[i] == '1') ++s1;
            if(t[i] == '1') ++t1;
            if(s[i] == '?') ++que;
            if(s[i] != t[i] && s[i] == '0') ++diff0;
            if(s[i] != t[i] && s[i] == '1') ++diff1;
        }
        if(s1 > t1)
            printf("-1\n");
        else //�������ģ�������ȫʣ1����ȫʣ0���ն���Ҫ����ÿ�����β����� ����que-(diff0 - diff1)����ʣ����ʺ�Ҫ���еĲ��� 
        {
            if(diff0 < diff1) swap(diff0, diff1);
            printf("%d\n", diff1 + (diff0 - diff1) * 2 + que - (diff0 - diff1));
        }
    }
	return 0;
}

