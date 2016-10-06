#include<stdio.h>
#define kitten

int main()
{
    int f, l, t;
    scanf("%d%d%d\n", &f, &l, &t);
    char fr[20][20];
    for (int i = 0; i < f; ++i) {
        scanf("%s", fr[i]);
    }
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        int sum = 0;
        for (int j = 0; j < f; ++j) {
            if (fr[j][i] == 'Y') ++sum;
        }
        if (sum >= t) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
