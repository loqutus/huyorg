#include "main.h"

int main(int argc, char** argv) {
  const std::string conf_file("../test/slave.conf");
  confreader conf(conf_file);
  logging log_obj(conf.get(std::string("log")));
  log_obj.write("SLAVE: starting slave");
  const std::string listen_host = conf.get(std::string("host"));
  log_obj.write("SLAVE: listen_host", listen_host);
  const std::string listen_port = conf.get(std::string("port"));
  log_obj.write("SLAVE: listen_port", listen_port);
  const std::string docker_port = conf.get(std::string("docker_port"));
  log_obj.write("SLAVE: docker_port", docker_port);
  const std::string docker_host = conf.get(std::string("docker_host"));
  log_obj.write("SLAVE: docker_host", docker_host);
  while (true) {
    tcpserver server(listen_host, listen_port);
    log_obj.write("SLAVE: listening");
    std::string s = server.read_string();
    log_obj.write("SLAVE: master connected");
    json json_object(s);
    auto json_map = json_object.get_map();
    std::string action = json_map["action"];
    log_obj.write("SLAVE: action", action);
    if (action == "run_container") {
      container container_server(docker_host, docker_port);
      log_obj.write("SLAVE: run_container");
      std::string container_image = json_map["image"];
      log_obj.write("SLAVE: image:", container_image);
      std::string container_command = json_map["command"];
      log_obj.write("SLAVE: command:", container_command);
      std::string container_id =
          container_server.run_container(container_image, container_command);
      log_obj.write("SLAVE: container_id:", container_id);
      server.write_string(container_id);
    } else if (action == "get_containers") {
      container container_server(docker_host, docker_port);
      log_obj.write("SLAVE: get_containers");
      auto containers_list = container_server.get_containers();
      json json_containers_list(containers_list);
      auto containers_list_str = json_containers_list.get_string_from_list();
      log_obj.write("SLAVE: containers", containers_list_str);
      server.write_string(containers_list_str);
    } else if (action == "destroy_container") {
      container container_server(docker_host, docker_port);
      log_obj.write("SLAVE: destroy container");
      auto container_id = json_map["id"];
      auto container_destroy_answer =
          container_server.destroy_container(container_id);
      log_obj.write(container_destroy_answer);
      server.write_string(container_destroy_answer);
    } else if (action == "stop") {
      log_obj.write("SLAVE: stop");
      server.write_string("OK");
      break;
    } else {
      server.write_string("NONONONO");
      log_obj.write("SLAVE: received: ", s);
    }
  }
  log_obj.write("exiting");
  return 0;
}
