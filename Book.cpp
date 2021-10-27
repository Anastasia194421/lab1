#include "Book.h"

Book::Book() {
    cout << "Book constructor." << endl;
    year = 0;
    number_page = 0;
}

Book::Book(const string &name, int prise, string author, string annotation, string genre, int year, int numberPage)
        : Thing(name, prise), author(move(
        author)), annotation(move(annotation)), genre(move(genre)), year(year), number_page(numberPage) {
    cout << "Book constructor." << endl;
}

Book::~Book() {
    cout << "Book destructor." << endl;
}

Book::Book(const Book &book) : Thing(book) {
    cout << "Book constructor copy." << endl;
    this->genre = book.genre;
    this->number_page = book.number_page;
    this->annotation = book.annotation;
    this->year = book.year;
    this->author = book.author;
}

const string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string &author) {
    Book::author = author;
}

const string &Book::getAnnotation() const {
    return annotation;
}

void Book::setAnnotation(const string &annotation) {
    Book::annotation = annotation;
}

const string &Book::getGenre() const {
    return genre;
}

void Book::setGenre(const string &genre) {
    Book::genre = genre;
}

int Book::getYear() const {
    return year;
}

void Book::setYear(int year) {
    Book::year = year;
}

int Book::getNumberPage() const {
    return number_page;
}

void Book::setNumberPage(int numberPage) {
    number_page = numberPage;
}

void Book::set_name(string name) {
    this->name = name;
}

string Book::get_name() {
    return name;
}

void Book::set_prise(int prise) {
    this->prise = prise;
}

int Book::get_prise() {
    return prise;
}

bool Book::operator==(const Book &rhs) const {
    return static_cast<const Thing &>(*this) == static_cast<const Thing &>(rhs) &&
           author == rhs.author &&
           annotation == rhs.annotation &&
           genre == rhs.genre &&
           year == rhs.year &&
           number_page == rhs.number_page;
}

bool Book::operator!=(const Book &rhs) const {
    return !(rhs == *this);
}

Book &Book::operator=(const Book &book) {
    if (&book == this)
        return *this;
    this->~Book();
    this->author = book.author;
    this->year = book.year;
    this->number_page = book.number_page;
    this->annotation = book.annotation;
    this->genre = book.genre;
    return *this;
}

ostream &operator<<(ostream &os, const Book &book) {
    os << "Book: " <<  static_cast<const Thing &>(book) << " author: " << book.author << " annotation: " << book.annotation
       << " genre: " << book.genre << " year: " << book.year << " number_page: " << book.number_page << endl;
    return os;
}

istream &operator>>(istream &is, Book &book) {
    string key;
    int count = 0;
    is >> static_cast<Thing&>(book);
    while (is && count != 5) {
        is >> key;
        if(key == "author:") {
            is >> book.author;
            count++;
        }
        if(key == "genre:") {
            is >> book.genre;
            count++;
        }
        if (key == "year:") {
            is >> book.year;
            count++;
        }
        if (key == "annotation:") {
            is >> book.annotation;
            count++;
        }
        if (key == "number_page:") {
            is >> book.number_page;
            count++;
        }
    }
    return is;
}

