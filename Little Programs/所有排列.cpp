#include<iostream>
#include<cstdio>
#include<cstdlib>
#define LOCAL
using namespace std;
void print_permutation(int n,int *a,int cur)
{
	if(cur==n)
	{
		cout<<'(';
		for(int i=0;i<n-1;i++)
			cout<<a[i]<<',';
		cout<<a[n-1]<<')'<<endl;
	}
	else for (int i = 1; i <=n; ++i){
		int ok=1;
		for(int j=0;j<cur;j++)
			if(a[j]==i)
				ok=0;
		if(ok){
			a[cur]=i;
			print_permutation(n,a,cur+1);
		}
	}
}
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	int a[1000];
	while(cin>>n)
	print_permutation(n,a,0);
	return 0;
}