#include "BookShop.h"
#include "Book.h"
#include "Chancellery.h"
#include "Tutorial.h"

BookShop::BookShop() {
    cout << "BookShop constructor." << endl;
    this->size = 0;
    this->capacity = 1000;
    this->things = new Thing *[1000];
}

BookShop::BookShop(int capacity) {
    cout << "BookShop constructor." << endl;
    if (capacity > 1) {
        this->size = 0;
        this->capacity = capacity;
        this->things = new Thing *[capacity];
    } else
        BookShop();
}

BookShop::BookShop(const BookShop &bookShop) {
    cout << "BookShop constructor copy." << endl;
    this->size = bookShop.size;
    this->capacity = bookShop.capacity;
    delete[] things;
    things = new Thing *[capacity];
    for (int i = 0; i < size; i++) {
        things[i] = bookShop.things[i];
    }
}

BookShop::~BookShop() {
    cout << "BookShop destructor." << endl;
    delete[] things;
}

BookShop &BookShop::operator=(const BookShop &bookShop) {
    if (this == &bookShop)
        return *this;
    this->~BookShop();
    this->size = bookShop.size;
    this->capacity = bookShop.capacity;
    delete[] things;
    things = new Thing *[capacity];
    for (int i = 0; i < size; i++) {
        things[i] = bookShop.things[i];
    }
    return *this;
}

int BookShop::getSize() const {
    return size;
}

int BookShop::getCapacity() const {
    return capacity;
}

void BookShop::addThing(Thing *thing) {
    if (size + 1 == capacity) {
        throw exception();
    }
    things[size] = thing;
    size++;
}

void BookShop::removeThing(Thing *thing) {
    if(thing == nullptr)
        throw exception();
    for (int i = 0; i < size; i++) {
        if (things[i] == thing) {
            thing[i] = thing[size - 1];
            size--;
            break;
        }
    }
}

void BookShop::removeLastThing() {
    delete things[size-1];
    size--;
}


void BookShop::saveFile() const {
    std::ofstream fout;
    fout.open("things.txt");
    fout << *this;
    fout.close();
}

void BookShop::loadFile(){
    ifstream fin;
    fin.open("things.txt");
    fin >> *this;
}

ostream &operator<<(ostream &os, const BookShop &shop) {
    os << " size: " << shop.size << " ";
    os << "things: ";
    for (int i = 0; i < shop.size; i++) {
        if(dynamic_cast<Book*>(shop.things[i]) != 0) {
            auto * book = dynamic_cast<Book*>(shop.things[i]);
            os << *book << " ";
        }
        if(dynamic_cast<Chancellery*>(shop.things[i]) != 0) {
            auto* ch = dynamic_cast<Chancellery*>(shop.things[i]);
            os << *ch << " ";
        }
        if(dynamic_cast<Tutorial*>(shop.things[i]) != 0) {
            auto* tmp = dynamic_cast<Tutorial*>(shop.things[i]);
            os << *tmp << " ";
        }
    }
    return os;
}

istream &operator>>(istream &is, BookShop &shop) {
    string things;
    string size;
    is >> size;
    if(size == "size:") {
        is >> shop.size;
        is >> things;
        if(things == "things:") {
            if(shop.size > shop.capacity) {
                shop.capacity = shop.size * 2;
                shop.things = new Thing*[shop.capacity];
            }
            string key;
            for(int i = 0; i < shop.size; i++) {
                is >> key;
                if(key == "Book:") {
                    Book* book = new Book();
                    is >> static_cast<Book&>(*book);
                    shop.things[i] = book;
                    continue;
                }
                if(key == "Chancellery:") {
                    auto* book = new Chancellery();
                    is >> static_cast<Chancellery&>(*book);
                    shop.things[i] = book;
                    continue;
                }
                if(key == "Tutorial:") {
                    auto* book = new Tutorial();
                    is >> static_cast<Tutorial&>(*book);
                    shop.things[i] = book;
                }
            }
        }
    }
    return is;
}


