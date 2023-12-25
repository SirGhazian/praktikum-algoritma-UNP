#include <iostream>
using namespace std;

int main()
{
    int tanggal, nomor_bulan;
    string bulan;

    cout << "\n  ==================================" << endl;
    cout << "  ||   TENTUKAN ZODIAKMU DISINI!   ||" << endl;
    cout << "  ===================================" << endl
         << endl;

    cout << "Masukkan tanggal dan bulan lahirmu! (Misal: 5 januari)" << endl;
    cin >> tanggal >> bulan;

    cout << endl
         << endl;

    cout << "Kamu lahir tanggal " << tanggal << " di bulan " << bulan << endl;

    if (((22 <= tanggal && tanggal <= 31 && bulan == "desember") || ((1 <= tanggal && tanggal <= 19) && bulan == "januari")))
    {
        cout << "Kamu adalah Capicorn!";
    }
    else if (((20 <= tanggal && tanggal <= 31) && bulan == "januari") || ((1 <= tanggal && tanggal <= 18) && bulan == "februari"))
    {
        cout << "Kamu adalah Aquarius!";
    }
    else if (((19 <= tanggal && tanggal <= 28) && bulan == "februari") || ((1 <= tanggal && tanggal <= 20) && bulan == "maret"))
    {
        cout << "Kamu adalah Pisces!";
    }
    else if (((21 <= tanggal && tanggal <= 31) && bulan == "maret") || ((1 <= tanggal && tanggal <= 19) && bulan == "april"))
    {
        cout << "Kamu adalah Aries!";
    }
    else if (((20 <= tanggal && tanggal <= 30) && bulan == "april") || ((1 <= tanggal && tanggal <= 20) && bulan == "mei"))
    {
        cout << "Kamu adalah Taurus!";
    }
    else if (((21 <= tanggal && tanggal <= 31) && bulan == "mei") || ((1 <= tanggal && tanggal <= 20) && bulan == "juni"))
    {
        cout << "Kamu adalah Gemini!";
    }
    else if (((21 <= tanggal && tanggal <= 30) && bulan == "juni") || ((1 <= tanggal && tanggal <= 22) && bulan == "juli"))
    {
        cout << "Kamu adalah Cancer!";
    }
    else if (((23 <= tanggal && tanggal <= 31) && bulan == "juli") || ((1 <= tanggal && tanggal <= 22) && bulan == "agustus"))
    {
        cout << "Kamu adalah Leo!";
    }
    else if (((23 <= tanggal && tanggal <= 31) && bulan == "agustus") || ((1 <= tanggal && tanggal <= 22) && bulan == "september"))
    {
        cout << "Kamu adalah Virgo!";
    }
    else if (((22 <= tanggal && tanggal <= 30) && bulan == "september") || ((1 <= tanggal && tanggal <= 23) && bulan == "oktober"))
    {
        cout << "Kamu adalah Libra!";
    }
    else if (((24 <= tanggal && tanggal <= 31) && bulan == "oktober") || ((1 <= tanggal && tanggal <= 21) && bulan == "november"))
    {
        cout << "Kamu adalah Scorpio!";
    }
    else if (((22 <= tanggal && tanggal <= 30) && bulan == "november") || ((1 <= tanggal && tanggal <= 21) && bulan == "desember"))
    {
        cout << "Kamu adalah Sagittarius!";
    }
    else
    {
        cout << "Tanggal tidak valid, cobalah untuk tidak menggunakan huruf kapital!";
    }

    cout << endl
         << endl;

    return 0;
}
