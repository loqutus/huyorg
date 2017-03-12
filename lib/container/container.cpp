#include "container.h"

container::container(std::string host, std::string port)
    : host(host), port(port), url("http://" + host + ":" + port + ":/") {}

std::list<std::string> container::get_containers() {
    std::string url_json("containers/json");
    std::string url_containers(this->url + url_json);
    httpclient http_client(url_containers);
    std::string json_string = http_client.get();
    json json_object(json_string);
    auto list_of_maps = json_object.get_list_of_maps();
    if (!list_of_maps.empty()) {
        std::list<std::string> list_of_strings;
        for (auto map : list_of_maps) {
            list_of_strings.push_back(map["Id"]);
        }
        return list_of_strings;
    } else {
        return std::list<std::string>();
    }
}

std::string container::create_container(std::string image,
                                        std::string command) {
    std::string body_create;
    body_create += "{\"image\":\"";
    body_create += image;
    body_create += "\",\"command\":\"";
    body_create += command;
    body_create += "\"}\n";
    std::string url_string = this->url + std::string("containers/create");
    httpclient http_client(url_string, body_create);
    auto response = http_client.post();
    json json_object(response);
    auto map = json_object.get_map();
    std::string container_id = map["Id"];
    return container_id;
}

std::string container::run_container(std::string container_id) {
    std::string url_string = this->url + std::string("containers/") +
                             container_id + std::string("/start");
    httpclient http_client(url_string, std::string(""));
    auto response = http_client.post();
    return response;
}

std::string container::destroy_container(std::string container_id) {
    std::string url_string = this->url + std::string("containers/") +
                             container_id + std::string("/kill");
    httpclient http_client(url_string, std::string(""));
    auto response = http_client.post();
    return response;
}
