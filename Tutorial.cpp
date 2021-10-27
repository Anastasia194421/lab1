#include "Tutorial.h"

#include <utility>

Tutorial::Tutorial() {
    cout << "Tutorial constructor." << endl;
    year = 0;
    year_study = 0;
    number_page = 0;
}

Tutorial::Tutorial(const string &name, int prise, string author, string appointment, int year,
                   int yearStudy, int numberPage) : Thing(name, prise), author(std::move(author)), appointment(std::move(appointment)),
                                                    year(year), year_study(yearStudy), number_page(numberPage) {
    cout << "Tutorial constructor." << endl;
}

Tutorial::Tutorial(const Tutorial &tutorial) : Thing(tutorial) {
    cout << "Tutorial constructor copy." << endl;
    this->number_page = tutorial.number_page;
    this->year = tutorial.year;
    this->year_study = tutorial.year_study;
    appointment = tutorial.appointment;
    author = tutorial.author;
}

Tutorial::~Tutorial() {
    cout << "Tutorial destructor." << endl;
    author.clear();
    appointment.clear();
}

std::ostream &operator<<(std::ostream &os, const Tutorial &tutorial) {
    os << "Tutorial: " << static_cast<const Thing &>(tutorial) << " author: " << tutorial.author << " year: " << tutorial.year
       << " appointment: " << tutorial.appointment << " year_study: " << tutorial.year_study << " number_page: "
       << tutorial.number_page;
    return os;
}

Tutorial &Tutorial::operator=(const Tutorial &tutorial) {
    if (this == &tutorial)
        return *this;
    this->~Tutorial();
    Thing::operator=(tutorial);
    this->number_page = tutorial.number_page;
    this->year = tutorial.year;
    this->year_study = tutorial.year_study;
    this->appointment = tutorial.appointment;
    this->author = tutorial.author;
    return *this;
}

void Tutorial::set_name(std::string name) {
    this->name = std::move(name);
}

std::string Tutorial::get_name() {
    return name;
}

void Tutorial::set_prise(int prise) {
    this->prise = prise;
}

int Tutorial::get_prise() {
    return prise;
}

string Tutorial::getAuthor() const {
    return author;
}

void Tutorial::setAuthor(string author) {
    Tutorial::author = std::move(author);
}

int Tutorial::getYear() const {
    return year;
}

void Tutorial::setYear(int year) {
    Tutorial::year = year;
}

string Tutorial::getAppointment() const {
    return appointment;
}

void Tutorial::setAppointment(string appointment) {
    Tutorial::appointment = std::move(appointment);
}

int Tutorial::getYearStudy() const {
    return year_study;
}

void Tutorial::setYearStudy(int yearStudy) {
    year_study = yearStudy;
}

int Tutorial::getNumberPage() const {
    return number_page;
}

void Tutorial::setNumberPage(int numberPage) {
    number_page = numberPage;
}

bool Tutorial::operator==(const Tutorial &rhs) const {
    return static_cast<const Thing &>(*this) == static_cast<const Thing &>(rhs) &&
           author == rhs.author &&
           year == rhs.year &&
           appointment == rhs.appointment &&
           year_study == rhs.year_study &&
           number_page == rhs.number_page;
}

bool Tutorial::operator!=(const Tutorial &rhs) const {
    return !(rhs == *this);
}


istream &operator>>(istream &is, Tutorial &tut) {
    string key;
    int count = 0;
    is >> static_cast<Thing&>(tut);
    while (is && count != 5) {
        is >> key;
        if(key == "author:") {
            is >> tut.author;
            count++;
        }
        if(key == "year_study:") {
            is >> tut.year_study;
            count++;
        }
        if (key == "year:") {
            is >> tut.year;
            count++;
        }
        if (key == "appointment:") {
            is >> tut.appointment;
            count++;
        }
        if (key == "number_page:") {
            is >> tut.number_page;
            count++;
        }
    }
    return is;
}
