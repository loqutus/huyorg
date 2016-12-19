#include "container.h"

container::container(std::string host, std::string port)
    : host(host), port(port) {}

std::list<std::string> container::get_containers() {
  httpclient http_client(this->host, this->port);
  std::string json_string = http_client.get(std::string("/containers/json"));
  json json_object(json_string);
  auto list_of_maps = json_object.get_list_of_maps();
  std::list<std::string> list_of_strings;
  for (auto map : list_of_maps) {
    list_of_strings.push_back(map["Id"]);
  }
  return list_of_strings;
}

std::string container::create_container(std::string image,
                                        std::string command) {
  std::string body_create;
  body_create += "{\"image\":\"";
  body_create += image;
  body_create += "\",\"command\":\"";
  body_create += command;
  body_create += "\"}\n";
  httpclient http_client(this->host, this->port);
  auto response = http_client.post("/containers/create", body_create);
  json json_object(response);
  auto map = json_object.get_map();
  std::string container_id = map["Id"];
  return container_id;
}

bool container::run_container(std::string container_id) {
  httpclient http_client(this->host, this->port);
  std::string run_url = "/containers/" + container_id + "/start";
  auto response_run = http_client.post_zero_body(run_url);
  return true;
}

bool container::destroy_container(std::string container_id) {
  httpclient http_client(this->host, this->port);
  std::string url = "/containers/";
  url += container_id;
  url += "/kill";
  auto response = http_client.post_zero_body(url);
  return true;
}
