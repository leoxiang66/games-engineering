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
#include <algorithm>
#include <functional>

void offset2(int &);
int offset(int);
int offset3(const int &x); // or, equivalent: int& const x
int offset4(int x, int step);

template <typename T>
T offset5(T x);

double offset(double);

// function type in argument: std::function<return_type(argumemt_tupes)>
void apply_bonus(double &grade, std::function<double(double, double)> operation);

int main(int argc, const char **argv)
{
    std::array<int, 3> x_unit_vector{1, 0, 0}; // before c++17
    // std::array x_unit_vector{1, 0.0};           //c++17
    std::vector<double> grades{62.5, 43.0, 21.5};

    // accessing elements
    // x_unit_vector.at(5); // at() check bounds - error
    x_unit_vector[5]; // no bounds checking - may run silently (可能報錯， 也可能不報錯)

    // working with vectors
    // 1 construction
    // 1.1 vector with 10 elements initialized to 0.0
    std::vector<double> grades_list(10, 0.0);

    // 1.2 vector with 3 elements
    std::vector<double> grades_list2 = {55.0, 95.0, 70.0};
    for (auto var : grades_list2)
    {
        std::cout << var << std::endl;
    }

    // push_back: append elements
    grades_list.push_back(85.0);

    // iterate the container
    // use auto&
    for (auto &i : grades_list)
    {
    }

    int a = 2;
    offset2(a);
    std::cout << a << std::endl;

    // lambda expression
    // apply an anonymous function on every element of grades
    // general syntax: [captured_variable](arguments) -> return_type {body}
    // captured variable: additional variables from our program (optional)
    // capture all by value: [=]
    // capture all by reference: [&]
    // capture none: []
    // capture certain variables by reference: [&var1, &var2]
    // return_type is optional if it can be inferred from the implementation
    std::for_each(grades.begin(), grades.end(),
                  [](double &grade) -> void
                  {
                      if (grade <= 4.0 && grade > 1.0)
                      {
                          grade += 0.3;
                      }
                  });

    int counter{0};
    std::for_each(grades.begin(), grades.end(),
                  [&counter](double &grade)
                  {
                      grade = -1;
                      counter++;
                  });

    // passinng functions to functions
    // 1 define a lambda function
    auto super_bonus = [](double x, double step)
    { return x + 3 * step; };

    for (auto &grade : grades)
    {
        apply_bonus(grade, super_bonus);
    }

    return 0;
}

// pass by value: copies the passed argument into the function
// the original stays untouched, but copying can be costly
int offset(int x)
{
    int y = x + 40;
    return y;
}

// pass by reference: shares the passed argument with the function
// no copy overhead, but the function may (unintentionally) modify the original
void offset2(int &x)
{
    x = x + 40;
}

// pass by const reference: shares the passed argument with the function, in
// a read-only fashion
// no copy overhead and the function cannot modify the original
int offset3(const int &x)
{
    int y = x + 40;
    return y;
}

// overloading: implement different behaviour in a function depending on the
// input type
double offset(double x)
{
    double y = x + 40.0;
    return y;
}

// default arguments: must come after all the no-default arguments
int offset4(int x, int step = 40)
{
    return x + step;
}

// overloading with templates
template <typename T>
T offset5(T x)
{
    return x + static_cast<T>(40); // automatic type deduction
}