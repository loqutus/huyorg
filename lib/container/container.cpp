#include "container.h"

container::container(std::string host, std::string port)
    : host(host), port(port), url("http://" + host + ":" + port + ":/") {}

std::list<std::string> container::get_containers() {
  std::string url_containers =
      std::string(this->url.c_str() + "containers/json")
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
    return std::list<std::string>;
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
  httpclient http_client(this->url.c_str() + "containers/create");
  auto response = http_client.post(body_create);
  json json_object(response);
  auto map = json_object.get_map();
  std::string container_id = map["Id"];
  return container_id;
}

bool container::run_container(std::string container_id) {
  httpclient http_client(this->url.c_str() + "containers/" + container_id +
                         "/start");
  auto response_run = http_client.post(std::string(""));
  return true;
}

bool container::destroy_container(std::string container_id) {
  httpclient http_client(this->url.c_str() + "containers/" + container_id +
                         "/kill");
  auto response = http_client.post(std::string(""));
  return true;
}
