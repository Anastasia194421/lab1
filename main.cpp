#include <iostream>
#include "Book.h"
#include "BookShop.h"
#include "Tutorial.h"
#include "Chancellery.h"

int main() {
    BookShop* shop = new BookShop();
    BookShop* shop1 = new BookShop();
    Tutorial* book = new Tutorial("abc", 90, "ovch", "kadsnfadsf", 1213, 123, 90);
    Chancellery* chan = new Chancellery("qwe", 234, "asdf", 90);
    shop->addThing(chan);
    shop->addThing(book);
    std::cout << *shop << endl;
    shop->saveFile();
    shop1->loadFile();
    std::cout << *shop1 << endl;
    return 0;
}
