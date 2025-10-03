

#Test Cases  

The following test cases were run to verify correctness of the system.  



#1. Add and Search Book (Positive Test)  
- Input: Add book → ID: 101, Title: "C++ Basics", Author: "Bjarne", Year: 1985, Copies: 2  
- Action: Search by Title → "C++ Basics"  
- Expected Output: Book details printed with 2 copies available.  



#2. Search Non-existent Book (Negative Test)  
- Input: Search by Title → "Python for Kids"  
- Expected Output: "No book found with title 'Python for Kids'."  



#3. Add and Search User (Positive Test)  
- Input: Add user → ID: 1, Name: "Alice"  
- Action: Search User → "Alice"  
- Expected Output: User details printed with borrow limit 3.  



#4. Borrow Book Successfully (Positive Test)  
- Input: User "Alice" borrows "C++ Basics"  
- Expected Output:  
  - "Alice borrowed 'C++ Basics'."  
  - Available copies reduced to 1.  



#5. Borrow Book When No Copies Left (Negative Test)  
- Input: Alice borrows all copies of "C++ Basics", then tries again.  
- Expected Output:  
  - "No available copies left for 'C++ Basics'."  



#6. Borrow More Than Limit (Negative Test)  
- Input: Alice tries to borrow 4 books (limit = 3).  
- Expected Output:  
  - "Alice has reached the borrowing limit."  



#7. Return Book Successfully (Positive Test)  
- Input: Alice returns "C++ Basics".  
- Expected Output:  
  - "'C++ Basics' returned successfully."  
  - Available copies increased by 1.  



#8. Return Book Not Borrowed (Negative Test)  
- Input: Alice tries to return "Python for Kids" (never borrowed).  
- Expected Output:  
  - "Alice did not borrow 'Python for Kids'."  


#9. Remove Book (Positive Test)  
- Input: Remove book → ID: 101 ("C++ Basics")  
- Expected Output:  
  - "Book removed successfully."  
  - Searching for "C++ Basics" shows no results.  



#10. Remove Non-existent User (Negative Test)  
- Input: Remove user → ID: 99 (not in system)  
- Expected Output:  
  - "User not found."  



