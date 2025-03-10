#include <iostream>
using namespace std;

int PIN_BENAR = 6054;
int BATAS_GAGAL = 3;

int main() {
    int pin;
    bool aksesditerima = false;
    int saldo = 2000000;

    cout << "=== SELAMAT DATANG DI ATM ===\n";
    for (int percobaan = 1; percobaan <= BATAS_GAGAL; percobaan++) {
        cout << "Masukkan PIN Anda: ";
        cin >> pin;

        if (pin == PIN_BENAR) {
            cout << "PIN benar. Selamat datang!\n";
            aksesditerima = true;
            break;
        } else {
            cout << "PIN salah! Percobaan ke-" << percobaan << " dari " << BATAS_GAGAL << ".\n";
        }
    }

    if (aksesditerima) {
        int pilihan;
        while (true) {
            cout << "\n=== MENU ATM ===\n";
            cout << "1. Setor Tunai\n";
            cout << "2. Cek Saldo\n";
            cout << "3. Tarik Tunai\n";
            cout << "4. Keluar\n";
            cout << "Pilih menu (1-4): ";
            cin >> pilihan;

            switch (pilihan) {
                case 1: {
                    int setor;
                    cout << "Masukkan jumlah setor tunai: ";
                    cin >> setor;
                    saldo += setor;
                    cout << "Setor tunai berhasil. Saldo Anda saat ini: Rp" << saldo << endl;
                    break;
                }
                case 2:
                    cout << "Saldo Anda saat ini: Rp" << saldo << endl;
                    break;
                case 3: {
                    int tarik;
                    cout << "Masukkan jumlah tarik tunai: ";
                    cin >> tarik;
                    if (tarik > saldo) {
                        cout << "Mohon maaf saldo tidak mencukupi!\n";
                    } else {
                        saldo -= tarik;
                        cout << "Tarik tunai berhasil. Saldo Anda saat ini: Rp" << saldo << endl;
                    }
                    break;
                }
                case 4:
                    cout << "Terima kasih telah menggunakan ATM ini. Have a great day!\n";
                    return 0; 
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi.\n";
            }
        }
    } else {
        cout << "Anda telah salah memasukkan PIN sebanyak 3 kali. Akses diblokir.\n";
    }

    return 0;
}