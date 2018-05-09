#include "Database.h"

Database::Database(string str)
{
    fileName = str;
}

void Database::append(Record data)
{
    ofstream output(fileName,ios::app);

    output << fixed << setprecision(2);
    output << data.name << endl << data.money << endl;
    
    output.close();
}

double Database::searchName(string search_phrase)
{
    string   temp_string;
    double   temp_double;
    ifstream input(fileName);
    
    if (!input.is_open())
    {
        cout << "cannot open input file" << endl << flush;
        return 1;
    }

    while (getline(input, temp_string) >> temp_double/*!input.fail()*/)
    {
        //getline(input, temp_string);
        //input >> temp_double;
        input.ignore();

        if (temp_string == search_phrase)
        {
            input.close();
            return temp_double;
        }
    }
    input.close();
    return -1;
}

string Database::getData()
{
    ifstream      input(fileName);
    ostringstream oSS;
    string        temp_string;
    double        temp_double;

    oSS << fixed << setprecision(2);

    while (getline(input, temp_string) >> temp_double)
    {
        input.ignore();
        oSS << temp_string << endl << temp_double << endl;
    }

    return oSS.str();
}