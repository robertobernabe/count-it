#include <iostream>
#include<countit/countit.hpp>

int main() {
    auto coffee = CountIt("coffee");
    coffee++;
    std::cout << coffee.get_name() << ": " << coffee.get_amount();
    
  return 0;
}