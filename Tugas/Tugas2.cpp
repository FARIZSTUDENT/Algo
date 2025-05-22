#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk pasien
struct Pasien {
    int nomor;
    string nama;
    string keluhan;
    Pasien* prev;
    Pasien* next;
};

// Pointer untuk head dan tail
Pasien* head = nullptr;
Pasien* tail = nullptr;

// Fungsi untuk menambahkan pasien secara terurut berdasarkan nomor antrian
void tambahPasien(int nomor, string nama, string keluhan) {
    Pasien* baru = new Pasien{nomor, nama, keluhan, nullptr, nullptr};

    // Jika linked list kosong
    if (!head) {
        head = tail = baru;
        cout << "✅ Pasien ditambahkan sebagai data pertama.\n";
        return;
    }

    Pasien* current = head;

    // Sisipkan di posisi yang tepat berdasarkan nomor antrian
    while (current && current->nomor < nomor) {
        current = current->next;
    }

    if (current == head) { // Sisip di depan
        baru->next = head;
        head->prev = baru;
        head = baru;
    } else if (!current) { // Sisip di belakang
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    } else { // Sisip di tengah
        baru->next = current;
        baru->prev = current->prev;
        current->prev->next = baru;
        current->prev = baru;
    }

    cout << "✅ Pasien berhasil ditambahkan.\n";
}

// Menampilkan antrian dari depan (nomor kecil ke besar)
void tampilDariDepan() {
    if (!head) {
        cout << "⛔ Antrian kosong.\n";
        return;
    }

    Pasien* current = head;
    cout << "\n📋 Antrian dari Awal:\n";
    while (current) {
        cout << "Nomor: " << current->nomor
             << " | Nama: " << current->nama
             << " | Keluhan: " << current->keluhan << "\n";
        current = current->next;
    }
}

// Menampilkan antrian dari belakang (nomor besar ke kecil)
void tampilDariBelakang() {
    if (!tail) {
        cout << "⛔ Antrian kosong.\n";
        return;
    }

    Pasien* current = tail;
    cout << "\n📋 Antrian dari Akhir:\n";
    while (current) {
        cout << "Nomor: " << current->nomor
             << " | Nama: " << current->nama
             << " | Keluhan: " << current->keluhan << "\n";
        current = current->prev;
    }
}

// Cari pasien berdasarkan nomor antrian
void cariPasien(int nomor) {
    Pasien* current = head;
    while (current) {
        if (current->nomor == nomor) {
            cout << "\n🔍 Pasien Ditemukan:\n";
            cout << "Nomor: " << current->nomor
                 << " | Nama: " << current->nama
                 << " | Keluhan: " << current->keluhan << "\n";
            return;
        }
        current = current->next;
    }
    cout << "❌ Pasien dengan nomor antrian tersebut tidak ditemukan.\n";
}

// Hapus pasien berdasarkan nomor antrian
void hapusPasien(int nomor) {
    if (!head) {
        cout << "⛔ Antrian kosong.\n";
        return;
    }

    Pasien* current = head;
    while (current && current->nomor != nomor) {
        current = current->next;
    }

    if (!current) {
        cout << "❌ Pasien tidak ditemukan.\n";
        return;
    }

    if (current == head && current == tail) {
        head = tail = nullptr;
    } else if (current == head) {
        head = head->next;
        head->prev = nullptr;
    } else if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    cout << "✅ Pasien berhasil dihapus dari antrian.\n";
}

// Menu utama
int main() {
    int pilihan;
    do {
        cout << "\n=== MENU KLINIK SEHAT SELALU ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Tampilkan Antrian dari Awal\n";
        cout << "3. Tampilkan Antrian dari Akhir\n";
        cout << "4. Cari Pasien Berdasarkan Nomor Antrian\n";
        cout << "5. Hapus Pasien Berdasarkan Nomor Antrian\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int nomor;
                string nama, keluhan;
                cout << "Nomor Antrian: ";
                cin >> nomor;
                cin.ignore();
                cout << "Nama Pasien: ";
                getline(cin, nama);
                cout << "Keluhan: ";
                getline(cin, keluhan);
                tambahPasien(nomor, nama, keluhan);
                break;
            }
            case 2:
                tampilDariDepan();
                break;
            case 3:
                tampilDariBelakang();
                break;
            case 4: {
                int cari;
                cout << "Masukkan nomor antrian: ";
                cin >> cari;
                cariPasien(cari);
                break;
            }
            case 5: {
                int hapus;
                cout << "Masukkan nomor antrian yang akan dihapus: ";
                cin >> hapus;
                hapusPasien(hapus);
                break;
            }
            case 6:
                cout << "👋 Terima kasih telah menggunakan program antrian.\n";
                break;
            default:
                cout << "❗ Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}