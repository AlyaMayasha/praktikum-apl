#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct DetailProduk {
    string warna;
    int stok;
};

struct Produk {
    string nama;
    int harga;
    DetailProduk detail;
};

const int max_produk = 100;

void tampilkanRekursif(Produk data[], int indeks, int jumlah) {
    if (indeks >= jumlah) return;
    cout << "| " << setw(2) << indeks + 1
         << " | " << left << setw(18) << data[indeks].nama
         << " | " << right << setw(10) << data[indeks].harga
         << " | " << setw(4) << data[indeks].detail.stok
         << " | " << setw(10) << left << data[indeks].detail.warna << " |\n";
    tampilkanRekursif(data, indeks + 1, jumlah);
}

void tampilkanProduk(Produk data[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada produk yang tersedia.\n";
        return;
    }
    cout << "\n+----+--------------------+------------+------+------------+\n";
    cout << "| No | Nama Produk        | Harga      | Stok | Warna      |\n";
    cout << "+----+--------------------+------------+------+------------+\n";
    tampilkanRekursif(data, 0, jumlah);
    cout << "+----+--------------------+------------+------+------------+\n";
}

void tambahProduk(Produk data[], int &jumlah) {
    if (jumlah >= max_produk) {
        cout << "Data penuh! Tidak bisa menambah produk lagi.\n";
        return;
    }

    cin.ignore();
    cout << "Masukkan nama produk: ";
    getline(cin, data[jumlah].nama);
    cout << "Masukkan harga produk: ";
    cin >> data[jumlah].harga;
    cin.ignore();
    cout << "Masukkan warna produk: ";
    getline(cin, data[jumlah].detail.warna);
    cout << "Masukkan stok produk: ";
    cin >> data[jumlah].detail.stok;

    jumlah++;
    cout << "Produk berhasil ditambahkan!\n";
    tampilkanProduk(data, jumlah);
}

void ubahProduk(Produk data[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada produk untuk diubah.\n";
        return;
    }

    tampilkanProduk(data, jumlah);
    int index;
    cout << "Masukkan nomor produk yang ingin diubah: ";
    cin >> index;

    if (index > 0 && index <= jumlah) {
        index--;
        cout << "Masukkan harga baru: ";
        cin >> data[index].harga;
        cout << "Masukkan stok baru: ";
        cin >> data[index].detail.stok;
        cout << "Produk berhasil diperbarui!\n";
    } else {
        cout << "Nomor produk tidak valid!\n";
    }
}

void hapusProduk(Produk data[], int &jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada produk yang bisa dihapus.\n";
        return;
    }

    tampilkanProduk(data, jumlah);
    int index;
    cout << "Masukkan nomor produk yang ingin dihapus: ";
    cin >> index;

    if (index > 0 && index <= jumlah) {
        index--;
        for (int i = index; i < jumlah - 1; i++) {
            data[i] = data[i + 1];
        }
        jumlah--;
        cout << "Produk berhasil dihapus!\n";
    } else {
        cout << "Nomor produk tidak valid!\n";
    }
}

int main() {
    string username = "Alya";
    string nim = "054";

    Produk produk[max_produk] = {
        {"Backpack Rajut", 300000, {"Pink", 20}},
        {"Tote Bag Rajut", 125000, {"Baby Blue", 45}},
        {"Sling Bag Rajut", 95000, {"Hitam", 30}},
        {"Hand Bag Rajut", 80000, {"Cream", 15}},
        {"Pouch Rajut", 65000, {"Maroon", 50}}
    };
    int jumlahProduk = 5;

    string inputNama, inputNim;
    int percobaan = 3;
    while (percobaan > 0) {
        cout << "Masukkan Nama: ";
        cin >> inputNama;
        cout << "Masukkan NIM: ";
        cin >> inputNim;

        if (inputNama == username && inputNim == nim) break;
        percobaan--;
        cout << "Login gagal! Sisa percobaan: " << percobaan << endl;
    }

    if (percobaan == 0) {
        cout << "Mohon maaf, percobaan login gagal! Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== Manajemen Produk Tas Rajut ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Ubah Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahProduk(produk, jumlahProduk);
                break;
            case 2:
                tampilkanProduk(produk, jumlahProduk);
                break;
            case 3:
                ubahProduk(produk, jumlahProduk);
                break;
            case 4:
                hapusProduk(produk, jumlahProduk);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini. Have a great day >_<!\n";
                break;
            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
