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

    if (sqlite.DirectStatement("create table foo (bar, baz)")) {
        std::cout << "table foo created" << std::endl;
    }
    else {
        std::cout << "Couldn't create table foo" << std::endl;
    }

    return 0;
}
