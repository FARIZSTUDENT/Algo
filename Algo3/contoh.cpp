#include <iostream>

using namespace std;

typedef struct
{
    char nama[50];
    int umur;
    float ipk;
} Mahasiswa;

Mahasiswa mhs[100];

int main()
{
    FILE *file;

    // Membuka file
    file = fopen("mahasiswa.txt", "a");
    if (file == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        return 1;
    }

    // Menulis ke file eksternal
    int x;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        cout << endl;
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan Nama Mahasiswa :";
        cin >> mhs[i].nama;
        cout << "Masukkan Umur Mahasiswa :";
        cin >> mhs[i].umur;
        cout << "Masukkan IPK Mahasiswa :";
        cin >> mhs[i].ipk;
        fprintf(file, "Nama : %s\nUmur : %d\nIPK : %f\n", mhs[i].nama, mhs[i].umur, mhs[i].ipk);
    }

    fclose(file);

    // Membaca file eksternal
    file = fopen("mahasiswa.txt", "r");
    Mahasiswa mhs_baca[100];
    int baris = 0;
    while (fscanf(file, "Nama : %s\nUmur : %d\nIPK : %f\n", &mhs_baca[baris].nama, &mhs_baca[baris].umur, &mhs_baca[baris].ipk) != EOF)
    {
        baris++;
    }

    for (int i = 0; i < baris; i++)
    {
        cout << endl;
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama Mahasiswa : " << mhs_baca[i].nama << endl;
        cout << "Umur Mahasiswa : " << mhs_baca[i].umur << endl;
        cout << "IPK Mahasiswa : " << mhs_baca[i].ipk << endl;
    }
    fclose(file);
}
