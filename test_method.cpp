#include <iostream>
#include <sstream>
#include "ConcreteClassX.h"
#include "ConcreteClassY.h"

class CoutRedirect {
    std::stringstream buffer;
    std::streambuf* old;
public:
    CoutRedirect() : old(std::cout.rdbuf(buffer.rdbuf())) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
    std::string str() const { return buffer.str(); }
};

int main() {
    CoutRedirect redirect;

    ConcreteClassX x;
    x.templateMethod();
    ConcreteClassY y;
    y.templateMethod();
    std::string output = redirect.str();

    if (output.find("PrimitiveOperationA implementation from X") == std::string::npos) return 1;
    if (output.find("PrimitiveOperationB implementation from X") == std::string::npos) return 1;
    if (output.find("PrimitiveOperationA implementation from Y") == std::string::npos) return 1;
    if (output.find("PrimitiveOperationB implementation from Y") == std::string::npos) return 1;

    std::cout << "All tests passed!\n";
    return 0;
}
