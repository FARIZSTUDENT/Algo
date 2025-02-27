#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

// Fungsi Bubble Sort untuk mengurutkan array secara ascending
void bubble_sort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(string arr[], int low, int high)
{
    string pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Fungsi Quick Sort untuk mengurutkan array secara descending
void quick_sort(string arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();

    string namamahasiswa[n];
    cout << "Masukkan nama mahasiswa:\n";
    for (int i = 0; i < n; i++)
    {
        getline(cin, namamahasiswa[i]);
    }

    // Mengurutkan secara descending menggunakan Quick Sort
    quick_sort(namamahasiswa, 0, n - 1);
    cout << "\nNama mahasiswa yang diurutkan secara descending:\n";
    for (int i = 0; i < n; i++)
    {
        cout << namamahasiswa[i] << endl;
    }

    return 0;
}