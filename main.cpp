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

public:
    // Constructor
    Book(int id, string title, string author) {
        ID = id;
        TITLE = title;
        AUTHOR = author;
    }

    // Getters
    string getTitle() const { return TITLE; }
    string getAuthor() const { return AUTHOR; }
    int getId() const { return ID; }

    // Display book
    void displayBook() const {
        cout << "ID: " << ID 
             << ", Title: " << TITLE 
             << ", Author: " << AUTHOR << endl;
    }
};

// ---------------- User Class ----------------
class User {
private:
    int ID;
    string FIRSTNAME;
    string LASTNAME;

public:
    // Constructor
    User(int id, string first_name, string last_name) {
        ID = id;
        FIRSTNAME = first_name;
        LASTNAME = last_name;
    }

    void displayUser() const {
        cout << "ID: " << ID 
             << ", Name: " << FIRSTNAME << " " << LASTNAME << endl;
    }
};

// ---------------- Library Class ----------------
class Library {
public:
    vector<Book> books;
    vector<User> users;

    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "The book \"" << title << "\" by " << author 
             << " has been added successfully." << endl;
    }

    void addUser(int id, string first_name, string last_name) {
        users.push_back(User(id, first_name, last_name));
        cout << "The user " << first_name << " " << last_name 
             << " has been added successfully." << endl;
    }

    // Search book by title
    void searchByTitle(const string &title) {
        bool found = false;
        for (const auto &b : books) {
            if (b.getTitle() == title) {
                cout << "Book found: ";
                b.displayBook();
                found = true;
            }
        }
        if (!found) cout << "No book found with title \"" << title << "\"." << endl;
    }

    // Search book by author
    void searchByAuthor(const string &author) {
        bool found = false;
        for (const auto &b : books) {
            if (b.getAuthor() == author) {
                cout << "Book found: ";
                b.displayBook();
                found = true;
            }
        }
        if (!found) cout << "No book found by author \"" << author << "\"." << endl;
    }

    // Show all books
    void showBooks() {
        cout << "\nLibrary Books:" << endl;
        for (const auto &b : books) {
            b.displayBook();
        }
    }

    // Show all users
    void showUsers() {
        cout << "\nRegistered Users:" << endl;
        for (const auto &u : users) {
            u.displayUser();
        }
    }
};

// ---------------- Main ----------------
int main() {
    Library library;

    library.addBook(1, "Title1", "Author1");
    library.addBook(2, "Title2", "Author2");
    library.addUser(1, "Fredrick", "Owino");

    library.showBooks();
    library.showUsers();

    cout << "\nSearching for 'Title1'..." << endl;
    library.searchByTitle("Title1");

    cout << "\nSearching for books by 'Author2'..." << endl;
    library.searchByAuthor("Author2");

    return 0;
}

