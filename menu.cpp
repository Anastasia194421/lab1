#include <iostream>
#include "BookShop.h"
#include "Book.h"
#include "Tutorial.h"
#include "Chancellery.h"

using namespace std;

void static menu_add(BookShop* shop) {
    int c =  1;
    while (c != 0) {
        cout << "MENU ADD BOOKSHOP" << endl;
        cout << "1 - add Book" << endl;
        cout << "2 - add Tutorial" << endl;
        cout << "3 - add Chancellery" << endl;
        cin >> c;
        switch(c) {
            case 1: {
                auto *book = new Book("Paradise", 90, "Dante", "death, life ", "Comedy", 2021, 900);
                shop->addThing(book);
                c = 0;
                break;
            }
            case 2: {
                auto *tutorial = new Tutorial("Alphabet", 90, "ovchinnikov", "crypto", 2001, 2021, 173);
                shop->addThing(tutorial);
                c = 0;
                break;
            }
            case 3: {
                auto *chan = new Chancellery("Pancel", 234, "wood", 90);
                shop->addThing(chan);
                c = 0;
                break;
            }
        }
    }
}

void static menu() {
    int c =  1;
    auto* shop = new BookShop();
    while (c != 0) {
        cout << "MENU BOOKSHOP" << endl;
        cout << "1 - add thing" << endl;
        cout << "2 - delete last thing" << endl;
        cout << "3 - show thing" << endl;
        cout << "4 - save file" << endl;
        cout << "5 - load file" << endl;
        cout << "0 - exit" << endl;
        cin >> c;
        switch(c) {
            case 1:
                menu_add(shop);
                break;
            case 2:
                shop->removeLastThing();
                break;
            case 3:
                cout << *shop << endl;
                break;
            case 4:
                shop->saveFile();
                break;
            case 5:
                shop->loadFile();
                break;
        }
    }
}
