#ifndef NAMESPACE_File_H // replace with relevant names
#define NAMESPACE_File_H
#include "ShoppingRec.h"
namespace sdds {

	// Your header file content goes here
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif