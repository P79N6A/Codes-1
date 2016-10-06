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
string s;

int parse(string ss, int step)
{
    if(ss.length() == 1)
    {
        return step;
    }
    int sum = 0;
    for(int i = 0; i < ss.length(); ++i)
    {
        sum += ss[i] - '0';
    }
    string sub;
    while(sum)
    {
        sub += sum % 10 + '0';
        sum /= 10;
    }
    reverse(sub.begin(),sub.end());
    return parse(sub, step + 1);
}

int main()
{
 	while(cin >> s)
 	{
 	    cout << parse(s, 0) << '\n';
    }
	return 0;
}

