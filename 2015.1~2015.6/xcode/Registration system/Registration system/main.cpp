#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    getchar();
    map<string, int> mp;
    while (n --)
    {
        char name[35];
        gets(name);
        ++mp[name];
        if (mp[name] >= 2)
        {
            printf("%s%d\n",name, mp[name] - 1);
            sprintf(name, "%s%d", name, mp[name] - 1);
            ++mp[name];
        }
        else printf("OK\n");
    }
    return 0;
}
