#include <iostream>
#include <string>

using namespace std;

struct Node {
      string judul;
      int durasi;
      Node *kanan;
      Node *kiri;
};

void tambahlagu (Node *&head, string judul, int durasi) {
      Node *baru = new Node;
      baru->judul = judul;
      baru->durasi = durasi;
      baru->kanan = nullptr;
      baru->kiri = nullptr;

      if (head == nullptr) {
            head = baru;
      } else {
            Node *temp = head;
            while (temp->kanan != nullptr) {
                  temp = temp->kanan;
            }
            temp->kanan = baru;
      }
}

void tampilkanLagu (Node *head) {
      if (!head) {
            cout << "Tidak ada lagu dalam daftar." << endl;
            return;
      } else {
            cout << "Daftar lagu:" << endl;
            Node *temp = head;
            while (temp != nullptr) {
                  cout << "Judul: " << temp->judul << ", Durasi: " << temp->durasi << " detik" << endl;
                  temp = temp->kanan;
            }
      }
}

void hapusLagu (Node *&head, string judul) {
      if (head == nullptr) {
            cout << "Tidak ada lagu dalam daftar." << endl;
            return;
      }

      Node *temp = head;
      Node *prev = nullptr;

      while (temp != nullptr && temp->judul != judul) {
            prev = temp;
            temp = temp->kanan;
      }

      if (temp == nullptr) {
            cout << "Lagu dengan judul '" << judul << "' tidak ditemukan." << endl;
            return;
      }

      if (prev == nullptr) {
            head = temp->kanan;
      } else {
            prev->kanan = temp->kanan;
      }
      delete temp;

      cout << "Lagu dengan judul '" << judul << "' telah dihapus." << endl;
}

int main (){
      Node *head = nullptr;
      int pilihan;
      string judul;
      int durasi;

      do {
            cout << "Menu:" << endl;
            cout << "1. Tambah lagu" << endl;
            cout << "2. Tampilkan lagu" << endl;
            cout << "3. Hapus lagu" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilih opsi: ";
            cin >> pilihan;

            switch (pilihan) {
                  case 1:
                        cout << "Masukkan judul lagu: ";
                        cin.ignore();
                        getline(cin, judul);
                        cout << "Masukkan durasi lagu (detik): ";
                        cin >> durasi;
                        tambahlagu(head, judul, durasi);
                        break;
                  case 2:
                        tampilkanLagu(head);
                        break;
                  case 3:
                        cout << "Masukkan judul lagu yang ingin dihapus: ";
                        cin.ignore();
                        getline(cin, judul);
                        hapusLagu(head, judul);
                        break;
                  case 4:
                        cout << "Keluar dari program." << endl;
                        break;
                  default:
                        cout << "Pilihan tidak valid." << endl;
            }
      } while (pilihan != 4);

      return 0;
};