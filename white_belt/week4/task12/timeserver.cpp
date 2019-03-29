#include <iostream>

using namespace std;

//string AskTimeServer() {
//    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
//       * нормальный возврат строкового значения
//       * выброс исключения system_error
//       * выброс другого исключения с сообщением.
//    */
//    //  system_error
////    stringstream ss;
////    ss <<"Oops! It's system error!";
////    throw system_error(ss.str());
//    //  Normal result
//    return "15:10:49";
//}

class TimeServer {
public:
    string GetCurrentTime() {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля LastFetchedTime
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
        try {
            LastFetchedTime = AskTimeServer();
            return LastFetchedTime;
        } catch (system_error &se) {
            return LastFetchedTime;
        }
    }

private:
    string LastFetchedTime = "00:00:00";
};