//
// Created by max on 01/06/22.
//

#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H

class Logging {
public:
    enum Levels {
        eCRITICAL,
        eERROR,
        eWARNING,
        eINFO,
        eDEBUG
    };

    explicit Logging(int LOG_LEVEL);

    void debug(const char *output) const;
    void info(const char *output);
    void warning(const char *output);
    void error(const char *output);
    void critical(const char *output);

private:
    int LOG_LEVEL;

    enum COLORS {
        eRED,
        eORANGE,
        eYELLOW,
        eBLUE,
        eGREEN
    };

    /// A COLORS enum value will be passed to an
    /// index of this to find the corresponding string value;
    ///
    /// List of 8 bit r;g;b color values
    /// Index corresponds to COLORS enum
    const char *COLOR_CODE[5] {
    "204;0;0",    ///< eRED
    "255;128;0",  ///< eORANGE
    "240;199;6",  ///< eYELLOW
    "0;111;184",  ///< eBLUE
    "0;170;0"     ///< eGREEN
    };

    void print(const char *string, int color) const;

};


#endif //LOGGING_LOGGING_H
