#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string path = "/", s, temp, op;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> op;
        if (op == "cd")
        {
            cin >> s;
            s += '/';
            for (int i = 0; i < s.size(); ++i)
            {
                temp += s[i];
                if (s[i] == '/')
                {
                    if (temp == "/")
                        path = temp;
                    else if (temp == "../")
                    {
                        int j;
                        for (j = path.size() - 1; path[j - 1] != '/'; --j);
                        path.resize(j);
                    }
                    else path += temp;
                    temp = "";
                }
            }
        }
        else
            cout << path << '\n';
    }
    return 0;
}