#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

string add(string a, string b)
{
	string res;
	int carry = 0;  //��λ 
	int len1 = a.length(), len2 = b.length(), mxl;  //mxl:����� 
	if (len1 > len2)
	{
		for (int i = len2; i < len1; ++i)
		{
			b += '0';  //�����ַ����������Ϊ�ܹ��������� 
		}
		mxl = len1;
	}
	else
	{
		for (int i = len1; i < len2; ++i)
		{
			a += '0';  //�����ַ����������Ϊ�ܹ��������� 
		}
		mxl = len2;
	}
	for (int i = 0; i < mxl; ++i)  //����res�ַ����洢�ַ����� 
		res += '0';
	for (int i = 0; i < mxl; ++i)  //��ʼ���� 
	{
		res[i] = a[i] + b[i] - '0' + carry; 
		if (res[i] > '9') //�����Ƿ�Ҫ��λ 
		{
			carry = 1;
			res[i] -= 10;
		}
		else carry = 0;
	}
	if (carry) 
	{
		res += '1';
	}
	return res;
}

int main()
{
	string a, b, c, d;
	while(cin >> a >> b >> c)
	{
		reverse(a.begin(),a.end()); //��ת 
		reverse(b.begin(),b.end());
		reverse(c.begin(),c.end());
		for (int i = 3; i <= 99; ++i)
		{
			string t = add(a, b);
			d = add(t, c);
			a = b, b = c, c = d;
		}
		reverse(d.begin(),d.end());
		cout << d << endl;
	}
	return 0;
}

