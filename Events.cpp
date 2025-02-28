#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Event {
public:
    Event(const string& name, int attendees) : name(name), attendees(attendees) {}

    string judgeSuccess() const {
        if (attendees < 30) {
            return "Fail";
        } else if (attendees < 50) {
            return "Ok";
        } else {
            return "Great";
        }
    }

    string getName() const {
        return name;
    }

private:
    string name;
    int attendees;
};

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<Event> events;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string eventName;
        int numberOfAttendees;

        if (iss >> eventName >> numberOfAttendees) {
            cout << "Read event: " << eventName << " with attendees: " << numberOfAttendees << endl; // Debugging line
            events.emplace_back(eventName, numberOfAttendees);
        } else {
            cerr << "Error reading line: " << line << endl;
        }
    }

    inputFile.close();

    if (events.empty()) {
        cerr << "No events found in the file." << endl;
        return 1;
    }

    for (const auto& event : events) {
        cout << "Event " << event.getName() << " was a: " << event.judgeSuccess() << endl;
    }

    return 0;
}