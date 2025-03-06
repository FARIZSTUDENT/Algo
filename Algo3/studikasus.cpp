#include <iostream>

using namespace std;

typedef struct
{
    char nama[50];
    char nomor[50];
} Pelanggan;

Pelanggan plgn[100];

int main()
{
    // Membuka file
    FILE *kontak;
    kontak = fopen("kontak.txt", "a");
    if (kontak == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        return 1;
    }

    // Menulis ke file eksternal
    int x;
    cout << "Masukkan jumlah pelanggan: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        cout << endl;
        cout << "Masukkan Pelanggan ke - " << i + 1 << endl;
        cout << "Masukkan Nama Pelanggan :";
        cin >> plgn[i].nama;
        cout << "Masukkan Nomor Pelanggan :";
        cin >> plgn[i].nomor;
        fprintf(kontak, "%s %d\n", plgn[i].nama, plgn[i].nomor);
    }
    fclose(kontak);

    // Membaca file eksternal
    kontak = fopen("kontak.txt", "r");
    Pelanggan plgn_baca[100];
    int baris = 0;
    while (fscanf(kontak, "%s %d\n", &plgn_baca[baris].nama, &plgn_baca[baris].nomor) != EOF)
    {
        baris++;
    }

    for (int i = 0; i < baris; i++)
    {
        cout << endl;
        cout << "Pelanggan ke-" << i + 1 << endl;
        cout << "Nama Pelanggan : " << plgn_baca[i].nama << endl;
        cout << "Nomor Pelanggan : " << plgn_baca[i].nomor << endl;
    }
    fclose(kontak);
}
