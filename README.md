# 📚 Library Management System (C++)

A CLI-based Library Management System built using C++ to manage books with features like insert, display, modify, and delete. Data is stored in a binary file (`Books.dat`) using file I/O.

## 🔧 Features
- Add new book records
- View all or specific book details
- Modify book information
- Delete records by Book ID
- Persistent storage using binary files
- Demonstrates Object-Oriented Programming and File Handling

## 🛠 Technologies Used
- C++ (OOP, file I/O, pointers)
- Windows-only dependency: `conio.h` (`getch()` for pause)

## 📂 Structure
- `Books.dat`: Binary file storing book records
- `Books` class: Encapsulates all logic
- Menu-driven interface via `main()`

## 🚀 Getting Started
1. Compile using any C++ compiler (e.g. g++, Dev C++)
2. Run the executable
3. Use on-screen menu options to manage books

```bash
g++ LibrarySystem.cpp -o LibrarySystem
./LibrarySystem
```

## 📌 Note
- This project is a basic implementation intended for learning purposes. Enhancements like dynamic memory, exception handling, or database integration are possible next steps.
