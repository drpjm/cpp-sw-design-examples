#include "func_support.hpp"
#include "spdlog/spdlog.h"
// For the std::function container
#include <functional>

int main() {

    spdlog::info("Testing the CountIf!");

    func_support::CountIf count_a { 'a' };
    auto num_as = count_a("My name is Patrick!");
    spdlog::info("My name is Patrick! has {} a's", num_as);

    func_support::CountIf count_z { 'z' };
    auto num_zs = count_z("Zzz zzz zzt!");
    spdlog::info("Zzz zzz zzt! has {} z's", num_zs);
}