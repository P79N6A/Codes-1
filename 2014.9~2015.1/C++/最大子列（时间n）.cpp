//Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
#include<iostream>

using namespace std;

int main(void)
{
	int n,num[100000];
	while(cin>>n)
	{
		int max=0,sum=0;
		for(int i=0;i<n;i++)
			cin>>num[i];
		for(int i=0;i<n;i++)
		{
			//cout<<"sun[i]="<<num[i]<<endl;
			sum+=num[i];
			if(sum>max)
				max=sum;
			else if(sum<0)
				sum=0;
			//cout<<"sum="<<sum<<"\nmax="<<max<<endl;
		}
		cout<<max<<endl;
	}
	return 0;
}
