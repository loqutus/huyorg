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

int logging::write(std::string message) {
    logfile << message << std::endl;
    return 0;
}
