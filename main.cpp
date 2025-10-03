#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------------- Book Class ----------------
class Book {
private:
    int ID;
    string TITLE;
    string AUTHOR;
    int YEAR;
    int TOTAL_COPIES;
    int AVAILABLE_COPIES;

public:
    Book(int id, string title, string author, int year, int totalCopies)
        : ID(id), TITLE(title), AUTHOR(author), YEAR(year), TOTAL_COPIES(totalCopies), AVAILABLE_COPIES(totalCopies) {}

    string getTitle() const { return TITLE; }
    string getAuthor() const { return AUTHOR; }
    int getYear() const { return YEAR; }
    int getId() const { return ID; }
    int getAvailableCopies() const { return AVAILABLE_COPIES; }

    bool borrowBook() {
        if (AVAILABLE_COPIES > 0) {
            AVAILABLE_COPIES--;
            return true;
        }
        return false;
    }

    void returnBook() {
        if (AVAILABLE_COPIES < TOTAL_COPIES) AVAILABLE_COPIES++;
    }

    void displayBook() const {
        cout << "ID: " << ID
             << ", Title: " << TITLE
             << ", Author: " << AUTHOR
             << ", Year: " << YEAR
             << ", Available Copies: " << AVAILABLE_COPIES << "/" << TOTAL_COPIES
             << endl;
    }
};

// ---------------- User Class ----------------
class User {
private:
    int ID;
    string NAME;
    int BORROW_LIMIT;
    vector<int> BORROWED_BOOKS; // store book IDs

public:
    User(int id, string name, int borrowLimit = 3)
        : ID(id), NAME(name), BORROW_LIMIT(borrowLimit) {}

    int getId() const { return ID; }
    string getName() const { return NAME; }

    bool canBorrow() const { return BORROWED_BOOKS.size() < BORROW_LIMIT; }

    void borrowBook(int bookId) { BORROWED_BOOKS.push_back(bookId); }

    void returnBook(int bookId) {
        for (auto it = BORROWED_BOOKS.begin(); it != BORROWED_BOOKS.end(); ++it) {
            if (*it == bookId) {
                BORROWED_BOOKS.erase(it);
                break;
            }
        }
    }

    void displayUser() const {
        cout << "ID: " << ID
             << ", Name: " << NAME
             << ", Borrowed Books: " << BORROWED_BOOKS.size() << endl;
    }
};

// ---------------- Library Class ----------------
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(int id, string title, string author, int year, int totalCopies) {
        books.push_back(Book(id, title, author, year, totalCopies));
        cout << "Book \"" << title << "\" added successfully.\n";
    }

    void addUser(int id, string name) {
        users.push_back(User(id, name));
        cout << "User \"" << name << "\" added successfully.\n";
    }

    void searchByTitle(const string &title) {
        bool found = false;
        for (const auto &b : books) {
            if (b.getTitle() == title) {
                b.displayBook();
                found = true;
            }
        }
        if (!found) cout << "No book found with title \"" << title << "\".\n";
    }

    void searchByAuthor(const string &author) {
        bool found = false;
        for (const auto &b : books) {
            if (b.getAuthor() == author) {
                b.displayBook();
                found = true;
            }
        }
        if (!found) cout << "No book found by author \"" << author << "\".\n";
    }

    void searchByYear(int year) {
        bool found = false;
        for (const auto &b : books) {
            if (b.getYear() == year) {
                b.displayBook();
                found = true;
            }
        }
        if (!found) cout << "No book found from year " << year << ".\n";
    }

    void borrowBook(int userId, int bookId) {
        for (auto &u : users) {
            if (u.getId() == userId) {
                for (auto &b : books) {
                    if (b.getId() == bookId) {
                        if (u.canBorrow() && b.borrowBook()) {
                            u.borrowBook(bookId);
                            cout << u.getName() << " borrowed \"" << b.getTitle() << "\" successfully.\n";
                            return;
                        } else {
                            cout << "Borrow failed: Either no copies left or borrow limit reached.\n";
                            return;
                        }
                    }
                }
            }
        }
        cout << "Borrow failed: User or Book not found.\n";
    }

    void returnBook(int userId, int bookId) {
        for (auto &u : users) {
            if (u.getId() == userId) {
                for (auto &b : books) {
                    if (b.getId() == bookId) {
                        u.returnBook(bookId);
                        b.returnBook();
                        cout << u.getName() << " returned \"" << b.getTitle() << "\" successfully.\n";
                        return;
                    }
                }
            }
        }
        cout << "Return failed: User or Book not found.\n";
    }

    void showBooks() {
        cout << "\n--- Library Books ---\n";
        for (const auto &b : books) {
            b.displayBook();
        }
    }

    void showUsers() {
        cout << "\n--- Registered Users ---\n";
        for (const auto &u : users) {
            u.displayUser();
        }
    }
};

// ---------------- Main ----------------
int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add User\n";
        cout << "3. Show Books\n";
        cout << "4. Show Users\n";
        cout << "5. Search Book by Title\n";
        cout << "6. Search Book by Author\n";
        cout << "7. Search Book by Year\n";
        cout << "8. Borrow Book\n";
        cout << "9. Return Book\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, year, copies;
            string title, author;
            cout << "Enter Book ID, Title, Author, Year, Total Copies: ";
            cin >> id >> title >> author >> year >> copies;
            library.addBook(id, title, author, year, copies);
            break;
        }
        case 2: {
            int id;
            string name;
            cout << "Enter User ID and Name: ";
            cin >> id >> name;
            library.addUser(id, name);
            break;
        }
        case 3:
            library.showBooks();
            break;
        case 4:
            library.showUsers();
            break;
        case 5: {
            string title;
            cout << "Enter Title: ";
            cin >> title;
            library.searchByTitle(title);
            break;
        }
        case 6: {
            string author;
            cout << "Enter Author: ";
            cin >> author;
            library.searchByAuthor(author);
            break;
        }
        case 7: {
            int year;
            cout << "Enter Year: ";
            cin >> year;
            library.searchByYear(year);
            break;
        }
        case 8: {
            int userId, bookId;
            cout << "Enter User ID and Book ID: ";
            cin >> userId >> bookId;
            library.borrowBook(userId, bookId);
            break;
        }
        case 9: {
            int userId, bookId;
            cout << "Enter User ID and Book ID: ";
            cin >> userId >> bookId;
            library.returnBook(userId, bookId);
            break;
        }
        case 0:
            cout << "Exiting system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
