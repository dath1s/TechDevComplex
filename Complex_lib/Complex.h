#ifndef TECHDEVCOMPLEX_COMPLEX_H
#define TECHDEVCOMPLEX_COMPLEX_H

#include "string"

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double r = 0.0, double i = 0.0): real(r), imaginary(i) {}

    void setReal(double _real) {
        this->real = _real;
    }

    void setImg(double _imaginary) {
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
