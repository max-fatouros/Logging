//
// Created by max on 01/06/22.
//

#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H

#include <string>

class Logging {
public:
  explicit Logging(int LOG_LEVEL);

  enum Level {
    eCRITICAL,
    eERROR,
    eWARNING,
    eINFO,
    eDEBUG
  };

  void debug(const char *output) const;
  void info(const char *output);
  void warning(const char *output);
  void error(const char *output);
  void critical(const char *output);

  void log(const char *key, const char *output);

private:
  int LOG_LEVEL;
  const char *logOut  = "logs.txt";
  const char *logVars = "log_vars.txt";

  enum COLOR {
    eRED,
    eORANGE,
    eYELLOW,
    eBLUE,
    eGREEN
  };

  /// A COLOR enum value will be passed to the
  /// index of this to find the corresponding string value;
  ///
  /// List of 8 bit color values
  /// Index corresponds to COLOR enum
  const char *COLOR_CODE[5]{
      "124",  ///< eRED
      "208",  ///< eORANGE
      "220",  ///< eYELLOW
      "26",   ///< eBLUE
      "34"    ///< eGREEN
  };

  void print(std::string output, int color) const;
};

extern Logging logs;

#endif//LOGGING_LOGGING_H
