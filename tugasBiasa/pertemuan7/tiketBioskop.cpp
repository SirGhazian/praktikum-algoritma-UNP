#include <iostream>
using namespace std;

int main() {
    int pilihan_film, jumlah_tiket, jumlah_popcorn, total_popcorn, total_tiket;
    char opsi, konfirmasi;

    cout << "\n  ====================" << endl;
    cout << "  ||   XXI CINEMA   ||" << endl;
    cout << "  ====================" << endl
         << endl;

    cout << "\nBerikut pilihan film yang tersedia" << endl;
    cout << "-> 1) One Piece: The End" << endl;
    cout << "--> 2) Saruto: Boruto Next Generation" << endl;
    cout << "---> 3) Tendangan Si Madun vs Christiano Ronaldo" << endl;
    cout << "----> 4) Si Unyil: The Last" << endl;
    cout << "\nHarga tiket hari ini: 35.000/film" << endl;
    cout << "Harga popcorn hari ini: 30.000/popcorn" << endl;

    cout << "\nApakah anda ingin memesan tiket? (Y/N) ";
    cin >> opsi;

    if (opsi == 'Y' || opsi == 'y') {
        int tries = 3;
        do {
            cout << "Film nomor berapa yang ingin anda tonton? ";
            cin >> pilihan_film;
            tries--;

            if (pilihan_film < 1 || pilihan_film > 4) {
                cout << "Pilihan tidak valid. Sisa percobaan: " << tries << endl;
            }

        } while ((pilihan_film < 1 || pilihan_film > 4) && tries > 0);

        if (tries == 0 && (pilihan_film < 1 || pilihan_film > 4)) {
            cout << "Anda sudah mencoba sebanyak tiga kali. Program berakhir." << endl;
            return 0;
        }
    } else {
        cout << "Cih, liat doang, beli kagak!" << endl;
        return 0;
    }

    // TIKET
    do {
        cout << "Berapa jumlah tiket yang ingin dipesan? ";
        cin >> jumlah_tiket;

        if (jumlah_tiket < 1) {
            cout << "Harap memasukkan tiket lebih/sama dari 1" << endl;
        } else {
            total_tiket = jumlah_tiket * 35000;
            cout << endl
                 << "============================" << endl;
            cout << "Total tiket adalah " << total_tiket << endl;
            cout << "============================" << endl
                 << endl;
            cout << "Konfirmasi? (Y/N) ";
            cin >> konfirmasi;

            cout << endl;
        }
    } while (jumlah_tiket < 1 || (konfirmasi == 'N' || konfirmasi == 'n'));

    // POPCORN
    cout << "Apakah anda ingin memesan popcorn sekalian? (Y/N) ";
    cin >> opsi;

    if (opsi == 'Y' || opsi == 'y') {
        do {
            cout << "Berapa jumlah popcorn yang ingin dipesan? ";
            cin >> jumlah_popcorn;

            if (jumlah_popcorn < 1) {
                cout << "Harap memasukkan popcorn sama atau lebih dari 1" << endl;
            } else {
                total_popcorn = jumlah_popcorn * 30000;
                cout << endl
                     << "============================" << endl;
                cout << "Total popcorn adalah " << total_popcorn << endl;
                cout << "============================" << endl
                     << endl;
                cout << "Konfirmasi? (Y/N) ";
                cin >> konfirmasi;
                cout << endl;
            }

        } while (jumlah_popcorn < 1 || (konfirmasi == 'N' || konfirmasi == 'n'));
    }

    cout << "Jumlah tiket yang dipesan adalah           : " << jumlah_tiket << endl;
    cout << "Total harga tiket yang dipesan adalah      : " << total_tiket << endl;
    cout << "Total popcorn yang dipesan adalah          : " << jumlah_popcorn << endl;
    cout << "Total harga popcorn yang dipesan adalah    : " << total_popcorn << endl;

    return 0;
}
