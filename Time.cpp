#include <string>

//
// Created by 97862 on 2023/2/18.
//
/**
 * @return eg:2012-05-06.21:47:59
 */
std::string getCurrentDateTime() {
    time_t now = time(nullptr);
    struct tm tstruct = *localtime(&now);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}