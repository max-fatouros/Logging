//
// Created by max on 01/06/22.
//

#include "Logging.h"
#include <iostream>

Logging::Logging(int LOG_LEVEL) : LOG_LEVEL(LOG_LEVEL) {
    #ifdef DEBUG
        this->LOG_LEVEL = levels::LDEBUG;
    #elifdef INFO
        this->LOG_LEVEL = levels::LINFO;
    #elifdef WARNING
        this->LOG_LEVEL = levels::LWARNING;
    #elifdef ERROR
        this->LOG_LEVEL = levels::LERROR;
    #elifdef CRITICAL
        this->LOG_LEVEL = levels::LCRITICAL;
    #endif

}

void Logging::debug(const char *output) const {
    if (LOG_LEVEL >= levels::LDEBUG) {
        print(output, COLORS::GREEN);
    }
}

void Logging::info(const char *output) {
    if (LOG_LEVEL >= Logging::levels::LINFO) {
        print(output, COLORS::BLUE);
    }
}

void Logging::warning(const char *output) {
    if (LOG_LEVEL >= Logging::levels::LWARNING) {
        print(output, COLORS::YELLOW);
    }
}

void Logging::error(const char *output) {
    if (LOG_LEVEL >= Logging::levels::LERROR) {
        print(output, COLORS::ORANGE);
    }
}

void Logging::critical(const char *output) {
    if (LOG_LEVEL >= Logging::levels::LCRITICAL) {
        print(output, COLORS::RED);
    }
}

void Logging::print(const char *string, int color) const {
    std::string output = "\033[";  ///< Escape code for Ascii color code
    output += "38;2;";  ///< Escape code for the r;g;b color code to follow
    output += COLOR_CODE[color];
    output += "m";

    output += string;

    output += "\033[;0m";  ///< Reset code
    std::cout << output << std::endl;
}

