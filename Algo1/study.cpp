#include <iostream>
using namespace std;

struct buku
{
    string namabuku;
    int hargabuku;
};

buku dataBuku[5] = {
    {"Attack On Titan", 55000},
    {"Blue Box", 35000},
    {"Jujutsu Kaisen", 40000},
    {"Naruto", 45000},
    {"One Piece", 50000}
};

int main (){

    int cari, tengah;
    bool found;

    cout << "Masukkan Harga Buku yang akan dicari : ";
    cin >> cari;

    found = false;
    int awal = 0;
    int akhir = 4; // Batas akhir diubah menjadi 4 karena indeks terakhir adalah 4

    while (!found && awal <= akhir)
    {
        tengah = (akhir + awal) / 2;

        if (dataBuku[tengah].hargabuku == cari)
        {
            found = true;
            cout << "Buku ditemukan : " << dataBuku[tengah].namabuku << endl;
            cout << "Dengan Harga : " << dataBuku[tengah].hargabuku << endl;
        } 
        else 
        {
            if (cari < dataBuku[tengah].hargabuku)
            {
                akhir = tengah - 1; // Pencarian di sebelah kiri
            } 
            else
            {
                awal = tengah + 1; // Pencarian di sebelah kanan
            }
        }
    }

    if (!found) {
        cout << "Buku dengan harga " << cari << " tidak ditemukan." << endl;
    }

    return 0;
}