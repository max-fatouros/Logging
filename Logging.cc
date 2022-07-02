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
        std::string s;
        s += "[DEBUG]\t\t";
        s += output;
        print(s, COLORS::eGREEN);
    }
}

void Logging::info(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eINFO) {
        std::string s;
        s += "[INFO]\t\t";
        s += output;
        print(s, COLORS::eBLUE);
    }
}

void Logging::warning(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eWARNING) {
        std::string s;
        s += "[WARNING]\t";
        s += output;
        print(s, COLORS::eYELLOW);
    }
}

void Logging::error(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eERROR) {
        std::string s;
        s += "[ERROR]\t\t";
        s += output;
        print(s, COLORS::eORANGE);
    }
}

void Logging::critical(const char *output) {
    if (LOG_LEVEL >= Logging::Levels::eCRITICAL) {
        std::string s;
        s += "[CRITICAL]\t";
        s += output;
        print(s, COLORS::eRED);
    }
}

void Logging::print(std::string output, int color) const {
    std::string s = "\033[";  ///< Escape code for Ascii color code
    s += "38;2;";  ///< Escape code for the r;g;b color code to follow
    s += COLOR_CODE[color];
    s += "m";

    s += output;

    s += "\033[;0m";  ///< Reset code
    std::cout << s << std::endl;
}

