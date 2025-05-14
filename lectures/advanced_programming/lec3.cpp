// varrables live inside a scope: block scope, class scope, global scope, ...

// string contents are stored on the heap

// c++ containers, such as array, vector, map

// std::array: fixed-sized; size is known at compile time, no insertion/deletion
// arrays are completely stored on the stack

// std::vector: size is not known at compile time, i.e. we cann add or remove elements.
// the content of a vector is stored on the heap

// std::array, std::vector are contihuous containers, eheir elements are contihuous in memory
// (important for caching)

#include <array>
#include <vector>
#include <iostream>
int main(int argc, const char** argv) {
    std::array<int, 3> x_unit_vector{1, 0, 0};  //before c++17
    // std::array x_unit_vector{1, 0.0};           //c++17
    std::vector<double> grades{62.5, 43.0, 21.5};

    // accessing elements
    x_unit_vector.at(5);    // at() check bounds - error
    x_unit_vector[5];       // no bounds checking - may run silently (可能報錯， 也可能不報錯)


    // working with vectors
    // 1 construction
    // 1.1 vector with 10 elements initialized to 0.0
    std::vector<double> grades_list(10,0.0);

    // 1.2 vector with 3 elements
    std::vector<double> grades_list2={55.0, 95.0, 70.0};
    for(auto var : grades_list2)
    {
        std::cout << var << std::endl;   
    }

    // push_back: append elements
    grades_list.push_back(85.0);
    return 0;
}