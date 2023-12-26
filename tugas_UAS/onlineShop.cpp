#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int pilihan;
int jumlah;
bool adaKeranjang = 0;
string userInput;

// Struct untuk menyimpan informasi barang
typedef struct {
    string nama;
    double harga;
    int jumlah;
    float totalBayar;
} Barang;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "_____________________________________________" << endl;
    cout << "|     _____ __  ______  ____  ____________  |" << endl;
    cout << "|    / ___// / / / __ \\/ __ \\/ ____/ ____/  |" << endl;
    cout << "|    \\__ \\/ /_/ / / / / /_/ / __/ / __/     |" << endl;
    cout << "|   ___/ / __  / /_/ / ____/ /___/ /___     |" << endl;
    cout << "|  /____/_/ /_/\\____/_/   /_____/_____/     |" << endl;
    cout << "| __________________________________________|" << endl
         << endl;

    cout << "+========---------------------------========+" << endl;
    cout << "| 1 | Mulai Belanja                         |" << endl;
    cout << "| 2 | Tampilkan Keranjang Belanja           |" << endl;
    cout << "| 3 | Ubah Jumlah Barang dalam Keranjang    |" << endl;
    cout << "| 4 | Bayar                                 |" << endl;
    cout << "| 5 | Batal Pesanan                         |" << endl;
    cout << "| 6 | Keluar Program                        |" << endl;
    cout << "+========---------------------------========+" << endl;
    cout << "-> Pilih menu: ";
    cin >> pilihan;
}

void tekanEnter() {
    cout << "[ Tekan enter untuk kembali ke beranda ] ";
    cin.ignore();
    getline(cin, userInput);
}

// Fungsi untuk memulai belanja
void mulaiBelanja(Barang daftarBarang[], int jumlahBarang) {
    cout << "+================================================+" << endl;
    cout << "|                  DAFTAR BARANG                 | " << endl;
    cout << "+================================================+" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| NO | NAMA BARANG \t\t|   HARGA \t |" << endl;
    cout << "+------------------------------------------------+" << endl;
    for (int i = 0; i < jumlahBarang; ++i) {
        cout << "| " << i + 1 << "  | " << daftarBarang[i].nama << " \t\t| - Rp" << daftarBarang[i].harga << "\t |" << endl;
    }
    cout << "+------------------------------------------------+" << endl;

    do {
        cout << endl
             << "-> Pilih barang (0 untuk selesai): ";
        cin >> pilihan;

        if (pilihan < 0 || pilihan > jumlahBarang) {
            cout << "[ Pilihan tidak valid, silakan pilih kembali! ]" << endl;
            continue;
        }

        if (pilihan != 0) {
            cout << "-> Masukkan jumlah barang yang ingin dibeli: ";
            cin >> jumlah;

            // Memperbarui jumlah barang yang dibeli
            daftarBarang[pilihan - 1].jumlah += jumlah;
            adaKeranjang = 1;
        }

    } while (pilihan != 0);
    system("cls");
}

// Fungsi untuk menampilkan keranjang belanja
void tampilkanKeranjangBelanja(Barang daftarBarang[], int jumlahBarang) {
    int totalKeseluruhan = 0;

    cout << "+================================================+" << endl;
    cout << "|               KERANJANG BELANJA                | " << endl;
    cout << "+================================================+" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| JMLH \t| NAMA BARANG \t\t| TOTAL HARGA \t |" << endl;
    cout << "+------------------------------------------------+" << endl;
    for (int i = 0; i < jumlahBarang; ++i) {
        if (daftarBarang[i].jumlah > 0) {
            daftarBarang[i].totalBayar = daftarBarang[i].harga * daftarBarang[i].jumlah;

            cout << "| " << daftarBarang[i].jumlah << "\t| " << daftarBarang[i].nama << "\t\t| " << daftarBarang[i].totalBayar << "\t\t |" << endl;

            totalKeseluruhan += daftarBarang[i].totalBayar;
        }
    }
    cout << "+------------------------------------------------+" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "+================================================+" << endl;
    cout << "| TOTAL KESELURUHAN: " << totalKeseluruhan << " Rupiah \t\t |" << endl;
    cout << "+================================================+" << endl
         << endl
         << endl;
}

