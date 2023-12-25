#include <iostream>
using namespace std;

int main() {
    int umur;

    cout << "\nBerapa usiamu? ";
    cin >> umur;

    cout << "\n ==== Result ====" << endl;
    cout << "Kamu berumur " << umur << " Tahun" << endl;

    if (umur > 18)  // umur diatas 18
    {
        cout << "Kamu sudah dikategorikan sebagai orang dewasa" << endl;
        cout << "Selamat menjalani dunia yang keras kedepannya~" << endl;
    } else if (umur < 18)  // umur dibawah 18
    {
        cout << "Sayang sekali... kamu belum bisa dikategorikan sebagai orang dewasa" << endl;
        cout << "Manfaatkan momen-momen bahagia sebelum kamu masuk ke dalam dunia dewasa yang keras :)" << endl;
    } else  // umur = 18
    {
        cout << "Saat ini kamu masih dikategorikan sebagai anak-anak" << endl;
        cout << "Sabar, satu tahun lagi kamu akan dikategorikan sebagai orang dewasa!" << endl;
    }

    cout << endl;

    return 0;
}
