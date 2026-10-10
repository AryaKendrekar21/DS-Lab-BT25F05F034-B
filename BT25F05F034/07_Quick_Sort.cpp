#include <iostream>
using namespace std;

int a[100];

int partition(int p, int r)
{
    int pivot = a[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int p, int r)
{
    if (p < r)
    {
        int q = partition(p, r);

        quickSort(p, q - 1);
        quickSort(q + 1, r);
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

    quickSort(0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}