// Enhanced and corrected C++ Library Management System
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>  // Only works on Windows
using namespace std;

class Books {
    int Book_ID, Bprice, yop;
    char Bname[100], Bauthor[50], availability[5];

public:
    void input();
    void show();
    int getn() { return Book_ID; }
    void Insert();
    void Display();
    void DisplayP();
    void Modify();
    void Delete();
    void Create();
} b1;

fstream fil;

void Books::input() {
    cout << "Enter Book ID: ";
    cin >> Book_ID;
    cin.ignore();
    cout << "Enter book name: ";
    cin.getline(Bname, 100);
    cout << "Enter author's name: ";
    cin.getline(Bauthor, 50);
    cout << "Enter price of book: ";
    cin >> Bprice;
    cout << "Year of publication: ";
    cin >> yop;
    cout << "Available (yes/no): ";
    cin >> availability;
}

void Books::show() {
    cout << "\nBook ID: " << Book_ID
         << "\nBook's Name: " << Bname
         << "\nAuthor's Name: " << Bauthor
         << "\nPrice: " << Bprice
         << "\nYear of Publication: " << yop
         << "\nAvailability: " << availability << endl;
}

void BookIndex() {
    cout << "\nBooks available in bookstore:" << endl;
    cout << "1) Wuthering Heights by Emily Bronte (1847)\n"
         << "2) Pride and Prejudice by Jane Austen (1813)\n"
         << "3) A Tale Of Two Cities by Charles Dickens (1859)\n"
         << "4) Dead Souls by Nikolai Gogol (1842)\n"
         << "5) The Adventures of Tom Sawyer by Mark Twain (1878)\n"
         << "6) Jane Eyre by Charlotte Bronte (1847)\n"
         << "7) The Adventures of Sherlock Holmes by Arthur Conan Doyle (1892)\n"
         << "8) The Mayor of Casterbridge by Thomas Hardy (1886)\n"
         << "9) A Tale Of Two Cities by Charles Dickens (1859)\n"
         << "10) The Alchemist by Paulo Coelho (1988)" << endl;
}

void Books::Create() {
    char ch = 'y';
    fil.open("Books.dat", ios::out | ios::binary);
    while (ch == 'y' || ch == 'Y') {
        input();
        fil.write(reinterpret_cast<char*>(this), sizeof(*this));
        cout << "Want to continue? (y/n): ";
        cin >> ch;
    }
    fil.close();
}

void Books::Insert() {
    char ch = 'y';
    fil.open("Books.dat", ios::app | ios::binary);
    while (ch == 'y' || ch == 'Y') {
        input();
        fil.write(reinterpret_cast<char*>(this), sizeof(*this));
        cout << "Want to continue? (y/n): ";
        cin >> ch;
    }
    fil.close();
}

void Books::Display() {
    fil.open("Books.dat", ios::in | ios::binary);
    if (!fil) {
        cout << "File not found!" << endl;
        return;
    }
    while (fil.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        show();
        cout << "Press any key to continue..." << endl;
        getch();
    }
    fil.close();
}

void Books::DisplayP() {
    int n;
    cout << "Enter Book ID to search: ";
    cin >> n;
    bool found = false;
    fil.open("Books.dat", ios::in | ios::binary);
    if (!fil) {
        cout << "File not found!" << endl;
        return;
    }
    while (fil.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        if (n == getn()) {
            show();
            found = true;
            break;
        }
    }
    if (!found) cout << "Book not found." << endl;
    fil.close();
    getch();
}

void Books::Modify() {
    int n;
    cout << "Enter Book ID to modify: ";
    cin >> n;
    fil.open("Books.dat", ios::in | ios::out | ios::binary);
    if (!fil) {
        cout << "File not found!" << endl;
        return;
    }
    while (fil.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        if (n == getn()) {
            cout << "Enter new details:\n";
            input();
            int pos = -1 * static_cast<int>(sizeof(*this));
            fil.seekp(pos, ios::cur);
            fil.write(reinterpret_cast<char*>(this), sizeof(*this));
            break;
        }
    }
    fil.close();
}

void Books::Delete() {
    int n;
    cout << "Enter Book ID to delete: ";
    cin >> n;
    ofstream temp("temp.dat", ios::binary);
    fil.open("Books.dat", ios::in | ios::binary);
    if (!fil) {
        cout << "File not found!" << endl;
        return;
    }
    while (fil.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        if (n != getn()) {
            temp.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
    }
    fil.close();
    temp.close();
    remove("Books.dat");
    rename("temp.dat", "Books.dat");
}

int main() {
    int opt;
    cout << "\n\t\tCollinge and Clarke Library Management System" << endl;
    BookIndex();
    while (true) {
        cout << "\n\nMenu:\n"
             << "1. Create Data File\n"
             << "2. Insert New Record\n"
             << "3. Display All Records\n"
             << "4. Search Particular Record\n"
             << "5. Modify Record\n"
             << "6. Delete Record\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> opt;

        switch (opt) {
            case 1: b1.Create(); break;
            case 2: b1.Insert(); break;
            case 3: b1.Display(); break;
            case 4: b1.DisplayP(); break;
            case 5: b1.Modify(); break;
            case 6: b1.Delete(); break;
            case 7: exit(0);
            default: cout << "Invalid option!" << endl; getch();
        }
    }
    return 0;
}
