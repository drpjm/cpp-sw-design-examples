#include "fold.hpp"
#include "spdlog/spdlog.h"
// For the std::function container
#include <functional>
#include <limits>

// Some free functions to play with!
auto maximum(int left, int right){
    if(left > right) return left;
    return right;
}

auto minimum(int left, int right){
    if(left < right) return left;
    return right;
}

int main() {

    spdlog::info("Testing the fold function!");

    // Plain old array of ints!
    int data[] { 100, 200, 300, 400, 500 };
    // size_t - an unsigned integer type
    size_t data_len { 5 };

    // Fold allows us to process a chunk of data with any FUNCTION!

    // Example 1: just pass in the function!
    auto max = func_support::fold(maximum, data, data_len, 0);
    spdlog::info("Maximum value in the array: {}", max);

    // Example 2: throw into a std::function container!
    std::function<int(int,int)> min_fn = minimum;
    int max_int_val = std::numeric_limits<int>::max();  // Allows you to get various system numerical limits.
    auto min = func_support::fold(min_fn, data, data_len, max_int_val);
    spdlog::info("Minimum value in the array: {}", min);

    /**
     * Example 3: make a lambda!
     * We are assigning the lambda to the variable summation. It captures the bias variable!
     */ 
    int bias {1};
    auto summation = [bias](auto x, auto y) { return x + y + bias; };
    auto sum = func_support::fold(summation, data, data_len, 0);
    spdlog::info("Sum of the array with bias {0}: {1}", bias, sum);

}