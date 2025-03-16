#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string username = "Alya";
    string nim = "054";

    const int max_produk = 100;
    string namaproduk[max_produk] = {
        "Backpack Rajut", "Tote Bag Rajut", "Sling Bag Rajut",
        "Hand Bag Rajut", "Pouch Rajut"
    };
    int hargaproduk[max_produk] = {300000, 125000, 95000, 80000, 65000};
    int stokproduk[max_produk] = {20, 45, 30, 15, 50};
    int jumlahproduk = 5;
    string warnaproduk[max_produk] = {"Pink", "Baby Blue", "Hitam", "Cream", "Maroon"};

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
                    getline(cin, namaproduk[jumlahproduk]);
                    cout << "Masukkan harga produk: ";
                    cin >> hargaproduk[jumlahproduk];
                    cout << "Masukkan stok produk: ";
                    cin >> stokproduk[jumlahproduk];
                    cout << "Masukkan warna produk: ";
                    cin >> warnaproduk[jumlahproduk];
                    jumlahproduk++;
                    cout << "Produk berhasil ditambahkan!\n";
                    cout << "\n+----+--------------------+------------+------+------------+\n";
                    cout << "| No | Nama Produk        | Harga      | Stok | Warna      |\n";
                    cout << "+----+--------------------+------------+------+------------+\n";
                    for (int i = 0; i < jumlahproduk; i++) {
                    cout << "| " << setw(2) << i + 1
                         << " | " << left << setw(18) << namaproduk[i]
                         << " | " << right << setw(10) << hargaproduk[i]
                         << " | " << setw(4) << stokproduk[i]
                         << " | " << setw(10) << left << warnaproduk[i] << " |\n";
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
                         << " | " << left << setw(18) << namaproduk[i]
                         << " | " << right << setw(10) << hargaproduk[i]
                         << " | " << setw(4) << stokproduk[i]
                         << " | " << setw(10) << left << warnaproduk[i] << " |\n";
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
                         << " | " << left << setw(18) << namaproduk[i]
                         << " | " << right << setw(10) << hargaproduk[i]
                         << " | " << setw(4) << stokproduk[i]
                         << " | " << setw(10) << left << warnaproduk[i] << " |\n";
                }
                cout << "+----+--------------------+------------+------+------------+\n";
                    
                    cout << "Masukkan nomor produk yang ingin diubah: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahproduk) {
                        index--;
                        cout << "Masukkan harga baru: ";
                        cin >> hargaproduk[index];
                        cout << "Masukkan stok baru: ";
                        cin >> stokproduk[index];
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
                         << " | " << left << setw(18) << namaproduk[i]
                         << " | " << right << setw(10) << hargaproduk[i]
                         << " | " << setw(4) << stokproduk[i]
                         << " | " << setw(10) << left << warnaproduk[i] << " |\n";
                }
                cout << "+----+--------------------+------------+------+------------+\n";
                    cout << "Masukkan nomor produk yang ingin dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahproduk) {
                        index--;
                        for (int i = index; i < jumlahproduk - 1; i++) {
                            namaproduk[i] = namaproduk[i + 1];
                            hargaproduk[i] = hargaproduk[i + 1];
                            stokproduk[i] = stokproduk[i + 1];
                        }
                        jumlahproduk--;
                        cout << "Produk berhasil dihapus!\n";
                    } else {
                        cout << "Nomor produk tidak valid!\n";
                    }
                }
                break;

            case 5:
                cout << "Terima kasih telah menggunakan program ini. Have great day >_<!\n";
                break;

            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}