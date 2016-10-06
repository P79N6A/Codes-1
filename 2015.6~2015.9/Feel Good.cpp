#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 111;
typedef long long ll;
int v[MAXN];
ll sum[MAXN], l[MAXN], r[MAXN];

int main()
{
	int n;
	int cnt = 0;
	while( cin >> n )
	{
	    ll ansl = 0, ansr = 0, ansv = -1;
	    memset(sum , 0, sizeof sum);
	    for(int i = 0; i < n; ++i) cin >> v[i], l[i] = r[i] = i;
	    for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + v[i - 1]; //��¼ǰn���
	    for(int i = 0; i < n; ++i) //������ֵ
	    {
	        while(v[i] != 0 && l[i] > 0 && v[l[i] - 1] >= v[i])
	           l[i] = l[l[i] - 1];
        }
	    for(int i = n - 1; i >= 0; --i)//������ֵ
	    {
	        while(v[i]!= 0 && r[i] < n - 1 && v[r[i] + 1] >= v[i]) //С��Ϊ0���������ʱ�����и�������
                r[i] = r[r[i] + 1];
        }
        for(int i = 0; i < n; ++i)
        {
            ll temp = (sum[r[i] + 1] - sum[l[i]]) * v[i];
	        if( temp > ansv )
	        {
	            ansv = temp;
	            ansl = l[i] + 1;
	            ansr = r[i] + 1;
            }
            else if(temp == ansv && ansr - ansl > r[i] - l[i]) //ע����Ŀ����
            {
                ansl = l[i] + 1;
                ansr = r[i] + 1;
            }
        }
        if(cnt++) cout << '\n';
        cout << ansv << '\n' << ansl << ' ' << ansr << '\n';
    }
	return 0;
}