// Fungsi untuk mencetak struk ke file teks
void cetakStruk(Barang daftarBarang[], int jumlahBarang, int totalHarga, int uang, int kembalian) {
    ofstream fileStruk("struk_pembayaran.txt");  // Membuat file struk_pembayaran.txt

    if (fileStruk.is_open()) {  // Memastikan file terbuka dengan sukses
        fileStruk << "+================================================+" << endl;
        fileStruk << "|              INVOICE PEMBAYARAN                | " << endl;
        fileStruk << "+================================================+" << endl;
        fileStruk << "+------------------------------------------------+" << endl;
        fileStruk << "| JMLH \t| NAMA BARANG \t\t| TOTAL HARGA \t |" << endl;
        fileStruk << "+------------------------------------------------+" << endl;
        for (int i = 0; i < jumlahBarang; ++i) {
            if (daftarBarang[i].jumlah > 0) {
                daftarBarang[i].totalBayar = daftarBarang[i].harga * daftarBarang[i].jumlah;

                fileStruk << "| " << daftarBarang[i].jumlah << "\t| " << daftarBarang[i].nama << "\t\t| " << daftarBarang[i].totalBayar << "\t\t |" << endl;
            }
        }
        fileStruk << "+------------------------------------------------+" << endl;
        fileStruk << "+------------------------------------------------+" << endl;
        fileStruk << "+================================================+" << endl;
        fileStruk << "| TOTAL KESELURUHAN: " << totalHarga << " Rupiah \t\t |" << endl;
        fileStruk << "+================================================+" << endl
                  << endl;

        fileStruk << "[ Uang yang diterima: Rp" << uang << " ]" << endl;
        fileStruk << "[ Kembalian Anda: Rp" << kembalian << " ]" << endl
                  << endl;
        fileStruk << "[ Pembayaran berhasil. Terima kasih! ]" << endl
                  << endl;

        tekanEnter();

        fileStruk.close();  // Menutup file setelah selesai ditulis
    } else {
        cout << "[ Gagal membuka file struk_pembayaran.txt ]" << endl;
    }
}

