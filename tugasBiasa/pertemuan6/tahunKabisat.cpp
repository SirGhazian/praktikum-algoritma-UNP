#include <iostream>
using namespace std;

int main() {
    int tahun;

    cout << "  ========================================" << endl;
    cout << "  ||   Program menentukan Tahun kabisat  ||" << endl;
    cout << "  ========================================" << endl
         << endl;

    cout << "Masukkan tahun yang ingin ditentukan: ";
    cin >> tahun;

    cout << "\nTahun yang diinnput adalah tahun " << tahun << endl;

    if (tahun % 4 == 0) {
        cout << "Tahun " << tahun << " merupakan tahun kabisat!";
    } else {
        cout << "Tahun " << tahun << " merupakan tahun tidak kabisat!";
    }

    cout << endl
         << endl;

    return 0;
}
