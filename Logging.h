//
// Created by max on 01/06/22.
//

#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H

class Logging {
public:
    enum levels {
        LCRITICAL,
        LERROR,
        LWARNING,
        LINFO,
        LDEBUG
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
        RED,
        ORANGE,
        YELLOW,
        BLUE,
        GREEN
    };

    /// A COLORS enum value will be passed to an
    /// index of this to find the corresponding string value;
    ///
    /// List of 8 bit r;g;b color values
    /// Index corresponds to COLORS enum
    const char *COLOR_CODE[5] {
    "204;0;0",  ///< RED
    "255;128;0",  ///< ORANGE
    "240;199;6",  ///< YELLOW
    "0;111;184",  ///< BLUE
    "0;170;0"  ///< GREEN
    };

    void print(const char *string, int color) const;

};


#endif //LOGGING_LOGGING_H
