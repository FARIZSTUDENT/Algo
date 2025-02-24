#include <iostream>
using namespace std;

// Tanpa Sentinel
// int main (){
//     int arr[5] = {1,5,3,8,6};
//     int x;

//     cout << "Masukkan Angka Yang Ingin Dicari : ";
//     cin >> x;

//     int i = 0;
//     bool found = false;

//     while (!found && i < 5)
//     {
//         if (arr[i] == x)
//         {
//             found = true;
//         } else {
//             i++;
//         }
        
//         if (found)
//         {
//             cout << "Angka yang dicari ditemukan di array ke- " << i << endl;
//         } else {
//             cout << "Angka yang dicari tidak ada";
//         }
        
//     }
    
// }

// Dengan Sentinel

int main(){
    int arr[6] = {1,5,3,8,6};
    int x = 3;
    int i = 0;

    cout << "Masukkan angka yang akan dicari : ";
    cin >> x;

    arr[5] = x; // Sentinel

    while (arr[i] != x)
    {
       i++;
    }

    if (i<5)
    {
        cout << "Data ditemukan di array index ke- " << i << endl;

    } else {
        cout << "Data tidak ditemukan";
    }
    
    
}