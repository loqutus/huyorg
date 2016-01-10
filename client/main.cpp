#include "main.h"

int main(int argc, char** argv){
    optparse options(argc, argv);
    tcpclient client(options.get(std::string("host")), options.get(std::string("port")));
    std::string command = options.get("command");
    switch(command.c_str()){
        case "upload":
    }

	return 0;
}
