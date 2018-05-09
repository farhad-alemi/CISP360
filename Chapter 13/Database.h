#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;

struct Record
{
    string name;
    double money;
};

class Database
{
public:
    Database(string str);
    void append(Record data);
    double searchName(string search_phrase);
    string getData();

private:
    string fileName;
};

#endif // DATABASE_H_INCLUDED