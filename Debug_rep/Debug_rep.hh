#ifndef DEBUG_REP
#define DEBUG_REP

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
std::string debug_rep(const T& t)
{
    std::ostringstream ret;

    ret << t;

    return ret.str();
}

#endif