#include "main.h"

int main(int argc, char** argv){
    optparse options(argc, argv);
    tcpclient client(options.get(std::string("host")), options.get(std::string("port")));
	read_file file(options.get(std::string("json")));
	std::string file_str = file.read();
	client.write(file_str);
	std::cout << client.read() << std::endl;
	return 0;
}
