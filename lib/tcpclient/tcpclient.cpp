#include "tcpclient.h"

tcpclient::tcpclient(std::string host, std::string port)
    : host(host)
    , port(port)
{
}

bool tcpclient::write_string(std::string message)
{
    network_stream.expires_from_now(boost::posix_time::seconds(60));
    network_stream.connect(host, port);
    std::string answer;
    if (!network_stream)
        return false;
    network_stream << message;
    network_stream.flush();
    return true;
}

std::string tcpclient::read_string()
{
    std::string read_data;
    network_stream >> read_data;
    return read_data;
}
