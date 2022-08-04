//
// Created by max on 01/06/22.
//

#include "Logging.h"
#include <fstream>
#include <iostream>

Logging::Logging(int LOG_LEVEL) : LOG_LEVEL(LOG_LEVEL) {
  // clang-format off

  #ifdef DEBUG
    this->LOG_LEVEL = Level::eDEBUG;
  #elif defined(INFO)
    this->LOG_LEVEL = Level::eINFO;
  #elif defined(WARNING)
    this->LOG_LEVEL = Level::eWARNING;
  #elif defined(ERROR)
    this->LOG_LEVEL = Level::eERROR;
  #elif defined(CRITICAL)
    this->LOG_LEVEL = Level::eCRITICAL;
  #endif

  // clang-format on


  std::ofstream file(logOut, std::fstream::trunc);
  file.close();

  std::ofstream varFile(logVars, std::fstream::trunc);
  varFile.close();
}

void Logging::debug(const char *output) const {
  if (LOG_LEVEL >= Level::eDEBUG) {
    std::string s;
    s += "[DEBUG]\t\t";
    s += output;
    std::ofstream file(logOut, std::fstream::app);
    file << s << std::endl;
    file.close();
    print(s, COLOR::eGREEN);
  }
}

void Logging::info(const char *output) {
  if (LOG_LEVEL >= Logging::Level::eINFO) {
    std::string s;
    s += "[INFO]\t\t";
    s += output;
    std::ofstream file(logOut, std::fstream::app);
    file << s << std::endl;
    file.close();
    print(s, COLOR::eBLUE);
  }
}

void Logging::warning(const char *output) {
  if (LOG_LEVEL >= Logging::Level::eWARNING) {
    std::string s;
    s += "[WARNING]\t";
    s += output;
    std::ofstream file(logOut, std::fstream::app);
    file << s << std::endl;
    file.close();
    print(s, COLOR::eYELLOW);
  }
}

void Logging::error(const char *output) {
  if (LOG_LEVEL >= Logging::Level::eERROR) {
    std::string s;
    s += "[ERROR]\t\t";
    s += output;
    std::ofstream file(logOut, std::fstream::app);
    file << s << std::endl;
    file.close();
    print(s, COLOR::eORANGE);
  }
}

void Logging::critical(const char *output) {
  if (LOG_LEVEL >= Logging::Level::eCRITICAL) {
    std::string s;
    s += "[CRITICAL]\t";
    s += output;
    std::ofstream file(logOut, std::fstream::app);
    file << s << std::endl;
    file.close();
    print(s, COLOR::eRED);
  }
}

void Logging::log(const char *key, const char *output) {
  std::ofstream file(logVars, std::fstream::app);
  file << "[" << key << "]:\t\t" << output << std::endl;
  file.close();
}

void Logging::print(std::string output, int color) const {
  std::string s = "\033[";///< Escape code for Ascii color code
  s += "38;2;";           ///< Escape code for the r;g;b color code to follow
  s += COLOR_CODE[color];
  s += "m";

  s += output;

  s += "\033[;0m";///< Reset code
  std::cout << s << std::endl;
}
