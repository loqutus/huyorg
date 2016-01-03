//
// Created by Ruslan Gustomyasov on 21/11/15.
//

#ifndef PROJECT_LOGGING_H
#define PROJECT_LOGGING_H

#include <fstream>
#include <string>

class logging {
    std::ofstream logfile;
public:
    logging(std::string logfilename);

    ~logging();

    int write(char* message);
};

#endif //PROJECT_LOGGING_H
