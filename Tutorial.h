#ifndef LAB1_TUTORIAL_H
#define LAB1_TUTORIAL_H


#include <ostream>
#include "Thing.h"

using namespace std;

class Tutorial : public Thing {
public:
    Tutorial();

    Tutorial(const Tutorial &tutorial);

    Tutorial(const string &name, int prise, string author, string appointment, int year, int yearStudy,
             int numberPage);

    ~Tutorial() override;

    string getAuthor() const;

    void setAuthor(string author);

    int getYear() const;

    void setYear(int year);

    string getAppointment() const;

    void setAppointment(string appointment);

    int getYearStudy() const;

    void setYearStudy(int yearStudy);

    int getNumberPage() const;

    void setNumberPage(int numberPage);

    void set_name(string name) override;

    string get_name() override;

    void set_prise(int prise) override;

    int get_prise() override;

    bool operator==(const Tutorial &rhs) const;

    bool operator!=(const Tutorial &rhs) const;

    Tutorial &operator=(const Tutorial &tutorial);

    friend std::ostream &operator<<(std::ostream &os, const Tutorial &tutorial);

    friend istream &operator>>(istream &is, Tutorial &tut);

private:
    string author;
    string appointment;
    int year;
    int year_study;
    int number_page;
};


#endif //LAB1_TUTORIAL_H
