#include <iostream>
#include <string>

using namespace std;

struct Book {
    string Judul;
    string Penulis;
    bool StatusBuku;
};

void addBook(Book library[], const string& Judul, const string& Penulis, int& size) {
    library[size] = {Judul, Penulis, false};
    size++;
}

void checkOutBook(Book library[], int size, const string& Judul) {
    for (int i = 0; i < size; ++i) {
        if (library[i].Judul == Judul) {
            if (!library[i].StatusBuku) {
                library[i].StatusBuku = true;
                cout << "Buku \"" << Judul << "\" Berhasil Di Pinjam" << endl;
            } else {
                cout << "Buku \"" << Judul << "\" Sedang Di Pinjam" << endl;
            }
            return;
        }
    }
    cout << "Buku \"" << Judul << "\" Tidak Di Temukan" << endl;
}

void checkInBook(Book library[], int size, const string& Judul) {
    for (int i = 0; i < size; ++i) {
        if (library[i].Judul == Judul) {
            if (library[i].StatusBuku) {
                library[i].StatusBuku = false;
                cout << "Buku \"" << Judul << "\" Telah Di Tambahkan" << endl;
            } else {
                cout << "Buku \"" << Judul << "\" Telah Tersedia" << endl;
            }
            return;
        }
    }
}

void checkListBook(Book library[], int size){
    if (size != 0){
        for (int i = 0; i < size; i++){
            cout << "Judul : " << library[i].Judul << endl;
            cout << "Penulis : " << library[i].Penulis << endl;
            cout << "--------------------" << endl;
        }
    }else{
        cout << "Tidak Ada Buku Yang Tersedia";
    }
}


int main() {
    const int MAX_LIBRARY_SIZE = 100;
    Book library[MAX_LIBRARY_SIZE];
    int librarySize = 0;

    addBook(library, "1984", "George Orwell", librarySize);
    addBook(library, "To Kill a Mockingbird", "Harper Lee", librarySize);
    addBook(library, "The Catcher in the Rye", "J.D. Salinger", librarySize);

    checkOutBook(library, librarySize, "1984");

    checkOutBook(library, librarySize, "1984");

    checkOutBook(library, librarySize, "19845");

    checkInBook(library, librarySize, "1984");

    checkInBook(library, librarySize, "1984");

    checkListBook(library, librarySize);
    return 0;
}
