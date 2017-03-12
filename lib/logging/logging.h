#ifndef PROJECT_LOGGING_H
#define PROJECT_LOGGING_H

#include "../confreader/confreader.h"
#include <algorithm>
#include <fstream>
#include <memory>
#include <string>
#include <time.h>

class logging {
  std::ofstream logfile;

public:
  logging(std::string logfilename);

  ~logging();

  int write(const char *left, std::string right = std::string(""));
  int write(std::string left);
};

extern logging log_obj;

#endif // PROJECT_LOGGING_H
