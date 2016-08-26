#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char ch[110000];
int n;
int check(){
	int now=0;
	for (int i=1;i<=n;i++) if (ch[i]=='(') now++; else if (now==0) return 0; else now--;
	return (now==0);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data1.out","w",stdout);
	int t; scanf("%d",&t);
	for (;t;t--){
		scanf("%d",&n);
		scanf("%s",ch+1);
		int l=1,r=n;
		for (int i=1;i<=n;i++) if (ch[i]=='(') l=i;
		for (int i=n;i;i--) if (ch[i]==')') r=i;
		swap(ch[l],ch[r]);
		if (check()) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}

