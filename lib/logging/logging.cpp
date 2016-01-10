//
// Created by Ruslan Gustomyasov on 21/11/15.
//

#include "logging.h"

logging::logging(std::string logfilename) {
    logfile.open(logfilename, std::ios::out);
}

logging::~logging() {
    logfile.close();
}

int logging::write(const char *left, std::string right) {
    time_t rawtime;
    time(&rawtime);
    std::string time_str(ctime(&rawtime));
    logfile << time_str << " " << left << " " << right << std::endl;
    return 0;
}
