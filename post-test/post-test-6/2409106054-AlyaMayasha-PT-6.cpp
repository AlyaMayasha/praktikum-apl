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

bool login(string username, string nim) {
    string inputnama, inputnim;
    int percobaan = 3;
    while (percobaan > 0) {
        cout << "Masukkan Nama: ";
        cin >> inputnama;
        cout << "Masukkan NIM: ";
        cin >> inputnim;

        if (inputnama == username && inputnim == nim) {
            return true;
        } else {
            percobaan--;
            cout << "Login gagal! Sisa percobaan: " << percobaan << endl;
        }
    }
    return false;
}

void tampilkanProduk(Produk *produk, int *jumlahproduk) {
    if (*jumlahproduk == 0) {
        cout << "Belum ada produk yang tersedia.\n";
    } else {
        cout << "\n+----+--------------------+------------+------+------------+\n";
        cout << "| No | Nama Produk        | Harga      | Stok | Warna      |\n";
        cout << "+----+--------------------+------------+------+------------+\n";
        for (int i = 0; i < *jumlahproduk; i++) {
            cout << "| " << setw(2) << i + 1
                 << " | " << left << setw(18) << (produk + i)->nama
                 << " | " << right << setw(10) << (produk + i)->harga
                 << " | " << setw(4) << (produk + i)->detail.stok
                 << " | " << setw(10) << left << (produk + i)->detail.warna << " |\n";
        }
        cout << "+----+--------------------+------------+------+------------+\n";
    }
}

int tambahProduk(Produk *produk, int *jumlahproduk) {
    if (*jumlahproduk < max_produk) {
        cin.ignore();
        cout << "Masukkan nama produk: ";
        getline(cin, (produk + *jumlahproduk)->nama);
        cout << "Masukkan harga produk: ";
        cin >> (produk + *jumlahproduk)->harga;
        cin.ignore();
        cout << "Masukkan warna produk: ";
        getline(cin, (produk + *jumlahproduk)->detail.warna);
        cout << "Masukkan stok produk: ";
        cin >> (produk + *jumlahproduk)->detail.stok;
        cout << "Produk berhasil ditambahkan!\n";
        (*jumlahproduk)++;
        tampilkanProduk(produk, jumlahproduk);
    } else {
        cout << "Data penuh! Tidak bisa menambah produk lagi.\n";
    }
    return *jumlahproduk;
}

void ubahProduk(Produk &produk) {
    cout << "Masukkan harga baru: ";
    cin >> produk.harga;
    cout << "Masukkan stok baru: ";
    cin >> produk.detail.stok;
    cout << "Produk berhasil diperbarui!\n";
}

int hapusProduk(Produk *produk, int &jumlahproduk) {
    if (jumlahproduk == 0) {
        cout << "Tidak ada produk yang bisa dihapus.\n";
        return jumlahproduk;
    }

    tampilkanProduk(produk, &jumlahproduk);
    int index;
    cout << "Masukkan nomor produk yang ingin dihapus: ";
    cin >> index;
    if (index > 0 && index <= jumlahproduk) {
        index--;
        for (int i = index; i < jumlahproduk - 1; i++) {
            *(produk + i) = *(produk + i + 1);
        }
        jumlahproduk--;
        cout << "Produk berhasil dihapus!\n";
    } else {
        cout << "Nomor produk tidak valid!\n";
    }
    return jumlahproduk;
}

void sortNamaProduk(Produk *produk, int jumlahproduk) {
    for (int i = 0; i < jumlahproduk - 1; i++) {
        for (int j = 0; j < jumlahproduk - i - 1; j++) {
            if ((produk + j)->nama < (produk + j + 1)->nama) {
                Produk temp = *(produk + j);
                *(produk + j) = *(produk + j + 1);
                *(produk + j + 1) = temp;
            }
        }
    }
    cout << "Produk berhasil disorting berdasarkan nama (Z-A) dengan Bubble Sort!\n";
}

