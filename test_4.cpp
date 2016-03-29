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

    SQLiteStatement* stmt = sqlite.Statement("select * from foo");

    while (stmt->NextRow()) {
        std::cout << stmt->DataType   (0) << " - " << stmt->DataType   (1) << " | " <<
            stmt->ValueString(0) << " - " << stmt->ValueString(1) << std::endl;
    }

    return 0;
}
