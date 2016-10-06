#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int l = 1, r = 1000000, ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        printf("%d\n", mid);
        fflush(stdout);

        char response[3];
        scanf("%s", response);
        if (strcmp(response, "<") == 0) {
            r = mid - 1;
        }
        else {
            ans = mid;
            l = mid + 1;
        }
    }

    printf("! %d\n", ans);
    fflush(stdout);
}
