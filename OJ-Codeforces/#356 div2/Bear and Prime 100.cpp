#include <cstdio>
#include <cstring>
using namespace std;

int even[30] = {4,6,10,14,22,26,34,38,46,58,62,74,82,86,94}; // 15
int odd[30] = {3,5,7,11,13,17,19,23,29,31,37,9,25,49}; // 14

int main() {
    int ask = 2, cnt = 0, pos = -1;
    int first = 1, p = 0;
    while (1) {
        printf("%d\n", ask);
        fflush(stdout);

        char response[4];
        scanf("%s", response);
        if (strcmp(response, "no") == 1) {
            ++cnt;
            if (cnt > 1) break;
        }
        else {
            if (first) p = 1;
        }
        first = 0;
        if (p == 1) {
            if (++pos >= 14) break;
            ask = odd[pos];
        }
        else {
            if (++pos >= 15) break;
            ask = even[pos];
        }
    }

    if (cnt > 1) printf("composite\n");
    else printf("prime\n");
    fflush(stdout);
}
