#include <iostream>
using namespace  std;

int main (){
    int arr[13] ={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int awal, cari, tengah, akhir;

    bool found;

    cout << "Cari Nilai : ";
    cin >> cari;

    found = false;
    awal = 0;
    akhir = 13;

    while (!found && awal <= akhir)
    {
        tengah = (awal+akhir)/2;

        if (cari == arr[tengah])
        {
            found = true;
        } else {
            if (cari < arr[tengah])
            {
                akhir=tengah-1; // awal tetap
            } else {
                awal= tengah + 1; // akhir tetap
            }
        }
        
    }

    if (found)
    {
        cout << "Data ditemukan di array index ke- " << tengah << endl;

    } else {
        cout << "Data angka ke- " << cari << " tidak ada" << endl;
    }
    
    
}

