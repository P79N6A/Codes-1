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
const int MAXN = 111;
int cnt = 1, n;
struct P{
    string name;
    int score;
    bool operator <(const P& t) const
    {
        return (score == t.score? name < t.name : score > t.score);
    }
}p[MAXN];

map<string, int> id;

int getid(string name)
{
    //cout << name << "==========" << endl;
    int now = id[name];
    if(now) return now;
    p[cnt].name = name;
    return id[name] = cnt++;
}

int main()
{
    string name;
 	cin >> name >> n;
 	getchar();
    string a, b, c, d, e;
    for(int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c >> d;
        int id1, id2;
        if( b == "likes" )
        {
            c.resize(c.length() - 2);
            if( c == name ) 
            {
                id1 = getid(a);
                p[id1].score += 5;
            }
            else if( a == name ) 
            {
                id2 = getid(c);
                p[id2].score += 5;
            }
            else getid(a), getid(c);
        }
        else
        {
            d.resize(d.length() - 2);
            cin >> e;
            if(e == "wall")
            {
                if( d == name ) 
                {
                    id1 = getid(a);
                    p[id1].score += 15;
                }
                else if( a == name ) 
                {
                    id2 = getid(d);
                    p[id2].score += 15;
                }
                else getid(d), getid(a);
            }
            else
            {
                if( d == name ) 
                {
                    id1 = getid(a);
                    p[id1].score += 10;
                }
                else if( a == name ) 
                {
                    id2 = getid(d);
                    p[id2].score += 10;
                }
                else getid(d), getid(a);
            }
        }
    }
    sort(p + 1, p + cnt);
    //cout << cnt << endl;
    for(int i = 1; i < cnt; ++i)
        cout << p[i].name << '\n';
	return 0;
}

