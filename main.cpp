
#include <cstring>
#include <iostream>
#include "Logger.h"


int main() {
    int n = 20;
    while (n--) {
        debug("HELLO1:"+ std::to_string(n));
        info("HELLO1:"+ std::to_string(n));
        error("HELLO1:"+ std::to_string(n));
    }
}