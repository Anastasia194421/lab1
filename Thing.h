#ifndef LAB1_THING_H
#define LAB1_THING_H

#include <ostream>
#include <utility>
#include <iostream>


using namespace std;

class Thing {
protected:
    string name;
    int prise;
public:
    Thing();

    Thing(string  name, int prise);

    Thing(const Thing &thing);

    Thing &operator=(const Thing &thing);

    bool operator==(const Thing &rhs) const;

    bool operator!=(const Thing &rhs) const;

    virtual void set_name(string name) = 0;

    virtual string get_name() = 0;

    virtual void set_prise(int prise) = 0;

    virtual int get_prise() = 0;

    virtual ~Thing();

    friend ostream &operator<<(ostream &os, const Thing &thing);

    friend istream &operator>>(istream& is,  Thing &thing);
};

#endif
