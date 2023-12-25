// NAMA     : Muhammad Ghazian Tsaqif Zhafiri Andoz
// NIM      : 23343057

#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaFilm1 = "One Piece: The End";
    string namaFilm2 = "Saruto: Boruto Next Generation";
    string namaFilm3 = "Boboiboy Movie 10";
    string namaFilm4 = "Not Curious George";

    char kursi[16];
    int jumlahTiket, jumlahPopcorn, nomorFilm;
    float hargaFilm = 35000.0, hargaPopcorn = 20000.0, totalHarga, uangKembalian, jumlahBayar;

    cout << endl;
    cout << "======================================" << endl;
    cout << "|         SELAMAT DATANG DI          |" << endl;
    cout << "|          BIOSKOP UNP-XXI           |" << endl;
    cout << "======================================" << endl
         << endl;

    cout << "--------------------------------------" << endl;
    cout << "| Pilihan Film:                      |" << endl;
    cout << "--------------------------------------" << endl;
    cout << "| 1 | " << namaFilm1 << endl;
    cout << "| 2 | " << namaFilm2 << endl;
    cout << "| 3 | " << namaFilm3 << endl;
    cout << "| 4 | " << namaFilm4 << endl;
    cout << "======================================" << endl;
    cout << "-> Masukkan nomor film (1-4): ";
    cin >> nomorFilm;

    string namaFilm;
    switch (nomorFilm) {
        case 1:
            namaFilm = namaFilm1;
            break;
        case 2:
            namaFilm = namaFilm2;
            break;
        case 3:
            namaFilm = namaFilm3;
            break;
        case 4:
            namaFilm = namaFilm4;
            break;
        default:
            cout << "Nomor film tidak valid." << endl;
            return 1;
    }

    cout << endl;
    cout << "=================================" << endl;
    cout << "| HARGA TIKET: 35.000/tiket     |" << endl;
    cout << "| HARGA POPCORN: 20.000/tiket   |" << endl;
    cout << "=================================" << endl;

    cout << "-> Jumlah tiket yang ingin dipesan: ";
    cin >> jumlahTiket;
    cout << "-> Jumlah popcorn yang ingin dipesan: ";
    cin >> jumlahPopcorn;

    cout << endl;
    cout << "============================" << endl;
    cout << "|                          |" << endl;
    cout << "|    A   B   C   D   E     |" << endl;
    cout << "|    F   G   H   I   J     |" << endl;
    cout << "|    K   L   M   N   O     |" << endl;
    cout << "|                          |" << endl;
    cout << "|     [LAYAR BIOSKOP]      |" << endl;
    cout << "============================" << endl
         << endl;

    for (int i = 0; i < jumlahTiket; i++) {
        cout << "-> Silahkan pilih kursi tiket ke-" << i + 1 << ": ";
        cin >> kursi[i];
    }

    totalHarga = (hargaFilm * jumlahTiket) + (hargaPopcorn * jumlahPopcorn);

    cout << endl
         << "--------------------------------------" << endl;
    cout << "|          Detail Pesanan:           |" << endl;
    cout << "--------------------------------------" << endl
         << endl;
    cout << "Film: " << namaFilm << endl;
    cout << "Jumlah Tiket: " << jumlahTiket << " x " << hargaFilm << " = " << (hargaFilm * jumlahTiket) << endl;
    cout << "Jumlah Popcorn: " << jumlahPopcorn << " x " << hargaPopcorn << " = " << (hargaPopcorn * jumlahPopcorn) << endl;
    cout << "Total Harga: " << totalHarga << " Rupiah" << endl;

    cout << endl
         << "-> Masukkan jumlah pembayaran: ";
    cin >> jumlahBayar;

    uangKembalian = jumlahBayar - totalHarga;

    if (jumlahBayar >= totalHarga) {
        cout << endl
             << "[ Total kembalian: " << uangKembalian << " Rupiah ]" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "  Terima kasih atas pembayarannya. Selamat menikmati!  " << endl;
        cout << "-------------------------------------------------------" << endl;
    } else {
        cout << "Maaf, jumlah pembayaran tidak mencukupi. Transaksi dibatalkan." << endl;
    }

    return 0;
}
