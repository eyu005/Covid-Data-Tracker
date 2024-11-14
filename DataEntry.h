#ifndef DATAENTRY_H
#define DATAENTRY_H

#include <iostream>

using namespace std;

// Creating a class named DataEntry
class DataEntry {
  private:
    string date;
    string country;
    int c_cases;
    int c_deaths;
  public:
    DataEntry(string date, string country, int cases, int deaths);
    string getDate();
    string getCountry();
    int getCases();
    int getDeaths();
    void setDate(string date);
    void setCountry(string country);
    void setCases(int cases);
    void setDeaths(int deaths);
    void print();
};

#endif
