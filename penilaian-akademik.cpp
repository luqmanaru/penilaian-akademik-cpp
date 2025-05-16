#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// Struktur Mahasiswa
struct Mhs {
    string nim;
    string nama;
    int nilai;
};

// Fungsi untuk menentukan grade berdasarkan nilai
char grades(int n) {
    if (n > 85) return 'A';
    else if (n > 75) return 'B';
    else if (n > 65) return 'C';
    else if (n > 45) return 'D';
    else return 'E';
}

int main() {
    int jml;
    char ulang;

    // Waktu saat ini
    time_t t = time(0);
    tm* now = localtime(&t);

    cout << "REPORT NILAI MAHASISWA PERTANGGAL "
         << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900)
         << endl;

input_ulang:
    cout << "\nMasukkan jumlah Mahasiswa yang ingin diinput : ";
    cin >> jml;

    Mhs mahasiswa[jml];
    cout << "\nSilakan input " << jml << " data nilai Mahasiswa\n";

    for (int i = 0; i < jml; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "NIM\t: ";
        cin >> mahasiswa[i].nim;
        cin.ignore();
        cout << "Nama\t: ";
        getline(cin, mahasiswa[i].nama);
        cout << "Nilai\t: ";
        cin >> mahasiswa[i].nilai;
    }

    // Header tabel
    cout << "\n===================================================" << endl;
    cout << "|    NIM    |      NAMA      |  NILAI  | GRADES  |" << endl;
    cout << "===================================================" << endl;

    // Menampilkan data
    for (int i = 0; i < jml; i++) {
        cout << "| " << mahasiswa[i].nim
             << " | " << mahasiswa[i].nama
             << " |   " << mahasiswa[i].nilai
             << "   |    " << grades(mahasiswa[i].nilai)
             << "     |" << endl;
    }

    cout << "---------------------------------------------------\n";
    cout << "Mau input data lagi? [Y/T] : ";
    cin >> ulang;
    if (ulang == 'y' || ulang == 'Y') {
        goto input_ulang;
    }

    return 0;
}
