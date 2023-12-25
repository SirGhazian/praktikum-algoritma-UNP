#include <iostream>
using namespace std;

int main() {
    float angka1, angka2, angka3;

    cout << "  ========================================" << endl;
    cout << "  ||   Program mencari angka terbesar   ||" << endl;
    cout << "  ||   dari tiga angka yang diurutkan   ||" << endl;
    cout << "  ========================================" << endl
         << endl;

    cout << "-> Masukkan angka ke-(1) yang ingin disortir: ";
    cin >> angka1;
    cout << "-> Masukkan angka ke-(2) yang ingin disortir: ";
    cin >> angka2;
    cout << "-> Masukkan angka ke-(3) yang ingin disortir: ";
    cin >> angka3;

    cout << endl;
    cout << "============================ HASIL ============================" << endl;

    if (angka1 >= angka2 && angka1 >= angka3)  // terbesar adalah bilangan-1
    {
        cout << "Yang terbesar menurut angka-angka yang diinput adalah angka " << angka1 << endl;
        if (angka2 >= angka3) {
            cout << "Diikuti dengan angka " << angka2 << " dan " << angka3 << endl;
        } else {
            cout << "Diikuti dengan angka " << angka3 << " dan " << angka2 << endl;
        }
    } else if (angka2 >= angka1 && angka2 >= angka3)  // terbesar adalah bilangan-2
    {
        cout << "Yang terbesar menurut angka-angka yang diinput adalah angka " << angka2 << endl;
        if (angka1 >= angka3) {
            cout << "Diikuti dengan angka " << angka1 << " dan " << angka3 << endl;
        } else {
            cout << "Diikuti dengan angka " << angka3 << " dan " << angka1 << endl;
        }
    } else  // terbesar adalah bilangan-3
    {
        cout << "Yang terbesar menurut angka-angka yang diinput adalah angka " << angka3 << endl;
        if (angka1 >= angka2) {
            cout << "Diikuti dengan angka " << angka1 << " dan " << angka2 << endl;
        } else {
            cout << "Diikuti dengan angka " << angka2 << " dan " << angka1 << endl;
        }
    }

    cout << "===============================================================" << endl;
    cout << endl;

    return 0;
}
