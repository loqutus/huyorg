#include "main.h"

int main(int argc, char **argv) {
  const std::string conf_file("../test/slave.conf");
  confreader conf(conf_file);
  logging log(conf.get(std::string("log")));
  log.write("starting slave");
  log.write("read config file", conf_file);
  const std::string server_host = conf.get(std::string("host"));
  log.write("host", server_host);
  const std::string server_port = conf.get(std::string("port"));
  log.write("port", server_port);
  container container_server(server_host, server_port);
  while (true) {
    tcpserver server(server_port);
    log.write("listening");
    server.accept();
    log.write("master connected");
    std::string s = server.read();
    json json_object(s);
    auto json_map = json_object.get_map();
    std::string action = json_map["action"];
    if (action == "run_container") {
      log_obj.write("run_container");
      std::string container_image = json_map["image"];
      log_obj.write("image:", container_image);
      std::string container_command = json_map["command"];
      log_obj.write("command:", container_command);
      std::string container_id =
          container_server.run_container(container_image, container_command);
      log_obj.write("id", container_id);
      server.write(container_id);
    } else if (action == "get_containers") {
      log_obj.write("get_containers");
      auto containers_list = container_server.get_containers();
      json json_containers_list(containers_list);
      auto containers_list_str = json_containers_list.get_string_from_list();
      log_obj.write(containers_list_str);
      server.write(containers_list_str);
    } else if (action == "destroy_container") {
      log_obj.write("destroy container");
      auto container_id = json_map["id"];
      auto container_destroy_answer =
          container_server.destroy_container(container_id);
      log_obj.write(container_destroy_answer);
      server.write(container_destroy_answer);
    } else if (action == "stop") {
      log_obj.write("stop");
      server.write("OK");
      break;
    } else {
      log.write("received: ", s);
    }
  }
  log.write("exiting");
  return 0;
}
