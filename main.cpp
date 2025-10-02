#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= Book Class =================
class Book {
private:
    int id;
    string title;
    string author;
    int year;
    int totalCopies;
    int availableCopies;

public:
    // Constructor
    Book(int id, string title, string author, int year, int totalCopies)
        : id(id), title(title), author(author), year(year),
          totalCopies(totalCopies), availableCopies(totalCopies) {}

    // Getters
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    int getAvailableCopies() const { return availableCopies; }

    // Borrow and return
    bool borrowBook() {
        if (availableCopies > 0) {
            availableCopies--;
            return true;
        }
        return false;
    }

    void returnBook() {
        if (availableCopies < totalCopies)
            availableCopies++;
    }

    void displayBook() const {
        cout << "ID: " << id << " | Title: " << title << " | Author: " << author
             << " | Year: " << year
             << " | Available: " << availableCopies << "/" << totalCopies << endl;
    }
};

// ================= User Class =================
class User {
private:
    int id;
    string name;
    int borrowLimit;
    vector<int> borrowedBooks; // store book IDs

public:
    User(int id, string name, int borrowLimit = 3)
        : id(id), name(name), borrowLimit(borrowLimit) {}

    int getId() const { return id; }
    string getName() const { return name; }

    bool canBorrow() const {
        return borrowedBooks.size() < borrowLimit;
    }

    void borrowBook(int bookId) {
        borrowedBooks.push_back(bookId);
    }

    void returnBook(int bookId) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (*it == bookId) {
                borrowedBooks.erase(it);
                break;
            }
        }
    }

    void displayUser() const {
        cout << "User ID: " << id << " | Name: " << name
             << " | Borrowed: " << borrowedBooks.size() << "/" << borrowLimit << endl;
    }
};

// ================= Library Class =================
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    // Add a new book
    void addBook(Book book) {
        books.push_back(book);
    }

    // List all books
    void listBooks() const {
        cout << "\n=== Books in Library ===" << endl;
        for (const auto &book : books)
            book.displayBook();
    }

    // Add a new user
    void addUser(User user) {
        users.push_back(user);
    }

    // List all users
    void listUsers() const {
        cout << "\n=== Users in Library ===" << endl;
        for (const auto &user : users)
            user.displayUser();
    }

    // Search books by title
    void searchByTitle(string title) const {
        cout << "\nSearch Results for title \"" << title << "\":" << endl;
        for (const auto &book : books) {
            if (book.getTitle() == title)
                book.displayBook();
        }
    }

    // Borrow a book
    void borrowBook(int userId, int bookId) {
        for (auto &user : users) {
            if (user.getId() == userId) {
                if (!user.canBorrow()) {
                    cout << "User has reached borrow limit!" << endl;
                    return;
                }

                for (auto &book : books) {
                    if (book.getId() == bookId) {
                        if (book.borrowBook()) {
                            user.borrowBook(bookId);
                            cout << user.getName() << " borrowed " << book.getTitle() << endl;
                        } else {
                            cout << "Book not available!" << endl;
                        }
                        return;
                    }
                }
            }
        }
        cout << "User or Book not found!" << endl;
    }

    // Return a book
    void returnBook(int userId, int bookId) {
        for (auto &user : users) {
            if (user.getId() == userId) {
                user.returnBook(bookId);
                for (auto &book : books) {
                    if (book.getId() == bookId) {
                        book.returnBook();
                        cout << user.getName() << " returned " << book.getTitle() << endl;
                        return;
                    }
                }
            }
        }
        cout << "User or Book not found!" << endl;
    }
};

// ================= Main Function =================
int main() {
    Library lib;

    // Add some books
    lib.addBook(Book(1, "C++ Basics", "Bjarne", 2013, 3));
    lib.addBook(Book(2, "OOP in C++", "Stroustrup", 2017, 2));

    // Add some users
    lib.addUser(User(101, "Alice"));
    lib.addUser(User(102, "Bob"));

    // List everything
    lib.listBooks();
    lib.listUsers();

    // Borrowing
    lib.borrowBook(101, 1); // Alice borrows book ID 1
    lib.borrowBook(102, 2); // Bob borrows book ID 2

    // List after borrow
    lib.listBooks();

    // Returning
    lib.returnBook(101, 1);

    // Search book
    lib.searchByTitle("C++ Basics");

    return 0;
}


