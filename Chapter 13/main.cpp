#include "Database.h"

int main()
{
   Database db("data.txt");
   db.append(Record{"Ryan Hermle", 22.99});  
   db.append(Record{"Lochness Monster", 3.50});  
   db.append(Record{"Wonder Woman", 123456.78});

   string temp_string = db.Database::getData();

   cout << temp_string;
}