#include "main.h"

int main(int argc, char** argv){
    optparse options(argc, argv);
    tcpclient client(options.get(std::string("host")), options.get(std::string("port")));
	return 0;
}
