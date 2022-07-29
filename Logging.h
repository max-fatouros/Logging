//
// Created by max on 01/06/22.
//

#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H

#include <string>

class Logging {
public:
    explicit Logging(int LOG_LEVEL, bool clear=false);

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
    const char *logOut = "logs.txt";
    const char *logVars = "log_vars.txt";


    enum COLOR {
        eRED,
        eORANGE,
        eYELLOW,
        eBLUE,
        eGREEN
    };

    /// A COLOR enum value will be passed to an
    /// index of this to find the corresponding string value;
    ///
    /// List of 8 bit r;g;b color values
    /// Index corresponds to COLOR enum
    const char *COLOR_CODE[5] {
    "204;0;0",    ///< eRED
    "255;128;0",  ///< eORANGE
    "240;199;6",  ///< eYELLOW
    "0;111;184",  ///< eBLUE
    "0;170;0"     ///< eGREEN
    };

    void print(std::string output, int color) const;

		// Just some comments
		// This is for testing clang-format
		// delete me after testing

};


#endif //LOGGING_LOGGING_H
