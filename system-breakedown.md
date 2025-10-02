

What is Required

Task :**build an Online Library Management System in C++** using **Object-Oriented Programming (OOP)**


Key requirements:

1. Classes: Create classes for main entities:

   *Book
   *User
   *Library
   
2. Encapsulation of data + behavior → Each class should keep its data private and expose methods for actions.
3. Functionalities:

   * Add and remove books.
   * Search for books (by title, author, year, etc.).
   * Manage users (add/remove).
   * Borrow and return books.
   
4. Test cases: Write positive and negative tests (e.g., borrow a book successfully, borrow a book with no copies left, return a book not borrowed, etc.).
5. Documentation: Explain your design and how to compile/run tests.
6. Submission: Upload your code to GitHub and share the link.

---



STEPS TO FOLLOW



Step 1: Identify Entities

**Book** → attributes: `id`, `title`, `author`, `year`, `totalCopies`, `availableCopies`.
**User** → attributes: `id`, `name`, `borrowedBooks`.
**Library** → manages all books and users.


Step 2: Define Classes

* Write C++ classes for `Book`, `User`, and `Library`.
* Use **private attributes** + **public methods** (e.g., `borrowBook()`, `returnBook()`).


Step 3: Implement Functionalities

Inside `Library`:

**Book Management**: `addBook()`, `removeBook()`.

**User Management**: `addUser()`, `removeUser()`.

**Search**: `searchByTitle()`, `searchByAuthor()`, `searchByYear()`.

**Borrow/Return**: `borrowBook(userId, bookId)`, `returnBook(userId, bookId)`.



Step 4: Write Tests

* Positive test: Add a user → should succeed.
* Negative test: Add same user twice → should fail.
* Borrow a book → success if available, fail if not.
* Return a book → success if borrowed, fail otherwise.


Step 5: Document & Submit

* Write a short `README.md` explaining:

  * What classes you used and why.
  * How to compile and run (`g++ ...`).
  * Examples of test results.

---

System Flow (Tree)

A **tree diagram** of the system:

```
Library Management System
│
├── Library
│   ├── manages → Books
│   │   ├── addBook()
│   │   ├── removeBook()
│   │   ├── searchByTitle()
│   │   ├── searchByAuthor()
│   │   └── searchByYear()
│   │
│   ├── manages → Users
│   │   ├── addUser()
│   │   ├── removeUser()
│   │   ├── borrowBook()
│   │   └── returnBook()
│   │
│   └── storage
│       ├── vector<Book>
│       └── vector<User>
│
├── Book
│   ├── id
│   ├── title
│   ├── author
│   ├── year
│   ├── totalCopies
│   └── availableCopies
│
└── User
    ├── id
    ├── name
    ├── borrowLimit
    └── borrowedBooks
```

---

The flow is:

**Library** acts as the **manager/controller**.

**Books and Users** are the **entities**.

**Methods** in Library coordinate actions (search, borrow, return).

**Test cases** check that the whole system behaves correctly.

