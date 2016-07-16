#include "master.h"

master::master() : server_port(conf.get(std::string("port"))) {
  log_obj.write("starting master");
  log_obj.write("config: ../master/master.conf");
  log_obj.write("port: ", server_port);
}

int master::listen() {
  while (true) {
    tcpserver server(this->server_port);
    log_obj.write("listening");
    server.accept();
    log_obj.write("client connect");
    std::string s = server.read();
    json json_object(s);
    std::unordered_map<std::string, std::string> json_map =
        json_object.get_map();
    std::string action = json_map[std::string("action")];
    log_obj.write("client action:", action);
    std::string action_string = this->do_action(json_map);
    if (action_string == "exit"){
      return 0;
    }
    server.write(action_string);
  }
}

std::string master::do_action(
    std::unordered_map<std::string, std::string> json_map) {
  std::string return_string;
  std::string action = json_map["action"];
  if (action == std::string("add_slave")) {
    std::string slave_host_port(json_map["slave_host"] + ":" +
                                json_map["slave_port"]);
    store.set_slave(slave_host_port, json_map);
    log_obj.write("slave_add ", std::string(json_map["slave_host"] + ":" +
                                            json_map["slave_port"]));
    return_string = std::string("slave added");
  } 
  else if (action == std::string("remove_slave")){
    std::string slave_host_port(json_map["slave_host"] + ":" +
                                json_map["slave_port"]);
    store.remove_slave(slave_host_port);
    log_obj.write("slave_remove", std::string(json_map["slave_host"] + ":" + json_map["slave_port"]));
    return_string = std::string("slave removed");
  }
  else if (action == std::string("add_pod")) {
    std::string pod_name = json_map[std::string("pod_name")];
    store.set_pod(pod_name, json_map);
    log_obj.write("pod_add ", pod_name);
    return_string = std::string("pod added");
  }
  else if (action == std::string("remove_pod")){
    std::string pod_name = json_map[std::string("pod_name")];
    store.remove_pod(pod_name);
    log_obj.write("pod_remove ", pod_name);
    return_string = std::string("pod removed");
  }
  else if (action == std::string("stop")){
    log_obj.write("exit");
    return_string = std::string("exit");
  }
  return return_string;
}

master::~master() { log_obj.write("stopping master"); }
