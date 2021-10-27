#ifndef LAB1_BOOKSHOP_H
#define LAB1_BOOKSHOP_H

#include <fstream>
#include <ostream>
#include "Thing.h"

class BookShop {
protected:
    Thing **things;
    int size;
    int capacity;
public:
    BookShop();

    BookShop(int size);

    BookShop(const BookShop& bookShop);

    BookShop& operator=(const BookShop& bookShop);

    ~BookShop();

    int getSize() const;

    int getCapacity() const;

    void addThing(Thing *thing);

    void removeThing(Thing *thing);

    void saveFile() const;

    void loadFile();

    friend ostream &operator<<(ostream &os, const BookShop &shop);

    friend istream &operator>>(istream &is, BookShop &shop);

};

#endif //LAB1_BOOKSHOP_H
