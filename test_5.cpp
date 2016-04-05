#include <iostream>

#include "SQLiteWrapper.h"

int main() {
    SQLiteWrapper sqlite;
    std::string sql;
    if (sqlite.Open("SQLiteWrapper.db")) {
        std::cout << "SQLiteWrapper.db created or opened" << std::endl;
    }
    else {
        std::cout << "couldn't open SQLiteWrapper.db" << std::endl;
    }

    sql = "CREATE TABLE IF NOT EXISTS COMPANY("  \
           "ID INT PRIMARY KEY     NOT NULL," \
           "NAME           TEXT    NOT NULL," \
           "AGE            INT     NOT NULL," \
           "ADDRESS        CHAR(50)," \
           "SALARY         REAL );";


    if (sqlite.DirectStatement(sql)) {
        std::cout << "table COMPANY created" << std::endl;
    }
    else {
        std::cout << "Couldn't create table COMPANY" << std::endl;
    }

    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
           "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
           "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
           "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
           "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
           "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
           "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
           "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    if (sqlite.DirectStatement(sql)) {
        std::cout << "insert values successfully" << std::endl;
    }
    else {
        std::cout << "Couldn't insert values" << std::endl;
    }

    sql = "SELECT * from COMPANY";

    SQLiteWrapper::ResultTable res;
    if (sqlite.SelectStmt(sql, res)) {
        std::cout << "select  values successfully" << std::endl;
    }
    else {
        std::cout << "Couldn't select values" << std::endl;
    }

    return 0;
}
