#include <iostream>
#include <string>

class CountIt {
    int count {1};
    std::string name {};
    public:
        CountIt(std::string name): name(name) {
        
        };

    int get_amount() {
        return count;
    }

    std::string get_name() {
        return name;
    }
    void operator ++(int){
         count++;
         }

};
