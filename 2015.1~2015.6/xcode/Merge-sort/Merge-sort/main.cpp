#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

void merge(int *a, int l, int mid, int r)
{
    int len1 = mid - l + 1;
    int len2 = r - mid;
    int *b = new int(len1 + 1);
    int *c = new int(len2 + 1);
    for (int i = 0; i < len1; ++i)
        b[i] = a[l + i];
    for (int i = 0; i < len2; ++i)
        c[i] = a[mid + i];
    
    b[len1] = 0x3f3f3f3f;
    c[len2] = 0x3f3f3f3f;
    len1 = 0, len2 = 0;
    
    for (int i = l; i <= r; ++i)
    {
        if (b[len1] <= c[len2])
        {
            a[i] = b[len1];
            ++len1;
        }
        else
        {
            a[i] = c[len2];
            ++len2;
        }
    }
    delete []b;
    delete []c;
}

void merge_sort(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    int a[10] = {3, 12, 5, 32, 54, 1, 9, 93, 0, 1};
    merge_sort(a, 0, 9);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << ' ';
    return 0;
}