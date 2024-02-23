#include <iostream>
#include <string>

class Book{
    private:
        std::string title;
        std::string author;
        int isbn;
    public:
        Book(std::string Ititle,std::string Iauthor,int Iisbn):title(Ititle),author(Iauthor),isbn(Iisbn){}
        Book() = default;

        void setTitle(std::string name){
            title = name;
        }
        std::string getTitle() const {
            return title;
        }

        void setAuthor(std::string name){
            author = name;
        }
        std::string getAuthor() const {
            return author;
        }

        void setISBN(int newIsbn){
            isbn = newIsbn;
        }
        int getISBN() const {
            return isbn;
        }

};

int main(){
    Book book;
    book.setISBN(1234);
    book.setAuthor("Conan Doyle");
    book.setTitle("Sherlock Holmes");

    std::cout<<book.getAuthor()<<"`s "<<book.getTitle()<<" book has "<<book.getISBN()<<" isbn number"<<std::endl;
    return 0;
}
