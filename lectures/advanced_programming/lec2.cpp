#include <iostream>
#include <string>

const double pi = 3.1415;

int main(int argc, char const *argv[])
{
    float a{static_cast<float>(39.123 + pi)};
    int b;

    std::cout << "a=" << a << " b = " << b << std::endl;
    b = a;
    std::string message{"The answer to everything is "};
    std::cout << message << std::to_string(b) << std::endl;

    // how to initialize basic data types
    // avoid
    int b = 0; // classic way: var = exp
    int b(0);  // classic way: var(expression list); basic types: =, classes: constructor

    // more preferred: 因為和複雜的type的init一樣
    int b{0}; // since c++11
    int b{};  // since c++11: defauts to 0 for int

    // convert type: static_cast<int>(a)
    return 0;
}
