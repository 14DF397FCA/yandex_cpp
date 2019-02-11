#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print_all_buses(map<string, vector<string>> &buses) {
    if (buses.empty()) {
        cout << "No buses" << endl;
    } else {
        for (const auto &bus : buses) {
            cout << "Bus " << bus.first << ": ";
            for (const auto &stops : bus.second) {
                cout << stops << " ";
            }
            cout << endl;
        }
    }
}

void buses_for_stop(map<string, vector<string>> &stops_to_buses, const string &stop) {
    if (stops_to_buses.count(stop) == 0) {
        cout << "No stop" << endl;
    } else {
        for (const auto &bus : stops_to_buses[stop]) {
            cout << bus << " ";
        }
        cout << endl;
    }
}

void stops_for_bus(map<string, vector<string>> &buses_to_stops, map<string, vector<string>> &stops_to_buses,
                   const string &bus) {
    if (buses_to_stops.count(bus) == 0) {
        cout << "No bus" << endl;
    } else {
        for (const auto &stop : buses_to_stops[bus]) {
            cout << "Stop " << stop << ": ";
            if (stops_to_buses[stop].size() == 1) {
                cout << "no interchange";
            } else {
                for (const string &alt_bus : stops_to_buses[stop]) {
                    if (bus != alt_bus) {
                        cout << alt_bus << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}

int main() {
    int q = 0;
    cin >> q;
    map<string, vector<string>> buses_to_stop, stop_to_buses;
    for (int i = 0; i < q; ++i) {
        string operation = "";
        cin >> operation;
        if (operation == "NEW_BUS") {
            int stops_num = 0;
            string bus = "";
            cin >> bus;
            cin >> stops_num;
            vector<string> &stops = buses_to_stop[bus];
            stops.resize(stops_num);
            for (auto &stop : stops) {
                cin >> stop;
                stop_to_buses[stop].push_back(bus);
            }
        } else if (operation == "BUSES_FOR_STOP") {
            string stop = "";
            cin >> stop;
            buses_for_stop(stop_to_buses, stop);
        } else if (operation == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            stops_for_bus(buses_to_stop, stop_to_buses, bus);
        } else if (operation == "ALL_BUSES") {
            print_all_buses(buses_to_stop);
        } else {
            cout << "Unsupported action - " << operation << endl;
        }
    }
    return 0;
}
/*
10
ALL_BUSES
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
ALL_BUSES
BUSES_FOR_STOP Vnukovo
 */