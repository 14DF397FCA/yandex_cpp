#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


int GetCommonDivisor(int a, int b) {
    int c = 0;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        const int factor = GetCommonDivisor(numerator, denominator);
        if (denominator / factor < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        num = numerator / factor;
        denom = denominator / factor;
    }

    int Numerator() const {
        // Реализуйте этот метод
        return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return denom;
    }

private:
    // Добавьте поля
    int num = 0;
    int denom = 1;
};

bool operator==(const Rational &r1, const Rational &r2) {
    const int gcd = GetCommonDivisor(r1.Denominator(), r2.Denominator());
    int n = (r1.Denominator() * r2.Denominator()) / gcd;
    int l = n / r1.Denominator();
    int r = n / r2.Denominator();
    return (r1.Numerator() * l) == (r2.Numerator() * r);
}

bool operator<(const Rational &r1, const Rational &r2) {
    const int gcd = GetCommonDivisor(r1.Denominator(), r2.Denominator());
    int n = (r1.Denominator() * r2.Denominator()) / gcd;
    int l = n / r1.Denominator();
    int r = n / r2.Denominator();
    return (r1.Numerator() * l) < (r2.Numerator() * r);
}

Rational operator+(const Rational &r1, const Rational &r2) {
    const int gcd = GetCommonDivisor(r1.Denominator(), r2.Denominator());
    int n = (r1.Denominator() * r2.Denominator()) / gcd;
    int l = n / r1.Denominator();
    int r = n / r2.Denominator();
    return Rational((r1.Numerator() * l) + (r2.Numerator() * r), n);
}

Rational operator-(const Rational &r1, const Rational &r2) {
    const int gcd = GetCommonDivisor(r1.Denominator(), r2.Denominator());
    int n = (r1.Denominator() * r2.Denominator()) / gcd;
    int l = n / r1.Denominator();
    int r = n / r2.Denominator();
    return Rational((r1.Numerator() * l) - (r2.Numerator() * r), n);
}

Rational operator*(const Rational &r1, const Rational &r2) {
    return Rational(r1.Numerator() * r2.Numerator(), r1.Denominator() * r2.Denominator());
}

Rational operator/(const Rational &r1, const Rational &r2) {
    if (r2.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return Rational(r1.Numerator() * r2.Denominator(), r1.Denominator() * r2.Numerator());
}

ostream &operator<<(ostream &stream, const Rational &r1) {
    stream << r1.Numerator() << "/" << r1.Denominator();
    return stream;
}

istream &operator>>(istream &stream, Rational &r1) {
    int a = 0, b = 0;
    char c;
    stream >> a >> c >> b;
    if (stream && c == '/') {
        r1 = Rational(a, b);
    }
    return stream;
}

int main() {
    Rational r1, r2;
    char operation;
    try {
        cin >> r1 >> operation >> r2;
        if (operation == '+') {
            cout << r1 + r2 << endl;
        } else if (operation == '-') {
            cout << r1 - r2 << endl;
        } else if (operation == '*') {
            cout << r1 * r2 << endl;
        } else if (operation == '/') {
            try {
                cout << r1 / r2 << endl;
            } catch (domain_error &de) {
                cout << de.what();
            }
        }
    } catch (invalid_argument &ia) {
        cout << ia.what();
    }
    return 0;
}