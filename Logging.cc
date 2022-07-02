//
// Created by max on 01/06/22.
//

#include "Logging.h"
#include <iostream>

Logging::Logging(int LOG_LEVEL) : LOG_LEVEL(LOG_LEVEL) {
    #ifdef DEBUG
        this->LOG_LEVEL = Levels::eDEBUG;
    #elifdef INFO
        this->LOG_LEVEL = Levels::eINFO;
    #elifdef WARNING
        this->LOG_LEVEL = Levels::eWARNING;
    #elifdef ERROR
        this->LOG_LEVEL = Levels::eERROR;
    #elifdef CRITICAL
        this->LOG_LEVEL = Levels::eCRITICAL;
    #endif

}

void Logging::debug(const char *output) const {
    if (LOG_LEVEL >= Levels::eDEBUG) {
        print(output, COLORS::eGREEN);
    }
}

void Logging::info(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eINFO) {
        print(output, COLORS::eBLUE);
    }
}

void Logging::warning(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eWARNING) {
        print(output, COLORS::eYELLOW);
    }
}

void Logging::error(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eERROR) {
        print(output, COLORS::eORANGE);
    }
}

void Logging::critical(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eCRITICAL) {
        print(output, COLORS::eRED);
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

