//
// Created by Ruslan Gustomyasov on 21/11/15.
//

#ifndef PROJECT_CONFREADER_H
#define PROJECT_CONFREADER_H

#include <string>
#include <fstream>
#include <map>
#include <sstream>

class confreader {
public:
    confreader(std::string confname);

    ~confreader();

    std::string get(std::string key);

private:
    std::ifstream conffile;
    std::map<std::string, std::string> conf_map;
};

#endif //PROJECT_CONFREADER_H
