#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port):
host(host), port(port){
}

bool tcpclient::write_string(std::string message) {
    this->network_stream.expires_from_now(boost::posix_time::seconds(60));
    this->network_stream.connect(host, port);
    std::string answer;
	if(!this->network_stream)
		return false;
	this->network_stream << message;
	this->network_stream.flush();
    this->network_stream >> answer;
    if(answer!=std::string("OK"))
        return false;
    return true;
}


std::string tcpclient::read_string() {
	std::string read_data;
	this->network_stream >> read_data;
	return read_data;
}
