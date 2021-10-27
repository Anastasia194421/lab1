#ifndef LAB1_CHANCELLERY_H
#define LAB1_CHANCELLERY_H

#include <ostream>
#include "Thing.h"

using namespace std;

class Chancellery : public Thing {
public:
    Chancellery();

    Chancellery(string name, int prise, string appointment, int color);

    Chancellery(const Chancellery& chancellery);

   string getAppointment() const;

    void setAppointment(string appointment);

    int getColor() const;

    void setColor(int color);

    void set_name(string name) override;

    string get_name() override;

    void set_prise(int prise) override;

    int get_prise() override;

    ~Chancellery() override;

    friend ostream &operator<<(ostream &os, const Chancellery &chancellery);

    friend istream &operator>>(istream &is, Chancellery &ch);

    bool operator==(const Chancellery &rhs) const;

    bool operator!=(const Chancellery &rhs) const;

    Chancellery& operator=(const Chancellery &rhs);

private:
    string appointment;
    int color;
};

#endif //LAB1_CHANCELLERY_H
