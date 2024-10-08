#ifndef FOLD_HPP
#define FOLD_HPP

#include <cstdint>
#include <cstddef>

namespace func_support {

/**
 * Templates allow you specify typenames that are figured out
 * at COMPILE time. Also known as compile time polymorphism!
 */

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input_data, size_t length, Out init_val){
    
    auto result {init_val};
    for(size_t i {}; i < length; i++){
        result = function(result, input_data[i]);
    }
    return result;
}

struct CountIf
{
    CountIf(char x) : x_ { x } {};
    size_t operator()(const char* str){
        size_t index {};
        size_t result {}; 
        while(str[index]){
            if (str[index] == x_) result++;
            index++;
        }
        return result;
    }
    private:
        const char x_;
};

}

#endif