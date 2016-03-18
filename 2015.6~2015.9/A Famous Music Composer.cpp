#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
map<string, bool> distinct;
map<string, string> MP;

void init()
{
    MP["A"] = "A"; MP["A#"] = "Bb"; MP["Bb"] = "A#"; MP["B"] = "B";
    MP["C"] = "C"; MP["C#"] = "Db"; MP["Db"] = "C#"; MP["D"] = "D";
    MP["D#"] = "Eb"; MP["Eb"] = "D#"; MP["E"] = "E"; MP["F"] = "F";
    MP["F#"] = "Gb"; MP["Gb"] = "F#"; MP["G"] = "G"; MP["G#"] = "Ab";
    MP["Ab"] = "G#";
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    string a, b;
    int kase = 0;
    while (cin >> a >> b)
    {
        cout << "Case " << ++kase << ": ";
        if (MP[a] != a)
        {
            cout << MP[a] << ' ' << b << '\n';
        }
        else cout << "UNIQUE\n";
    }
    return 0;
}
