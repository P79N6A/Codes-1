#include <iostream>
#include <algorithm>
using namespace std;

struct Day{
    int a, b;
    bool operator < (const Day& t)const
    {
        if (a != t.a)
            return a < t.a;
        else return b < t.b;
    }
}day[5011];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> day[i].a >> day[i].b;
    sort(day, day + n);
    int mosquick = day[0].b;
    for (int i = 1; i < n; ++i)
    {
        if (day[i].b >= mosquick)
            mosquick = day[i].b;
        else mosquick = day[i].a;
    }
    cout << mosquick << '\n';
    return 0;
}