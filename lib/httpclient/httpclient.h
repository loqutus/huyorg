#ifndef PROJECT_HTTPCLIENT_H
#define PROJECT_HTTPCLIENT_H

#include "../tcpclient/tcpclient.h"
#include <string>

class httpclient {
	tcpclient tcp_client;
public:
	httpclient(std::string host, std::string port);
	std::string get(std::string url);
	std::string post(std::string url, std::string body);
};

#endif //PROJECT_HTTPCLIENT_H
