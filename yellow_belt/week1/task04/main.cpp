#include <iostream>
#include <map>

using namespace std;
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}