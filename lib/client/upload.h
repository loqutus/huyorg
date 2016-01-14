//
// Created by Ruslan Gustomyasov on 10/01/16.
//

#ifndef PROJECT_UPLOAD_H
#define PROJECT_UPLOAD_H
#include "../tcpclient/tcpclient.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

class upload {
public:
    upload(std::string filename, tcpclient& client);
};


#endif //PROJECT_UPLOAD_H
