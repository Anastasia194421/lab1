#include "Chancellery.h"

Chancellery::Chancellery() {
    cout << "Chancellery constructor." << endl;
    color = 0;
}

Chancellery::Chancellery(string name, int prise, string appointment, int color) : Thing(move(name), prise),
                                                                                  appointment(move(appointment)),
                                                                                  color(color) {
    cout << "Chancellery constructor." << endl;
}

Chancellery::Chancellery(const Chancellery &chancellery) : Thing(chancellery) {
    cout << "Chancellery constructor copy." << endl;
    this->color = chancellery.color;
    this->appointment = chancellery.appointment;
}

void Chancellery::set_name(string name) {
    this->name = name;
}

string Chancellery::get_name() {
    return name;
}

void Chancellery::set_prise(int prise) {
    this->prise = prise;
}

int Chancellery::get_prise() {
    return prise;
}

string Chancellery::getAppointment() const {
    return appointment;
}

void Chancellery::setAppointment(string appointment) {
    Chancellery::appointment = move(appointment);
}

int Chancellery::getColor() const {
    return color;
}

void Chancellery::setColor(int color) {
    Chancellery::color = color;
}

Chancellery::~Chancellery() {
    cout << "Chancellery destructor." << endl;
}

ostream &operator<<(ostream &os, const Chancellery &chancellery) {
    os << "Chancellery: " << static_cast<const Thing &>(chancellery) << " appointment: " << chancellery.appointment << " color: "
       << chancellery.color;
    return os;
}


istream &operator>>(istream &is, Chancellery &ch) {
    string key;
    int count = 0;
    is >> static_cast<Thing&>(ch);
    while (is && count != 2) {
        is >> key;
        if(key == "appointment:") {
            is >> ch.appointment;
            count++;
        }
        if (key == "color:") {
            is >> ch.color;
            count++;
        }
    }
    return is;
}
bool Chancellery::operator==(const Chancellery &rhs) const {
    return static_cast<const Thing &>(*this) == static_cast<const Thing &>(rhs) &&
           appointment == rhs.appointment &&
           color == rhs.color;
}

bool Chancellery::operator!=(const Chancellery &rhs) const {
    return !(rhs == *this);
}

Chancellery &Chancellery::operator=(const Chancellery &chancellery) {
    if (this == &chancellery)
        return *this;
    this->~Chancellery();
    Thing::operator=(chancellery);
    this->color = chancellery.color;
    this->appointment = chancellery.appointment;
    return *this;
}