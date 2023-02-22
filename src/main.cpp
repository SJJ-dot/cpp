
#include <cstring>
#include <iostream>
#include <vector>
#include "Logger.h"
#include "json.hpp"
#include "base64.h"

int main() {
    std::string aaa = "https://www.toolhelper";
    debug(aaa);
    std::string aa = base64_encode(aaa);
    debug(aa);
    std::string bb = base64_decode(aa);

    debug(bb.append("a"));

    std::string ccc = "";
    char  a= 0xff;
    unsigned char  b= a;
    debug(std::to_string(a));
    debug(std::to_string(b));

}