#include<iostream>
using namespace std;

const int INF = 0x7f7f7f7f;

void merge(int *arr, int l, int mid, int r)
{
    int len1 = mid - l + 1;
    int len2 = r - mid;
    int *L = new int[len1 + 1];
    int *R = new int[len2 + 1];
    for (int i = 0; i < len1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < len2; ++i) R[i] = arr[mid + 1 + i];
    L[len1] = R[len2] = INF;
    int i = 0, j = 0;
    for (int k = l; k <= r; ++k)
    {
        if (L[i] > R[j])
        {
            arr[k] = R[j++];
        }
        else arr[k] = L[i++];
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) >> 1;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int original[] = {2, 3, 4, 1, 19, 1, 234, 45, 23, 45};
    cout << "Original array:\n";
    for (int i = 0; i < 10; ++i)
    {
        cout << original[i] << ' ';
    }
    cout << "\n\n";

    cout << "New array:\n";
    mergeSort(original, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        cout << original[i] << ' ';
    }
    cout << "\n\n";
    return 0;
}
