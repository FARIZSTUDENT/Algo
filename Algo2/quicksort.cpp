#include <iostream>
using namespace std;

void quick_sort(int array[], int awal, int akhir)
{
    int low = awal, high = akhir;
    int pivot = array[(awal + akhir) / 2];

    do
    {
        while (array[low] < pivot)
        {
            low++;
        }
        while (array[high] > pivot)
        {
            high--;
        }

        if (low <= high)
        {
            swap(array[low], array[high]);
            low++;
            high--;
        }
    } while (low <= high);

    if (awal < high)
    {
        quick_sort(array, awal, high);
    }
    if (low < akhir)
    {
        quick_sort(array, low, akhir);
    }
}

int main()
{
    int values[] = {9, 13, 6, 2};
    int n = sizeof(values) / sizeof(values[0]);

    // Data yang belum di sorting
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << values[i] << " ";
    }

    // Quick sort
    quick_sort(values, 0, n - 1);

    // Data yang sudah di sorting
    cout << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << values[i] << " ";
    }

    return 0;
}