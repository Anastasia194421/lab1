#include "Thing.h"

#include <utility>

Thing::Thing() {
    cout << "Thing constructor." << endl;
    prise = 0;
}

Thing::Thing(string name, int prise) : name(std::move(name)), prise(prise) {
    cout << "Thing constructor." << endl;
}

Thing::Thing(const Thing &thing) {
    cout << "Thing constructor copy." << endl;
    this->prise = thing.prise;
    if (!thing.name.empty()) {
        name = thing.name;
    }
}

Thing &Thing::operator=(const Thing &thing) {
    if (this == &thing)
        return *this;
    this->~Thing();
    this->prise = thing.prise;
    if (!thing.name.empty()) {
        name = thing.name;
    }
    return *this;
}

bool Thing::operator==(const Thing &rhs) const {
    return name == rhs.name &&
           prise == rhs.prise;
}

bool Thing::operator!=(const Thing &rhs) const {
    return !(rhs == *this);
}

Thing::~Thing() {
    name.clear();
    cout << "Thing destructor." << endl;
}

ostream &operator<<(ostream &os, const Thing &thing) {
    os << "name: " << thing.name << " prise: " << thing.prise;
    return os;
}

istream &operator>>(istream &is, Thing &thing) {
    string name;
    string prise;
    is >> name;
    if (name == "name:") {
        is >> thing.name;
        is >> prise;
        if (prise == "prise:") {
            is >> thing.prise;
        }
    }
    return is;
}
