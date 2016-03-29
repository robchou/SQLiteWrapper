#include <iostream>

#include "SQLiteWrapper.h"

int main() {
    SQLiteWrapper sqlite;
    if (sqlite.Open("SQLiteWrapper.db")) {
        std::cout << "SQLiteWrapper.db created or opened" << std::endl;
    }
    else {
        std::cout << "couldn't open SQLiteWrapper.db" << std::endl;
    }

    if (sqlite.DirectStatement("insert into foo values (1, 2)")) {
        std::cout << "values (1,2) into foo inserted" << std::endl;
    }
    else {
        std::cout << "Couldn't insert into foo" << std::endl;
    }

    return 0;
}
