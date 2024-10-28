#include <iostream>
using namespace std;

struct BookDetails {
    string author;
    int pageCount;
};

struct MultimediaDetails {
    int duration;
    string format;
};

class LibraryItem{
private:
  int itemID;
  string title;
  double fileSize;
  int accessCount;
  BookDetails bookInfo;
  MultimediaDetails mediaInfo;
  static int totalItems;
  
public:
  LibraryItem(){
    itemID=0;
    title="Unknown";
    fileSize=0.0;
    accessCount=0;
    totalItems++;
  }
  LibraryItem(int id,string t,double fs, int ac){
    itemID=id;
    title=t;
    fileSize=fs;
    accessCount=ac;
    totalItems++;
  }
  void accessItem(){
    accessCount++;
  }
  void displayDetails(){
    cout << "Item ID: " << itemID << endl;
    cout << "Title: " << title << endl;
    cout << "File Size: " << fileSize << " MB" << endl;
    cout << "Access Count: " << accessCount << endl;
  }
  void displayBookDetails(){
    if (bookInfo.author != "") {
        cout << "Book Author: " << bookInfo.author << endl;
        cout << "Page Count: " << bookInfo.pageCount << endl;
    }  
  }
  void displayMediaDetails(){
    if (mediaInfo.format != "") {
        cout << "Multimedia Duration: " << mediaInfo.duration << " minutes" << endl;
        cout << "Format: " << mediaInfo.format << endl;
    }
  }
  void setBookDetails(string author, int pc) {
     bookInfo.author = author;
     bookInfo.pageCount = pc;
  }
  void setMultimediaDetails(int duration, string format) {
     mediaInfo.duration = duration;
     mediaInfo.format = format;
  }

  static int getTotalItems() {
     return totalItems;
  }
};

int LibraryItem::totalItems = 0;

void displayAllDetails(LibraryItem& item) {
    item.displayDetails();
    item.displayBookDetails();
    item.displayMediaDetails();
    cout << endl << endl;
}

int main(){
  LibraryItem book1(201, "C++ Programming", 1.5, 0);
  book1.setBookDetails("Bjarne Stroustrup", 350);

  LibraryItem media1(202, "Learning C++ Video", 600.0, 0);
  media1.setMultimediaDetails(45, "MP4");

  LibraryItem item3;

  book1.accessItem();
  book1.accessItem();
  media1.accessItem();

  displayAllDetails(book1);
  displayAllDetails(media1);
  item3.displayDetails();

  cout <<endl<< "Total Library Items Created: " << LibraryItem::getTotalItems() << endl;

  return 0;
}
