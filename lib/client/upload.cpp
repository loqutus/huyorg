//
// Created by Ruslan Gustomyasov on 10/01/16.
//

#include "upload.h"
upload::upload(std::string filename, tcpclient& client) {
    std::ifstream t(filename.c_str());
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    client.send(str);
}