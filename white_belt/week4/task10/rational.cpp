#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if (denominator == 0) {
            throw invalid_argument("");
        }
        const int factor = GetCommonDivisor(numerator, denominator);
        num = numerator / factor;
        denom = denominator / factor;

        if (denom < 0) {
            denom = -denom;
            num = -num;
        }
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
    int num = 0, denom = 1;

    static int GetCommonDivisor(int a, int b) {
        int c = 0;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
};

bool operator==(const Rational &r1, const Rational &r2) {
    return r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator();
}

Rational operator+(const Rational &r1, const Rational &r2) {
    return {r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator(), r1.Denominator() * r2.Denominator()};
}

Rational operator-(const Rational &r1, const Rational &r2) {
    return {r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator(), r1.Denominator() * r2.Denominator()};
}

Rational operator*(const Rational &r1, const Rational &r2) {
    return {r1.Numerator() * r2.Numerator(), r1.Denominator() * r2.Denominator()};
}

Rational operator/(const Rational &r1, const Rational &r2) {
    if (r2.Numerator() == 0) {
        throw domain_error("");
    }
    return r1 * Rational(r2.Denominator(), r2.Numerator());
}

ostream &operator<<(ostream &stream, const Rational &r1) {
    return stream << r1.Numerator() << "/" << r1.Denominator();
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

bool operator<(const Rational &r1, const Rational &r2) {
    return (r1 - r2).Numerator() < 0;
}