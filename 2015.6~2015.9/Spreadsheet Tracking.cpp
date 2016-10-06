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
typedef vector< vector<int> > tvv;

int sheet[60][60]; //����ԭ���ı�� 
int num[15];       //�������������Ҫɾ���ĺ��� 

void init(int& r, int& c, tvv& v)   //��ÿ����Ԫ�������֣�ע�⣺�����ҵĵ�Ԫ���±��Ǵ�1��ʼ�������õ�vector�±���0��ʼ���� 
{
	int num = 0;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
		{
			++num;
			sheet[i][j] = num;
			v[i - 1].push_back(num);
		}
}

void find(int x, int y, tvv& v) //���ҵ�Ԫ�� 
{
	printf("Cell data in (%d,%d) ", x, y);
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == sheet[x][y])
			{
				printf("moved to (%d,%d)\n", i + 1, j + 1);
				return;
			}
		}
	puts("GONE");
}

void op_dr(int& n, tvv& v) //DR���� 
{
	int x;
	for (int i = 0; i < n; ++i)
	{
		x = num[i];
		v.erase(v.begin() + x - 1);
	}
}

void op_ir(int& n, tvv& v) //IR���� 
{
	int x;
	for (int i = 0; i < n; ++i)
	{
		x = num[i];
		v.insert(v.begin() + x - 1, vector<int>(v[0].size(), 0));
	}
}

void op_dc(int& n, tvv& v) //DC���� 
{
	int x;
	for (int i = 0; i < n; ++i)
	{
		x = num[i];
		for (int j = 0; j < v.size(); ++j)
		{
			v[j].erase(v[j].begin() + x - 1);
		}
	}
}

void op_ic(int& n, tvv& v) //IC���� 
{
	int x;
	for (int i = 0; i < n; ++i)
	{
		x = num[i];
		for (int j = 0; j < v.size(); ++j)
		{
			v[j].insert(v[j].begin() + x - 1, 0);
		}
	}
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int r, c, cnt = 0;
	int d, q;
	while (cin >> r >> c && (r || c))
	{
		tvv v(r);
		init(r, c, v);
		cin >> d;
		string op;
		int n;
		for (int i = 0; i < d; ++i)
		{
			cin >> op >> n;
			if (op == "EX") 
			{
				for (int i = 0; i < 3; ++i) cin >> num[i];
				swap(v[n - 1][num[0] - 1], v[num[1] - 1][num[2] - 1]);
			}
			else 
			{
				for (int i = 0; i < n; ++i) cin >> num[i];
				sort(num, num + n, cmp);   //���ض����л��к�����в�����ͬʱ���еģ����Ա���Ӵ�Ŀ�ʼ 
				if (op == "DR")	op_dr(n, v);
				if (op == "DC") op_dc(n, v);
				if (op == "IC")	op_ic(n, v);
				if (op == "IR")	op_ir(n, v);
			}
		}
		
		if (cnt > 0) putchar('\n');
		printf("Spreadsheet #%d\n", ++cnt);
		
		cin >> q;
		for (int i = 0; i < q; ++i)
		{
			int x, y;
			cin >> x >> y;
			find(x, y, v);
		}
	}
	return 0;
}

