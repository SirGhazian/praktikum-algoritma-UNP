#include <iostream>
using namespace std;

int main() {
    float suhu;

    cout << "\n  ============================================" << endl;
    cout << "  ||   Program menentukan suatu wujud air   ||" << endl;
    cout << "  ============================================" << endl
         << endl;

    cout << "Masukkan suhu dalam Celcius: ";
    cin >> suhu;

    cout << endl;
    cout << "Suhu air yang diinput " << suhu << " Celcius" << endl;

    if (suhu <= 0) {
        cout << "Wujud air berupa es";
    } else if (0 < suhu && suhu < 100) {
        cout << "Wujud air berupa cairan";
    } else {
        cout << "Wujud air berupa uap";
    }

    cout << endl
         << endl;

    return 0;
}