void sortHarga(Produk *produk, int jumlahproduk) {
    for (int i = 0; i < jumlahproduk - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < jumlahproduk; j++) {
            if ((produk + j)->harga < (produk + minIndex)->harga) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Produk temp = *(produk + i);
            *(produk + i) = *(produk + minIndex);
            *(produk + minIndex) = temp;
        }
    }
    cout << "Produk berhasil disorting berdasarkan harga (termurah-termahal) dengan Selection Sort!\n";
}

int partition(Produk *produk, int low, int high) {
    int pivot = (produk + high)->detail.stok;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((produk + j)->detail.stok > pivot) { 
            i++;
            Produk temp = *(produk + i);
            *(produk + i) = *(produk + j);
            *(produk + j) = temp;
        }
    }
    Produk temp = *(produk + i + 1);
    *(produk + i + 1) = *(produk + high);
    *(produk + high) = temp;
    return i + 1;
}

void quickSortStok(Produk *produk, int low, int high) {
    if (low < high) {
        int pi = partition(produk, low, high);
        quickSortStok(produk, low, pi - 1);
        quickSortStok(produk, pi + 1, high);
    }
}

void sortStokDesc(Produk *produk, int jumlahproduk) {
    quickSortStok(produk, 0, jumlahproduk - 1);
    cout << "Produk berhasil disorting berdasarkan stok (banyak ke sedikit) dengan Quick Sort!\n";
}


int main() {
    string username = "Alya";
    string nim = "054";

    Produk produk[max_produk];
    int jumlahproduk = 5;

    produk[0] = {"Backpack Rajut", 300000, {"Pink", 20}};
    produk[1] = {"Tote Bag Rajut", 125000, {"Baby Blue", 45}};
    produk[2] = {"Sling Bag Rajut", 95000, {"Hitam", 30}};
    produk[3] = {"Hand Bag Rajut", 80000, {"Cream", 15}};
    produk[4] = {"Pouch Rajut", 65000, {"Maroon", 50}};

    if (!login(username, nim)) {
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
        cout << "5. Sorting Produk\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahproduk = tambahProduk(produk, &jumlahproduk);
                break;
            case 2:
                tampilkanProduk(produk, &jumlahproduk);
                break;
            case 3:
                if (jumlahproduk == 0) {
                    cout << "Tidak ada produk untuk diubah.\n";
                } else {
                    tampilkanProduk(produk, &jumlahproduk);
                    int index;
                    cout << "Masukkan nomor produk yang ingin diubah: ";
                    cin >> index;
                    if (index > 0 && index <= jumlahproduk) {
                        ubahProduk(*(produk + index - 1));
                    } else {
                        cout << "Nomor produk tidak valid!\n";
                    }
                }
                break;
            case 4:
                jumlahproduk = hapusProduk(produk, jumlahproduk);
                break;
            case 5: {
                int opsiSort;
                do {
                    cout << "\n=== Menu Sorting ===\n";
                    cout << "1. Sorting Nama (Z-A) [Bubble Sort]\n";
                    cout << "2. Sorting Harga (Ascending) [Selection Sort]\n";
                    cout << "3. Sorting Stok (Descending) [Quick Sort]\n";
                    cout << "4. Kembali ke Menu Utama\n";
                    cout << "Pilihan: ";
                    cin >> opsiSort;
                    
                    switch (opsiSort) {
                        case 1:
                            sortNamaProduk(produk, jumlahproduk);
                            tampilkanProduk(produk, &jumlahproduk);
                            break;
                        case 2:
                            sortHarga(produk, jumlahproduk);
                            tampilkanProduk(produk, &jumlahproduk);
                            break;
                        case 3:
                            sortStokDesc(produk, jumlahproduk);
                            tampilkanProduk(produk, &jumlahproduk);
                            break;
                        case 4:
                            cout << "Kembali ke menu utama...\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid! Coba lagi.\n";
                    }
                } while (opsiSort != 4);
                break;
            }
            case 6:
                cout << "Terima kasih telah menggunakan program ini. Have a great day >_<!\n";
                break;
            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 6);

    return 0;
}
