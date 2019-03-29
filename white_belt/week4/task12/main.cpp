#include <iostream>
#include <exception>
#include <string>
#include <system_error>
#include <sstream>
#include "timeserver.cpp"

using namespace std;

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception &e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}