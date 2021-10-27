#ifndef LAB1_BOOK_H
#define LAB1_BOOK_H

#include <string>
#include <ostream>
#include "Thing.h"

using namespace std;

class Book : public Thing {
public:
    Book();

    Book(const string &name, int prise, string author, string annotation, string genre, int year, int numberPage);

    Book(const Book &book);

    virtual ~Book();

    const string &getAuthor() const;

    void setAuthor(const string &author);

    const string &getAnnotation() const;

    void setAnnotation(const string &annotation);

    const string &getGenre() const;

    void setGenre(const string &genre);

    int getYear() const;

    void setYear(int year);

    int getNumberPage() const;

    void setNumberPage(int numberPage);

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

    Book &operator=(const Book &book);

    friend ostream &operator<<(ostream &os, const Book &book);

    friend istream &operator>>(istream &os, Book &book);

    void set_name(string name) override;

    string get_name() override;

    void set_prise(int prise) override;

    int get_prise() override;

protected:
    string author;
    string annotation;
    string genre;
    int year;
    int number_page;
};


#endif //LAB1_BOOK_H
