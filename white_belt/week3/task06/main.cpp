#include <iostream>
#include "ReversibleString.cpp"

using namespace std;

class Route {
public:
    string GetSource() const {
        return source;
    }

    string GetTarget() const {
        return target;
    }

    int GetLength() const {
        return length;
    }

    void SetSource(const string &new_source) {
        source = new_source;
        UpdateLength();
    }

    void SetTarget(const string &new_target) {
        target = new_target;
        UpdateLength();
    }

    Route() {
        source = "Minsk";
        target = "Gomel";
        UpdateLength();
    }

    Route(const string &new_source, const string &new_target) {
        SetSource(new_source);
        SetTarget(new_target);
        UpdateLength();
    }

private:
    string source;
    string target;
    int length;

    void UpdateLength() {
        length = source.size() - target.size();
    }
};

void PrintRoute(const Route &route) {
    cout << route.GetSource() << " -> " << route.GetTarget() << endl;
}

int main() {
//    Route r;
//
//    PrintRoute({});
//    PrintRoute({"Moscow", "Vladivostok"});

    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString &s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
    return 0;
}