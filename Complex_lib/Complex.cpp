#include "exception"
#include <cmath>
#include "sstream"

#include "Complex.h"
#include "../Errors/ZeroDivision.h"


const double EPS = 1e-9;

bool Eq(double num1, double num2) {
    return std::abs(num1 - num2) < EPS;
}


double Complex::getReal() const {
    return this->real;
}

double Complex::getImg() const {
    return this->imaginary;
}

double Complex::abs() const {
    return std::sqrt(std::pow(this->real, 2) + std::pow(this->imaginary, 2));
}

Complex Complex::pow(int exp) const {
    double abs = this->abs();

    if (abs < EPS)
        throw ZeroDivisionError("Try to divide by 0");

    double expPhi = std::acos(this->real / abs) * exp;

    double cosExpPhi = std::cos(expPhi);
    double sinExpPhi = std::sin(expPhi);

    return Complex(cosExpPhi, sinExpPhi) * std::pow(abs, exp);
}

Complex Complex::operator+(const Complex other) const {
    return {this->real + other.real, this->imaginary + other.imaginary};
}

Complex Complex::operator-(const Complex other) const {
    return {this->real - other.real, this->imaginary - other.imaginary};
}

Complex Complex::operator*(const Complex other) const {
    return {this->real * other.real - this->imaginary * other.imaginary,
            this->real * other.imaginary + this->imaginary * other.real};
}

Complex Complex::operator*(const double number) const {
    return {this->real * number, this->imaginary * real};
}

Complex Complex::operator/(const Complex other) const {
    if (other.real < EPS and other.imaginary < EPS) {
        throw ZeroDivisionError("Try to divide by Complex(0, 0)");
    }

    double divisor = other.real * other.real + other.imaginary * other.imaginary;
    return Complex((this->real * other.real + this->imaginary * other.imaginary),
                   (this->imaginary * other.real - this->real * other.imaginary)) / divisor;
}

Complex Complex::operator/(const double number) const {
    if (number < EPS) {
        throw ZeroDivisionError("Try to divide by 0");
    }
    return {this->real / number, this->imaginary / number};
}

bool Complex::operator==(Complex other) const {
    return Eq(this->real, other.real) && Eq(this->imaginary, other.imaginary);
}

bool Complex::operator!=(Complex other) const {
    return !Eq(this->real, other.real) || !Eq(this->imaginary, other.imaginary);
}

bool Complex::operator>(Complex other) const {
    return this->abs() > other.abs();
}

bool Complex::operator>(double other) const {
    return this->abs() > other;
}

bool Complex::operator<(Complex other) const {
    return this->abs() < other.abs();
}

bool Complex::operator<(double other) const {
    return this->abs() < other;
}

std::string Complex::toString() const {
    std::stringstream ss;
    ss << this->real << (this->imaginary < 0 ? "" : "+") << this->imaginary << "i";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, Complex complex) {
    os << complex.toString();

    return os;
}