#include "httpclient.h"

httpclient::httpclient(std::string url, std::string body)
    : url(url), data(body.c_str()){};

size_t httpclient::readData(char *buffer, size_t size, size_t nitems) {
    strncpy(buffer, data, size * nitems);
    return size * nitems;
}

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
        return std::string("ERROR");
    }

    catch (curlpp::LogicError &e) {
        return std::string("ERROR");
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
        myRequest.setOpt(new curlpp::Options::ReadFunction(
            curlpp::types::ReadFunctionFunctor(this->readData)));
        std::list<std::string> headers;
        headers.push_back("User-Agent: huyorg/0.0.1");
        headers.push_back("Accept: */*");
        headers.push_back("Accept-Encoding: gzip");
        headers.push_back("Connection: close");
        myRequest.setOpt(new curlpp::Options::HttpHeader(headers));
        int size = strlen(this->data);
        myRequest.setOpt(new curlpp::Options::InfileSize(size));
        myRequest.setOpt(new curlpp::Options::Upload(true));
        myRequest.perform();
        std::string result;
        os >> result;
        return result;
    }

    catch (curlpp::RuntimeError &e) {
        return std::string("ERROR");
    }

    catch (curlpp::LogicError &e) {
        return std::string("ERROR");
    }
}
