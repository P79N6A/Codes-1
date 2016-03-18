#include<iostream>
#include<iomanip>

using namespace std;

int main(void)
{
	int **m;
	int a,b;
	cout<<"请输入行数和列数"<<endl;
	while(cin>>a>>b)
	{
		m=new int *[a];
		for(int i=0;i<a;i++)
			m[i]=new int[b];
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				m[i][j]=(i+1)*(j+1);
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
				cout<<setw(4)<<setiosflags(ios::left)<<m[i][j];
			cout<<endl;
		}
		for(int i=0;i<a;i++)
			delete []m[i];
		delete []m;
	}
	return 0;
}
