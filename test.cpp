#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int ls[MAXN];
int nxt[MAXN];
string x;

void kmp_pre()
{
    int i,j;
    int m = x.length();
    j=nxt[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j && x[i]!=x[j])j=nxt[j];
        nxt[++i]=++j;
    }
}

int main()
{
    while (cin >> x) {
        ls[0] = -1;
        int l = 0;
        for (int i = 1; i < x.length(); ++i) {
            ls[i] = l;
            if (x[i] == x[l]) ++l;
            else l = 0;
        }
        for (int i = 0; i < x.length(); ++i) {
            printf("%d ", ls[i]);
        }
        putchar('\n');
        kmp_pre();
        for (int i = 0; i < x.length(); ++i) {
            printf("%d ", nxt[i]);
        }
        putchar('\n');
    }
    return 0;
}
