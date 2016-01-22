#ifndef PROJECT_LOGGING_H
#define PROJECT_LOGGING_H

#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>

class logging {
    std::ofstream logfile;
public:
    logging(std::string logfilename);

    ~logging();

    int write(const char* left, std::string right=std::string(""));
};

#endif //PROJECT_LOGGING_H
