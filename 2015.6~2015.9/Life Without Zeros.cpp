#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;
int a, b, c;

int parse(int num)
{
    int ret = 0;
    int p = 1;
    while(num)
    {
        if(num%10 != 0)
        {
            ret += num%10 * p;
            p *= 10;
        }
        num /= 10;
    }
    return ret;
}

int main()
{
 	cin >> a >> b;
 	c = a + b;
 	a = parse(a), b = parse(b), c = parse(c);
 	cout << (a + b == c ? "YES": "NO") << '\n';
	return 0;
}

