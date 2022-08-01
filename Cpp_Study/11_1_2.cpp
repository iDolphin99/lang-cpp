#include <iostream>
using namespace std;

class Book {
private :
	char* title;
	char* isbn;
	int price; 
public :
	Book(const char * btitle, const char *bisbn, int bprice) : price(bprice) {
		title = new char[strlen(btitle) + 1];
		isbn = new char[strlen(bisbn) + 1];
		strcpy_s(title, strlen(btitle) + 1, btitle);
		strcpy_s(isbn, strlen(bisbn) + 1, bisbn);
	}
	Book(const Book& ref) : price(ref.price) {
		cout << "called Book Copy Constructor!" << endl;

		isbn = new char[strlen(ref.isbn) + 1];
		title = new char[strlen(ref.title) + 1];
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
	}
	Book& operator=(const Book& ref) {
		cout << "called Book Assignment Operator!" << endl;

		price = ref.price;

		if (isbn) delete isbn;
		if (title) delete title;
		isbn = new char[strlen(ref.isbn) + 1];
		title = new char[strlen(ref.title) + 1];
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
		strcpy_s(title, strlen(ref.title) + 1, ref.title);

		return *this;
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete[] title, isbn;
	}
};

class EBook : public Book {
private :
	char* DRMKey;
public :
	EBook(const char* btitle, const char* bisbn, int bprice, const char* ekey) : Book(btitle, bisbn, bprice) {
		DRMKey = new char[strlen(ekey) + 1];
		strcpy_s(DRMKey, strlen(ekey) + 1, ekey);
	}
	EBook(const EBook& ref) : Book(ref) {
		cout << "called EBook Copy Constructor!" << endl;

		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
	}
	EBook& operator=(const EBook& ref) {
		cout << "called Ebook Assignment Operator!" << endl;

		Book::operator=(ref);
		if (DRMKey) delete DRMKey;
		if (!ref.DRMKey) DRMKey = NULL;
		else {
			DRMKey = new char[strlen(ref.DRMKey) + 1];
			strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
		}

		return *this;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey;
	}
	~EBook() {
		delete[] DRMKey;
	}
};

int main() {
	Book book1("C++책", "AAA-BBB", 10000);
	Book book2=book1; // copy constructor 
	Book book3("C++책pro", "AAAA-BBBB", 20000);
	book3 = book2;    // assignment operator 
	book3.ShowBookInfo();

	EBook ebook1("Java책", "JJJ-VVV", 15000, "e-JJJ-VVV");
	EBook ebook2 = ebook1; // copy constructor 
	EBook ebook3("Java책pro", "JJJJ-VVVV", 30000, "e-JJJJ-VVVV");
	ebook3 = ebook2;      // assignment operator 
	ebook3.ShowEBookInfo();
}