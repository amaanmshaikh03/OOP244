#ifndef NAMESPACE_ShoppingRec_H // replace with relevant names
#define NAMESPACE_ShoppingRec_H

// Your header file content goes here
#include "Utils.h"
namespace sdds {
    const int MAX_TITLE_LENGTH = 50;
    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);

}
#endif