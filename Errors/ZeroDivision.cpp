#include "exception"
#include "string"

class ZeroDivisionError : public std::exception {
public:
    explicit ZeroDivisionError(std::string message) : message{std::move(message)} {}

    const char *what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message{};
};