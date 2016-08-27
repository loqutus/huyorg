#include "master.h"

master::master()
    : server_port(conf.get(std::string("port"))),
      server_host(conf.get(std::string("host"))) {
  log_obj.write("starting master");
  log_obj.write("config: ../master/master.conf");
  log_obj.write("port: ", server_port);
  log_obj.write("host: ", server_host);
}

int master::listen() {
  while (true) {
    tcpserver server(server_host, server_port);
    server.listen();
    log_obj.write("listening");
    std::string s = server.read_string();
    log_obj.write("client connect");
    json json_object(s);
    std::unordered_map<std::string, std::string> json_map =
        json_object.get_map();
    std::string action = json_map[std::string("action")];
    log_obj.write("client action:", action);
    std::string action_string = do_action(json_map);
    // server.write_string(action_string);
    server.close();
    log_obj.write(action_string);
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
  } else if (action == std::string("remove_slave")) {
    std::string slave_host_port(json_map["slave_host"] + ":" +
                                json_map["slave_port"]);
    store.remove_slave(slave_host_port);
    log_obj.write("slave_remove", std::string(json_map["slave_host"] + ":" +
                                              json_map["slave_port"]));
    return_string = std::string("slave removed");
  } else if (action == std::string("add_pod")) {
    std::string pod_name = json_map[std::string("pod_name")];
    store.set_pod(pod_name, json_map);
    log_obj.write("pod_add ", pod_name);
    return_string = std::string("pod added");
  } else if (action == std::string("remove_pod")) {
    std::string pod_name = json_map[std::string("pod_name")];
    store.remove_pod(pod_name);
    log_obj.write("pod_remove ", pod_name);
    return_string = std::string("pod removed");
  } else if (action == std::string("stop")) {
    log_obj.write("exit");
    return_string = std::string("exit");
  }
  return return_string;
}

master::~master() { log_obj.write("stopping master"); }
