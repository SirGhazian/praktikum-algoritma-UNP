#include <math.h>

#include <iostream>
using namespace std;

int main() {
    float dana_bansos, dana_korupsi, total_korupsi, dana_kurang, persentase_korupsi;
    string nama_camat;

    cout << "Masukkan nama koruptor: ";
    cin >> nama_camat;

    cout << "Berapa jumlah dana bansos yang diturunkan oleh Bupati? ";
    cin >> dana_bansos;

    cout << "Berapa jumlah uang yang dikorupsi oleh " << nama_camat << " ? ";
    cin >> dana_korupsi;

    total_korupsi = dana_bansos - dana_korupsi;
    persentase_korupsi = ((dana_korupsi / dana_bansos) * 100);
    dana_kurang = dana_bansos - dana_korupsi;

    cout << endl
         << "======= BREAKING NEWS! =======" << endl
         << endl;

    cout << "Wakil Bupati Sumatra Barat telah menurunkan dana bansos untuk masyarakat sejumlah " << int(dana_bansos) << " Rupiah" << endl;
    cout << "Namun, seorang Camat yang bernama " << nama_camat << " melakukan tindak korupsi dana bansos yang diberikan sebesar " << int(total_korupsi) << " Rupiah" << endl;
    cout << "Atau sekitar " << int(persentase_korupsi) << "% dari total anggaran yang diberikan" << endl;
    cout << endl;
    cout << "Akibat perbuatannya, hanya tersisa " << int(total_korupsi) << " Rupiah yang dapat dibagikan kepada masyarakat" << endl;
    cout << nama_camat << " telah dicatat sebagai koruptor yang telah merugikan negara sekitar " << int(dana_korupsi) << " Rupiah";
    cout << endl;

    cout << endl
         << "==============================" << endl;

    return 0;
}
