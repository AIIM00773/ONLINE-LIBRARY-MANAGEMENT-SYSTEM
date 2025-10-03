

#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Book{
    private:
      int ID;
      string TITLE;
      string AUTHOR;
      
    public:
      //constructor
      Book(int id, string title,string author){
      
        ID = id;
        TITLE = title;
        AUTHOR = author;
      
      };
        
};




class User{
    private:
      int ID;
      string FIRSTNAME;
      string LASTNAME;
      
    public:
      //constructor
      User(int id, string first_name,string last_name){
      
        ID = id;
        FIRSTNAME = first_name;
        LASTNAME = last_name;
      
      };
        
};





//main class-------------------------------------------------------

class Library{
public:
   vector<Book>books;
   vector<User>users;
   
   void addBooks(int id, string title, string author ){
       books.push_back(Book(id,title,author));
       cout<<" The book "<< id <<" "<< title <<" "<< author <<" added sucessfully;"<<endl;  
   }
   
   
   
   void addUser(int id, string first_name, string last_name){
    users.push_back(User(id,first_name,last_name));
    cout<<" The user "<< id <<" "<< first_name <<" "<< last_name <<" added sucessfully;"<<endl;  
   };
   
   
   
   };





int main(){
Library library;

library.addBooks(1,"Title1","Author1");
library.addUser(1,"Fredrick","Owino");

return 0;
}