// Fungsi untuk proses pembayaran
void bayar(Barang daftarBarang[], int jumlahBarang) {
    char metodePembayaran;
    string kodeDiskon;
    int totalHarga = 0;
    bool diskon50 = false;
    char kodeRespon;

    cout << "+================================================+" << endl;
    cout << "|               KERANJANG BELANJA                | " << endl;
    cout << "+================================================+" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| JMLH \t| NAMA BARANG \t\t| TOTAL HARGA \t |" << endl;
    cout << "+------------------------------------------------+" << endl;
    for (int i = 0; i < jumlahBarang; ++i) {
        if (daftarBarang[i].jumlah > 0) {
            daftarBarang[i].totalBayar = daftarBarang[i].harga * daftarBarang[i].jumlah;

            cout << "| " << daftarBarang[i].jumlah << "\t| " << daftarBarang[i].nama << "\t\t| " << daftarBarang[i].totalBayar << "\t\t |" << endl;

            totalHarga += daftarBarang[i].totalBayar;
        }
    }
    cout << "+------------------------------------------------+" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "+================================================+" << endl;
    cout << "| TOTAL KESELURUHAN: " << totalHarga << " Rupiah \t\t |" << endl;
    cout << "+================================================+" << endl
         << endl;

    cout << "+---------------------+" << endl;
    cout << "|  METODE PEMBAYARAN  |" << endl;
    cout << "+---------------------+" << endl;
    cout << "| 1 | CASH            |" << endl;
    cout << "| 2 | DEBIT           |" << endl;
    cout << "+---------------------+" << endl;
    cout << "-> Pilih metode pembayaran: ";
    cin >> metodePembayaran;

    if (metodePembayaran == '1') {
        cout << "--> Apakah Anda memiliki kode diskon? (y/n): ";
        cin >> kodeRespon;

        if (kodeRespon == 'y') {
            cout << "--> Masukkan kode diskon: ";
            cin >> kodeDiskon;

            if (kodeDiskon == "UNP123") {
                diskon50 = true;
                totalHarga /= 2;  // Diskon 50%

                system("cls");
                cout << "  ___ ___ ___ _  _____  _  _   ___  __ _   __ " << endl;
                cout << " |   \\_ _/ __| |/ / _ \\| \\| | | __|/  (_) / /" << endl;
                cout << " | |) | |\\__ \\ ' < (_) | .` | |__ \\ () |/ /_ " << endl;
                cout << " |___/___|___/_|\\_\\___/|_|\\_| |___/\\__//_/(_)" << endl
                     << endl;
            }
        }

        int uang;
        cout << endl
             << "[ Total harga yang harus dibayar: Rp" << totalHarga << " ]" << endl;
        cout << "--> Masukkan jumlah uang: Rp";
        cin >> uang;

        cout << endl;

        if (uang >= totalHarga) {
            int kembalian = uang - totalHarga;
            cout << "[ Kembalian Anda: Rp" << kembalian << " ]" << endl;
            cout << "[ Pembayaran berhasil. Terima kasih! ]" << endl
                 << endl;
            cetakStruk(daftarBarang, jumlahBarang, totalHarga, uang, kembalian);  // Memanggil fungsi cetakStruk
            // Reset jumlah barang yang dibeli setelah pembayaran berhasil
            for (int i = 0; i < jumlahBarang; ++i) {
                daftarBarang[i].jumlah = 0;
            }
        } else {
            cout << "[ Maaf, uang yang dimasukkan kurang ]" << endl;
        }
    } else if (metodePembayaran == '2') {
        cout << endl
             << "[ Tekan enter untuk menggesek kartu debit ] ";
        cin.ignore();
        getline(cin, userInput);

        cout << endl
             << "[ Pembayaran dengan debit berhasil. Terima kasih! ]" << endl;

        // Reset jumlah barang yang dibeli setelah pembayaran berhasil
        for (int i = 0; i < jumlahBarang; ++i) {
            daftarBarang[i].jumlah = 0;
        }
    } else {
        cout << "Metode pembayaran tidak valid." << endl;
    }
}

void tampilKeranjangKosong() {
    cout << endl
         << "[ Belum Ada List Keranjang Belanja ]" << endl;
    cout << "[      Selamat Berbelanja :)       ]" << endl;
    cout << endl
         << endl;

    tekanEnter();
    system("cls");
}

// Fungsi untuk membatalkan pesanan barang dari keranjang belanja
void batalPesanan(Barang daftarBarang[], int jumlahBarang) {
    int nomorPesanan;

    cout << "+================================================+" << endl;
    cout << "|           PEMBATALAN PESANAN BARANG            | " << endl;
    cout << "+================================================+" << endl;
    cout << "+------------------------------------------------+" << endl;
    cout << "| JMLH \t| NAMA BARANG \t\t| TOTAL HARGA \t |" << endl;
    cout << "+------------------------------------------------+" << endl;
    for (int i = 0; i < jumlahBarang; ++i) {
        if (daftarBarang[i].jumlah > 0) {
            daftarBarang[i].totalBayar = daftarBarang[i].harga * daftarBarang[i].jumlah;

            cout << "| " << daftarBarang[i].jumlah << "\t| " << daftarBarang[i].nama << "\t\t| " << daftarBarang[i].totalBayar << "\t\t |" << endl;
        }
    }
    cout << "+------------------------------------------------+" << endl;
    cout << "-> Masukkan nomor pesanan yang ingin dibatalkan (0 untuk selesai): ";
    cin >> nomorPesanan;

    if (nomorPesanan >= 1 && nomorPesanan <= jumlahBarang) {
        if (daftarBarang[nomorPesanan - 1].jumlah > 0) {
            daftarBarang[nomorPesanan - 1].jumlah = 0;
            cout << "[ Pesanan barang berhasil dibatalkan! ]" << endl;
        } else {
            cout << "[ Nomor pesanan tidak memiliki barang! ]" << endl;
        }
    } else if (nomorPesanan != 0) {
        cout << "[ Nomor pesanan tidak valid! ]" << endl;
    }

    cout << "[ Tekan enter untuk kembali ke beranda ] ";
    cin.ignore();
    getline(cin, userInput);
    system("cls");
}

