#include "DataEntry.h"

DataEntry::DataEntry(string newDate, string newCountry, int cases, int deaths) {
  date = newDate;
  country = newCountry;
  c_cases = cases;
  c_deaths = deaths;
}

// Getters
string DataEntry::getDate() {
  return date;
}

string DataEntry::getCountry() {
  return country;
}

int DataEntry::getCases() {
  return c_cases;
}

int DataEntry::getDeaths() {
  return c_deaths;
}

// Setters
void DataEntry::setDate(string newDate) {
  date = newDate;
}

void DataEntry::setCountry(string newCountry) {
  country = newCountry;
}

void DataEntry::setCases(int cases) {
  c_cases = cases;
}

void DataEntry::setDeaths(int deaths) {
  c_deaths = deaths;
}

void DataEntry::print() {
  cout << date << ", " << country << ", " << c_cases << ", " << c_deaths << endl;
}
