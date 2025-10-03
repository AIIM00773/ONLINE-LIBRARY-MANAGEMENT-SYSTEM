# ONLINE-LIBRARY-MANAGEMENT-SYSTEM
a simple library management system in c++

LIBRARY MANAGEMENT SYSTEM  

This is a simple C++ Library Management System that allows users to manage books and library members.  
It supports adding, searching, borrowing, and returning books, as well as managing users.


# Classes Used

1. Book
- Why: Represents each book in the library.  
- Attributes: id, title, author, year, totalCopies, availableCopies.  
- Key Methods:
  - displayBook() → Shows book details.
  - borrowBook() / returnBook() → Handles availability.

2. User
- Why: Represents each registered library user.  
- Attributes: id, name, borrowLimit, borrowedBooks.  
- Key Methods:
  - displayUser() → Shows user details.
  - borrowBook() / returnBook() → Tracks borrowed books.

3. Library
- Why: Acts as the controller for books and users.  
- Attributes: vector<Book> books, vector<User> users.  
- Key Methods:
  - addBook(), addUser().
  - searchByTitle(), searchByAuthor(), searchByYear().
  - borrowBook(), returnBook().
  - showBooks(), showUsers().

---

## How to Compile and Run


g++ -std=c++11 main.cpp -o main      


Run:
    ./library

