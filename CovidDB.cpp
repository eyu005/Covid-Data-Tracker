#include "CovidDB.h"
#include <iostream>
#include <string.h>

using namespace std;

// This is a Constructor
CovidDB::CovidDB() {
  size = 0;
}

// This method returns the size of the hashmap
int CovidDB::getSize() {
  return size;
}

// This method insert a DataEntry to a hashmap
bool CovidDB::add(DataEntry* newEntry) {
  DataEntry* existingEntry = get(newEntry->getCountry());
  if(existingEntry != nullptr) {
    if(convertDate(newEntry->getDate()) > convertDate(existingEntry->getDate())) {
      existingEntry->setCases(newEntry->getCases() + existingEntry->getCases());
      existingEntry->setDeaths(newEntry->getDeaths() + existingEntry->getDeaths());
      existingEntry->setDate(newEntry->getDate());
    }
  } else {
      int hash = hashFunction(newEntry->getCountry());
      hash_table[hash].push_back(newEntry);
      size++;
  }
  return true;
}

// This method retrieves a data entry with the specific country name. It returns
NULL if
// no such entry exists in the table.
DataEntry* CovidDB::get(string country) {
  int hash = hashFunction(country);
  vector<DataEntry*> countries = hash_table[hash];
  for (int i = 0; i < countries.size(); i++) {
    if (countries[i]->getCountry() == country) {
      return countries[i];
    }
  }
  return nullptr;
}

// This method removes a data entry with a specific country name
void CovidDB::remove(string country) {
  int hash = hashFunction(country);
  DataEntry* dataEntry = get(country);
  vector<DataEntry*> countries = hash_table[hash];
  vector<DataEntry*>::iterator deleteIt;
  bool found = false;
  for (vector<DataEntry*>::iterator it = countries.begin(); it !=countries.end(); ++it) {
      if ((*it)->getCountry() == country) {
          cout << "Removing " << (*it)->getCountry() << endl;
          deleteIt = it;
          found = true;
      }
  }
  if(found) {
    countries.erase(deleteIt);
    hash_table[hash] = countries;
    size--;
  }
}

// This method prints the data entry in the hash table
void CovidDB::print() {
  for(int i = 0; i < hash_table_size; i++) {
    vector<DataEntry*> countries = hash_table[i];
    if(countries.size() > 0) {
      for(DataEntry* entry : countries) {
          entry->print();
      }
    }
  }
}