void ubahJumlahBarang(Barang daftarBarang[], int jumlahBarang) {
    int nomorBarang, jumlahBaru;

    cout << "+================================================+" << endl;
    cout << "|           UBAH JUMLAH BARANG DI KERANJANG      | " << endl;
    cout << "+================================================+" << endl;

    tampilkanKeranjangBelanja(daftarBarang, jumlahBarang);

    cout << "-> Masukkan nomor barang yang ingin diubah jumlahnya: ";
    cin >> nomorBarang;

    if (nomorBarang >= 1 && nomorBarang <= jumlahBarang) {
        if (daftarBarang[nomorBarang - 1].jumlah > 0) {
            cout << "--> Masukkan jumlah baru: ";
            cin >> jumlahBaru;

            // Update jumlah barang yang dipilih
            if (jumlahBaru >= 0) {
                daftarBarang[nomorBarang - 1].jumlah = jumlahBaru;
                cout << endl
                     << "[ Jumlah barang berhasil diubah! ]" << endl;
            } else {
                cout << "[ Jumlah tidak valid! ]" << endl;
            }
        } else {
            cout << endl
                 << "[ Nomor barang tidak memiliki jumlah! ]" << endl;
        }
    } else {
        cout << "[ Nomor barang tidak valid! ]" << endl;
    }

    cout << "[ Tekan enter untuk kembali ke beranda ] ";
    cin.ignore();
    getline(cin, userInput);
    system("cls");
}

int main() {
    system("cls");
    const int jumlahBarang = 7;
    Barang daftarBarang[jumlahBarang] = {
        {"Panci   ", 50000, 0},
        {"Sabun Cuci", 15000, 0},
        {"Payung  ", 20000, 0},
        {"Shampoo ", 75000, 0},
        {"Sandal Swallow", 45000, 0},
        {"Pasta Gigi", 99000, 0},
        {"Kipas Turbo", 34000, 0}};

    do {
        tampilkanMenu();
        switch (pilihan) {
            case 1:
                system("cls");
                mulaiBelanja(daftarBarang, jumlahBarang);
                break;
            case 2:
                system("cls");
                if (adaKeranjang == 1) {
                    tampilkanKeranjangBelanja(daftarBarang, jumlahBarang);
                    tekanEnter();

                    system("cls");
                } else {
                    tampilKeranjangKosong();
                }
                break;

            case 3:
                system("cls");
                if (adaKeranjang == 1) {
                    ubahJumlahBarang(daftarBarang, jumlahBarang);
                } else {
                    tampilKeranjangKosong();
                }
                break;

            case 4:
                system("cls");
                if (adaKeranjang == 1) {
                    bayar(daftarBarang, jumlahBarang);
                    system("cls");
                    adaKeranjang = 0;
                } else {
                    tampilKeranjangKosong();
                }
                break;
            case 5:
                system("cls");
                if (adaKeranjang == 1) {
                    batalPesanan(daftarBarang, jumlahBarang);
                } else {
                    tampilKeranjangKosong();
                }
                break;
            case 6:
                system("cls");
                cout << endl
                     << "+-----------------------------------------------------+" << endl;
                cout << "|   Terima kasih telah menggunakan program belanja!   |" << endl;
                cout << "|           Semoga Hari Anda Menyenangkan :)          |" << endl;
                cout << "+-----------------------------------------------------+" << endl
                     << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}
