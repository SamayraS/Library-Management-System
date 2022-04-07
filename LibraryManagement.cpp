#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class Books
{
    int Book_ID, Bprice, yop;
    char Bname[100], Bauthor[50], availability[5];

public:
    void input();
    void show();
    int getn()
    {
        return Book_ID;
    }
    void Insert();
    void Display();
    void DisplayP();
    void Modify();
    void Delete();
    void Create();
} b1;

void Books::input()
{
    cout << "Enter Book ID:";
    cin >> Book_ID;
    cout << "\nEnter book name:";
    gets(Bname);
    cout << "\nEnter author's name:";
    gets(Bauthor);
    cout << "\nEnter price of book:";
    cin >> Bprice;
    cout << "\nYear of publication:";
    cin >> yop;
    cout << "\nAvailable (y/n):";
    cin >> availability;
}
void Books::show()
{
    cout << "\nBook ID:" << Book_ID << endl;
    cout << "\nBook's Name:" << Bname << endl;
    cout << "\nAuthor's Name:" << Bauthor << endl;
    cout << "\nPrice:" << Bprice;
    cout << "\nYear of Publication:" << yop;
}

void BookIndex()
{
    cout << "\nThe books available in bookstore are:";
    cout << "\n1) Wuthering Heights by Emily Bronte (1847)";
    cout << "\n2) Pride and Prejudice by Jane Austen (1813)";
    cout << "\n3) A Tale Of Two Cities by Charles Dickens (1859)";
    cout << "\n4) 19 Dead Souls by Nikolai Gogol (1842)";
    cout << "\n5) The Adventures of Tom Sawyer by Mark Twain (1878)";
    cout << "\n6) Jane Eyre by Charlotte Bronte (1847)";
    cout << "\n7) The Adventures of Sherlock Holmes by Arthur Conan Doyle (1892)";
    cout << "\n8) The Mayor of Casterbridge by Tom Hardy (1886)";
    cout << "\n9) A Tale Of Two Cities by Charles Dickens (1859)";
    cout << "\n10) The Alchemist by Paulo Coehlo (1988)";
}
fstream fil;
void Books::Create()
{
    char ch;
    fil.open("Books.dat", ios::out | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        b1.input();
        fil.write((char *)&b1, sizeof(b1));
        cout << "Want to Continue?? (y/n)";
        cin >> ch;
    }
    fil.close();
}

void Books::Insert()
{
    char ch = 'y';
    fil.open("Books.dat", ios::app | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        b1.input();
        fil.write((char *)&b1, sizeof(b1));
        cout << "Want to Continue?? (y/n)";
        cin >> ch;
    }
    fil.close();
}

void Books::Display()
{
    fil.open("Books.dat", ios::in | ios::binary);
    if (!fil)
    {
        cout << "File not Found";
        exit(0);
    }
    else
    {
        fil.read((char *)&b1, sizeof(b1));
        while (!fil.eof())
        {
            b1.show();
            cout << "Press Any Key to go to next record" << endl;
            getch();
            fil.read((char *)&b1, sizeof(b1));
        }
    }
    fil.close();
}

void Books::DisplayP()
{
    int n;
    cout << "Enter BookID that should be searched:";
    cin >> n;
    fil.open("Books.dat", ios::in | ios::binary);
    if (!fil)
    {
        cout << "File not Found";
        exit(0);
    }
    else
    {
        fil.read((char *)&b1, sizeof(b1));
        while (!fil.eof())
        {
            if (n == b1.getn())
            {
                b1.show();
                cout << "Press Any Key...." << endl;
                getch();
            }
            else
            {
                cout << "Press Any Key t Search" << endl;
                getch();
            }
            fil.read((char *)&b1, sizeof(b1));
        }
    }
    fil.close();
}
void Books::Modify()
{
    int n;
    cout << "Enter Name that should be searched:";
    cin >> n;
    fil.open("Books.dat", ios::in | ios::out | ios::binary);
    if (!fil)
    {
        cout << "File not Found!";
        exit(0);
    }
    else
    {
        fil.read((char *)&b1, sizeof(b1)
        while (!fil.eof())
        {
            if (n == b1.getn())
            {
                fil.seekg(0, ios::cur);
                cout << "Enter New Record.." << endl;
                b1.input();
                fil.seekp(fil.tellg() - sizeof(b1));
                fil.write((char *)&b1, sizeof(b1));
            }
            else
            {
                cout << "Press any key to search" << endl;
                getch();
            }
            fil.read((char *)&b1, sizeof(b1));
        }
    }
    fil.close();
}

void Books::Delete()
{
    int n;
    cout << "Enter Name that should be Deleted :";
    cin >> n;
    ofstream o;
    o.open("new.dat", ios::out | ios::binary);
    fil.open("Books.dat", ios::in | ios::binary);
    if (!fil)
    {
        cout << "File not Found";
        exit(0);
    }
    else
    {
        fil.read((char *)&b1, sizeof(b1));
        while (!fil.eof())
        {
            if (n != b1.getn())
            {
                o.write((char *)&b1, sizeof(b1));
            }
            else
            {
                cout << "Press any key to search" << endl;
                getch();
            }
            fil.read((char *)&b1, sizeof(b1));
        }
    }
    o.close();
    fil.close();
    remove("Books.dat");
    rename("new.dat", "binary.dat");
    fstream fil;
}
int main()
{
    cout << "\n              Collinge and Clarke";
    BookIndex();
    {
        
        int opt;
        while (1)
        {
            cout << "1.Create Data File" << endl;
            cout << "2.Insert New Record in File" << endl;
            cout << "3.Display Record From File" << endl;
            cout << "4.Display Particular Record From file" << endl;
            cout << "5.Modify Particular Record From File" << endl;
            cout << "6.Delete Particular Record From File" << endl;
            cout << "7.Exit From the Program" << endl;
            cout << "Enter your Option : " << endl;
            cin >> opt;
            switch (opt)
            {
            case 1:
            {
                void Create();
                cout << "Display Main Menu" << endl;
                getch();
                break;
            }
            case 2:
            {
                b1.Insert();
                cout << "To insert new record:" << endl;
                getch();
                break;
            }
            case 3:
            {
                b1.Display();
                cout << "To display the file:" << endl;
                getch();
                break;
            }
            case 4:
            {
                b1.DisplayP();
                cout << "To display a particular file:" << endl;
                getch();
                break;
            }
            case 5:
            {
                b1.Modify();
                cout << "To modify the file:" << endl;
                getch();
                break;
            }
            case 6:
            {
                b1.Delete();
                cout << "To delete a record from file:" << endl;
                getch();
                break;
            }
            case 7:
            {
                exit(0);
            }
            default:
            {
                cout << "Wrong Choice!! Press Key For View the Main Menu";
                getch();
            }
            }
        }
    }
};