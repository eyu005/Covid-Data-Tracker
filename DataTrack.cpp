#include <iostream>
#include <fstream>
#include <sstream>
#include "CovidDB.h"
#include "DataEntry.h"

using namespace std;

int main() {
  CovidDB covidDB;
  int choice;
  // Creating a simple user interface.
  do {
    cout << "\n" << endl;
    cout << "Please select an operation: " << endl;
    cout << "1. Create the initial hash table" << endl;
    cout << "2. Add a new data entry" << endl;
    cout << "3. Get a data entry" << endl;
    cout << "4. Remove a data entry" << endl;
    cout << "5. Display hash table" << endl;
    cout << "0. Quit" <<endl;
    cout << "Your choice: " << endl;
    cin >> choice;
    switch (choice) {
      case 1: {
      ifstream file;
      file.open("WHO-COVID-Data-1.csv");
      // file.open("WHO-COVID-Data-Test-1.csv");
      string line;
      while(getline(file, line)) {
        vector<string> csvRow;
        stringstream ss(line);
        while(ss.good()) {
          string subStr;
          getline(ss, subStr, ',');
          csvRow.push_back(subStr);
        }
        string date = csvRow[0];
        string country = csvRow[1];
        int cases = stoi(csvRow[2]);
        int deaths = stoi(csvRow[3]);
        DataEntry* dataEntry = new DataEntry(date, country, cases,
        deaths);
        covidDB.add(dataEntry);
      }
      file.close();
      cout << "Successfully initialized hash table. " << endl;
      break;
    }
    case 2: {
      string date;
      string country;
      int cases;
      int deaths;
      cout << "Enter a date: ";
      cin >> date;
      cout << "Enter a country: ";
      cin >> country;
      cout << "Enter the number of cases: ";
      cin >> cases;
      cout << "Enter the number of deaths: ";
      cin >> deaths;
      
      DataEntry* dataEntry = new DataEntry(date, country, cases, deaths);
      bool result = covidDB.add(dataEntry);
      if(result) {
        cout << "Successfully entered entry: ";
        dataEntry->print();
      } else {
        cout << "Failed to enter new entry." << endl;
      }
      break;
    }
    case 3: {
      string country;
      cout << "Enter a country to search for: ";
      cin >> country;
      DataEntry* dataEntry = covidDB.get(country);
      if (dataEntry != nullptr) {
        dataEntry->print();
      } else {
        cout << "Country not found." << endl;
      }
      break;
    }
    case 4: {
      string country;
      cout << "Enter a country to delete: ";
      cin >> country;
      covidDB.remove(country);
      break;
    }
    case 5: {
      covidDB.print();
      break;
    }
    case 0: {
      cout << "\n";
      cout << "End of the program" << endl;
      cout << "\n";
      break;
    }
    default:
      cout << "Invalid input. Please try again";
    }
  } while (choice != 0);
  return 0;
}
