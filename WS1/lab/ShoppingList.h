#ifndef NAMESPACE_ShoppingList_H // replace with relevant names
#define NAMESPACE_ShoppingList_H

	// Your header file content goes here

#include "File.h"
namespace sdds {
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif