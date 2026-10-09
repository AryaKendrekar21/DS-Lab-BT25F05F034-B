#include <iostream>
using namespace std;

int a[100];

void merge(int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int b[100];

    while (i <= q && j <= r)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= q)
        b[k++] = a[i++];

    while (j <= r)
        b[k++] = a[j++];

    for (i = p; i <= r; i++)
        a[i] = b[i];
}

void mergeSort(int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        mergeSort(p, q);
        mergeSort(q + 1, r);
        merge(p, q, r);
    }
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}