#include "slave_client.h"

slave_client::slave_client(std::string slave_host, std::string slave_port) {
  this->slave_host = slave_host;
  this->slave_port = slave_port;
}

std::list<std::string> slave_client::get_containers() {
  tcpclient tcp_client(this->slave_host, this->slave_port);
  tcp_client.write("{\"action\": \"get_containers\"}");
  std::string answer = tcp_client.read();
  json json_obj(answer);
  auto containers_list = json_obj.get_list();
  return containers_list;
}

std::string slave_client::run_container(std::string image,
                                        std::string command) {
  std::string request = "";
  request += "{\"action\": \"run_container\", \"image\" : \"";
  request += image;
  request += "\",\"command\":\"";
  request += command;
  request += "\"}";
  tcpclient tcp_client(this->slave_host, this->slave_port);
  tcp_client.write(request);
  auto answer = tcp_client.read();
  return answer;
}

std::string slave_client::destroy_container(std::string container_id) {
  std::string request = "";
  request += "{\"action\": \"destroy_container\", \"container_id\" : \"";
  request += container_id;
  request += "\"}";
  tcpclient tcp_client(this->slave_host, this->slave_port);
  tcp_client.write(request);
  auto answer = tcp_client.read();
  return answer;
}
