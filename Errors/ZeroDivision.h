#ifndef TECHDEVCOMPLEX_ZERODIVISION_H
#define TECHDEVCOMPLEX_ZERODIVISION_H

#include "exception"
#include "string"

class ZeroDivisionError : public std::exception {
private:
    std::string message{};

public:
    explicit ZeroDivisionError(std::string message) : message{std::move(message)} {}

    const char *what() const noexcept override{
        return message.c_str();
    };
};

#endif //TECHDEVCOMPLEX_ZERODIVISION_H
