#ifndef TECHDEVCOMPLEX_COMPLEX_H
#define TECHDEVCOMPLEX_COMPLEX_H

#include "string"

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double _real, double _imaginary) {
        real = _real;
        imaginary = _imaginary;
    }

    explicit Complex(double _real) {
        real = _real;
        imaginary = 0;
    }

    Complex() {
        real = 0;
        imaginary = 0;
    }

    [[maybe_unused]] void setReal(double _real) {
        this->real = _real;
    }

    [[maybe_unused]] void setImg(double _imaginary) {
        this->imaginary = _imaginary;
    }

    double getReal() const;

    double getImg() const;

    double abs() const;

    Complex pow(int exp) const;

    Complex operator+(const Complex other) const;

    Complex operator-(const Complex other) const;

    Complex operator*(const Complex other) const;

    Complex operator*(const double number) const;

    Complex operator/(const Complex other) const;

    Complex operator/(const double number) const;

    bool operator==(Complex other) const;

    bool operator!=(Complex other) const;

    bool operator>(Complex other) const;

    bool operator>(double other) const;

    bool operator<(Complex other) const;

    bool operator<(double other) const;

    std::string toString() const;

    friend std::ostream &operator<<(std::ostream &os, Complex obj);
};

#endif //TECHDEVCOMPLEX_COMPLEX_H
