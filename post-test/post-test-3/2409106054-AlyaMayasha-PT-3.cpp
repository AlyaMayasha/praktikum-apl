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

int main() {
    string username = "Alya";
    string nim = "054";

    const int max_produk = 100;
    Produk produk[max_produk];
    int jumlahproduk = 5;

    produk[0] = {"Backpack Rajut", 300000, {"Pink", 20}};
    produk[1] = {"Tote Bag Rajut", 125000, {"Baby Blue", 45}};
    produk[2] = {"Sling Bag Rajut", 95000, {"Hitam", 30}};
    produk[3] = {"Hand Bag Rajut", 80000, {"Cream", 15}};
    produk[4] = {"Pouch Rajut", 65000, {"Maroon", 50}};

    string inputnama, inputnim;
    int percobaan = 3;
    while (percobaan > 0) {
        cout << "Masukkan Nama: ";
        cin >> inputnama;
        cout << "Masukkan NIM: ";
        cin >> inputnim;

        if (inputnama == username && inputnim == nim) {
            break;
        } else {
            percobaan--;
            cout << "Login gagal! Sisa percobaan: " << percobaan << endl;
        }
    }

    if (percobaan == 0) {
        cout << "Mohon maaf percobaan login gagal! Program berhenti.\n";
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
            if (jumlahproduk < max_produk) {
                cin.ignore();
                cout << "Masukkan nama produk: ";
                getline(cin, produk[jumlahproduk].nama);
                cout << "Masukkan harga produk: ";
                cin >> produk[jumlahproduk].harga;
                cin.ignore();
                cout << "Masukkan warna produk: ";
                getline(cin, produk[jumlahproduk].detail.warna);
                cout << "Masukkan stok produk: ";
                cin >> produk[jumlahproduk].detail.stok;
                jumlahproduk++;
                cout << "Produk berhasil ditambahkan!\n";
                cout << "\n+----+--------------------+------------+------+------------+\n";
                cout << "| No | Nama Produk        | Harga      | Stok | Warna      |\n";
                cout << "+----+--------------------+------------+------+------------+\n";
                    for (int i = 0; i < jumlahproduk; i++) {
                        cout << "| " << setw(2) << i + 1
                             << " | " << left << setw(18) << produk[i].nama
                             << " | " << right << setw(10) << produk[i].harga
                             << " | " << setw(4) << produk[i].detail.stok
                             << " | " << setw(10) << left << produk[i].detail.warna << " |\n";
                    }
                    cout << "+----+--------------------+------------+------+------------+\n";
                } else {
                    cout << "Data penuh! Tidak bisa menambah produk lagi.\n";
                }
                break;

            case 2:
                if (jumlahproduk == 0) {
                    cout << "Belum ada produk yang tersedia.\n";
                } else {
                    cout << "\n+----+--------------------+------------+------+------------+\n";
                    cout << "| No | Nama Produk        | Harga      | Stok | Warna      |\n";
                    cout << "+----+--------------------+------------+------+------------+\n";
                    for (int i = 0; i < jumlahproduk; i++) {
                        cout << "| " << setw(2) << i + 1
                             << " | " << left << setw(18) << produk[i].nama
                             << " | " << right << setw(10) << produk[i].harga
                             << " | " << setw(4) << produk[i].detail.stok
                             << " | " << setw(10) << left << produk[i].detail.warna << " |\n";
                    }
                    cout << "+----+--------------------+------------+------+------------+\n";
                }
                break;

            case 3:
                if (jumlahproduk == 0) {
                    cout << "Tidak ada produk untuk diubah.\n";
                } else {
                    int index;
                    cout << "\n+----+--------------------+------------+------+------------+\n";
                    cout << "| No | Nama Produk        | Harga      | Stok | Warna      |\n";
                    cout << "+----+--------------------+------------+------+------------+\n";
                    for (int i = 0; i < jumlahproduk; i++) {
                        cout << "| " << setw(2) << i + 1
                             << " | " << left << setw(18) << produk[i].nama
                             << " | " << right << setw(10) << produk[i].harga
                             << " | " << setw(4) << produk[i].detail.stok
                             << " | " << setw(10) << left << produk[i].detail.warna << " |\n";
                    }
                    cout << "+----+--------------------+------------+------+------------+\n";

                    cout << "Masukkan nomor produk yang ingin diubah: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahproduk) {
                        index--;
                        cout << "Masukkan harga baru: ";
                        cin >> produk[index].harga;
                        cin.ignore();
                        cout << "Masukkan stok baru: ";
                        cin >> produk[index].detail.stok;
                        cout << "Produk berhasil diperbarui!\n";
                    } else {
                        cout << "Nomor produk tidak valid!\n";
                    }
                }
                break;

            case 4:
                if (jumlahproduk == 0) {
                    cout << "Tidak ada produk yang bisa dihapus.\n";
                } else {
                    int index;
                    cout << "\n+----+--------------------+------------+------+------------+\n";
                    cout << "| No | Nama Produk        | Harga      | Stok | Warna      |\n";
                    cout << "+----+--------------------+------------+------+------------+\n";
                    for (int i = 0; i < jumlahproduk; i++) {
                        cout << "| " << setw(2) << i + 1
                             << " | " << left << setw(18) << produk[i].nama
                             << " | " << right << setw(10) << produk[i].harga
                             << " | " << setw(4) << produk[i].detail.stok
                             << " | " << setw(10) << left << produk[i].detail.warna << " |\n";
                    }
                    cout << "+----+--------------------+------------+------+------------+\n";
                    cout << "Masukkan nomor produk yang ingin dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahproduk) {
                        index--;
                        for (int i = index; i < jumlahproduk - 1; i++) {
                            produk[i] = produk[i + 1];
                        }
                        jumlahproduk--;
                        cout << "Produk berhasil dihapus!\n";
                    } else {
                        cout << "Nomor produk tidak valid!\n";
                    }
                }
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