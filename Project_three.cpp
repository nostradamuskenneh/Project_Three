#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;
    string inputFile = "CS210_Project_Three_Input_File.txt";
    string backupFile = "frequency.dat";

public:
    // Load data from the file and populate the map
    void LoadDataFromFile() {
        ifstream file(inputFile);
        string item;
        if (file.is_open()) {
            while (file >> item) {
                itemFrequency[item]++;
            }
            file.close();
        }
    }

    // Get the frequency of a specific item
    int GetItemFrequency(const string& item) {
        if (itemFrequency.find(item) != itemFrequency.end()) {
            return itemFrequency[item];
        }
        else {
            return 0;
        }
    }

    // Display all items and their frequencies
    void DisplayAllItems() {
        for (auto const& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Display a histogram for the items
    void DisplayHistogram() {
        for (auto const& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Write data to the backup file
    void WriteBackupFile() {
        ofstream outfile(backupFile);
        for (auto const& pair : itemFrequency) {
            outfile << pair.first << " " << pair.second << endl;
        }
        outfile.close();
    }
};

int main() {
    GroceryTracker tracker;
    tracker.LoadDataFromFile();
    tracker.WriteBackupFile();

    int option;
    string item;
    while (true) {
        cout << "\n1. Find frequency of an item\n2. Display all items\n3. Display histogram\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter the item: ";
            cin >> item;
            cout << "Frequency of " << item << ": " << tracker.GetItemFrequency(item) << endl;
            break;
        case 2:
            tracker.DisplayAllItems();
            break;
        case 3:
            tracker.DisplayHistogram();
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
