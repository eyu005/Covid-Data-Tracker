#ifndef COVIDDB_H
#define COVIDDB_H
#include <iostream>
#include <sstream>
#include <vector>
#include "DataEntry.h"

using namespace std;

class CovidDB {
  private:
    int hash_table_size = 17;
    vector <DataEntry*> hash_table[17];
    int size;

    // This is a hash function
    int hashFunction(string country) {
      int sum = 0;
      for (int i = 0; i < country.length(); i++) {
          int ascii = int(country.at(i));
          sum += ((i + 1) * ascii);
       }
       return sum % hash_table_size;
     }

    // This method converts date in the hash table to proper format for
    comparison.
     string convertDate(string str) {
        vector<string> csvRow;
        stringstream ss(str);
        while(ss.good()) {
           string subStr;
           getline(ss, subStr, '/');
           csvRow.push_back(subStr);
        }
     return csvRow[2] + "-" + getProperDate(csvRow[0]) + "-" +
     getProperDate(csvRow[1]);
     }

    string getProperDate(string date) {
      if(date.length() == 1) {
        return "0" + date;
      }
    return date;
    }

  public:
    CovidDB();
    int getSize();
    bool add(DataEntry* entry);
    DataEntry* get(string country);
    void remove(string country);
    void print();
};
#endif
