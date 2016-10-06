#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;

const int MAXN = 1e6 + 111;

map<string, int> mp;

inline string add(string a, string b)
{
	string res;
	int carry = 0;  //进位 
	int len1 = a.length(), len2 = b.length(), mxl;  //mxl:最长长度 
	if (len1 > len2)
	{
		for (int i = len2; i < len1; ++i)
		{
			b += '0';  //补齐字符串，让这个为能够参与运算 
		}
		mxl = len1;
	}
	else
	{
		for (int i = len1; i < len2; ++i)
		{
			a += '0';  //补齐字符串，让这个为能够参与运算 
		}
		mxl = len2;
	}
	for (int i = 0; i < mxl; ++i)  //构造res字符串存储字符串和 
		res += '0';
	for (int i = 0; i < mxl; ++i)  //开始运算 
	{
		res[i] = a[i] + b[i] - '0' + carry; 
		if (res[i] > '9') //考虑是否要进位 
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
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	string a = "1", b = "1";
	mp[a] = 0; 
	for (int i = 2; i < 51; ++i)
	{
		string t = a; a = b; b = add(t, b);
		cout <<  i << ':' << ' ' << b << endl;
		mp[b] = i;
	}
	
	int t; cin >> t;
	string s;
	for (int i = 1; i <= t; ++i)
	{
		cin >> s;
		reverse(s.begin(), s.end());
		printf("Case #%d: ", i);
		int id = mp[s];
		if (id < 100000)
			printf("%d\n", id);
		else 
			printf("-1\n");
	}
	return 0;
}

