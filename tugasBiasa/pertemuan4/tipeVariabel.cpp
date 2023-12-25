#include <math.h>

#include <iostream>
using namespace std;

int main() {
    string nama, alamat, jenisKelamin;
    int usia, tinggi, berat;

    nama = "Ghazian Tza";
    alamat = "Jalan Wakanda No, 7";
    jenisKelamin = "Laki-laki";

    usia = 25;
    tinggi = 168;
    berat = 55;

    cout << "Halo tuan, " << nama << "!" << endl;
    cout << "Anda bertempat tinggal di " << alamat << endl;
    cout << "Anda berjenis kelamin " << jenisKelamin << endl;
    cout << "Umur " << nama << " adalah " << usia << " tahun" << endl;
    cout << "Tinggi " << nama << " adalah " << tinggi << endl;
    cout << nama << " memiliki berat " << berat << "Kg" << endl;

    return 0;
}
