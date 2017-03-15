#include "httpclient.h"

httpclient::httpclient(std::string url, std::string data)
    : url(url), data(data){};

std::string httpclient::get() {
    try {
        curlpp::Cleanup myCleanup;
        curlpp::Easy myRequest;
        std::stringstream os;
        curlpp::options::WriteStream ws(&os);
        myRequest.setOpt(ws);
        myRequest.setOpt<curlpp::Options::Url>(this->url.c_str());
        std::list<std::string> headers;
        headers.push_back("User-Agent: huyorg/0.0.1");
        headers.push_back("Accept: */*");
        headers.push_back("Accept-Encoding: gzip");
        headers.push_back("Connection: close");
        myRequest.setOpt(new curlpp::Options::HttpHeader(headers));
        myRequest.perform();
        std::string result;
        os >> result;
        return result;
    }

    catch (curlpp::RuntimeError &e) {
        return std::string("RERROR");
    }

    catch (curlpp::LogicError &e) {
        return std::string("LERROR");
    }
}

std::string httpclient::post() {
    try {
        curlpp::Cleanup myCleanup;
        curlpp::Easy myRequest;
        std::stringstream os;
        curlpp::options::WriteStream ws(&os);
        myRequest.setOpt(ws);
        myRequest.setOpt<curlpp::Options::Url>(this->url.c_str());
        std::list<std::string> headers;
        headers.push_back("User-Agent: huyorg/0.0.1");
        headers.push_back("Accept: */*");
        headers.push_back("Accept-Encoding: gzip");
        headers.push_back("Content-Type: application/json");
        // headers.push_back("Content-Length: 0");
        headers.push_back("Connection: close");
        myRequest.setOpt(new curlpp::Options::HttpHeader(headers));
        myRequest.setOpt(new curlpp::options::PostFields(this->data.c_str()));
        myRequest.setOpt(
            new curlpp::options::PostFieldSize(this->data.length()));
        myRequest.perform();
        std::string result;
        os >> result;
        return result;
    }

    catch (curlpp::RuntimeError &e) {
        return std::string(e.what());
    }

    catch (curlpp::LogicError &e) {
        return std::string(e.what());
    }
}
