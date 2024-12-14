#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
protected:
    string title;
    string type;
public:
    Book(string title,string type) : title(title), type(type) {}
    virtual double calculateScore() = 0;
    string getTitle() const { return title; }
    string getType() const { return type; }
};

class Fiction : public Book {
    int pages;
    double readingDifficulty;
public:
    Fiction(string title,int pages, double diff) : Book(title,"Fiction"), pages(pages), readingDifficulty(diff) {}
    double calculateScore() override {
        return pages * readingDifficulty;
    }
};

class NonFiction : public Book {
    int pages;
    double researchQuality;
public:
    NonFiction(string title,int pages, double quality) : Book(title,"NonFiction"), pages(pages), researchQuality(quality) {}
    double calculateScore() override {
        return pages * researchQuality;
    }
};

template <typename T>
class BookTemplate {
    T score;
public:
    BookTemplate(T s) : score(s) {}
    void displayScore() const {
        cout << "Score: " << score << endl;
    }
};

int main() {
    int choice;
    string title;
    int pages;
    double readingDifficulty, researchQuality;
    vector<Book *> books;

    while(true){
      cout << "Main Menu:\n"
        << "1. Add Fiction Book\n"
        << "2. Add NonFiction Book\n"
        << "3. Display Scores\n"
        << "4. Exit\n"
        << "Enter your choice: ";
      cin >> choice;
      cin.ignore();
      if(choice==1){
        cout << "Enter details for Fiction Book:\n";
        cout << "Title: ";
        getline(cin, title);
        cout << "Pages: ";
        cin >> pages;
        cout << "Reading Difficulty: ";
        cin >> readingDifficulty;
        books.push_back(new Fiction(title, pages, readingDifficulty));
      }else if(choice==2){
        cout << "\nEnter details for NonFiction Book:\n";
        cout << "Title: ";
        getline(cin, title);
        cout << "Pages: ";
        cin >> pages;
        cout << "Research Quality: ";
        cin >> researchQuality;
        books.push_back(new NonFiction(title, pages, researchQuality));
      }else if(choice==3){
        cout<<"\nCurrent Books:"<<endl;
        int num=1;
        for(Book *book:books){
          cout<<num<<": Title: "<<book->getTitle()<<" Type: "<<book->getType()<<" ";
          BookTemplate<double> fictionScore(book->calculateScore());
          fictionScore.displayScore();
          num++;
        }
        cout<<"\n";
      }else if(choice==4){
        break;
      }else {
        cout<<"Invalid input please try again."<<endl;
      }
    }

    return 0;
}
