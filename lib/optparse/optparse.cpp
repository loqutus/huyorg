//
// Created by Ruslan Gustomyasov on 05/01/16.
//

#include "optparse.h"

optparse::optparse(int argc, char **argv) : desc("Options:") {
    std::string host;
    std::string port;
    std::string command;
    std::string config;
    std::string pod;
    desc.add_options()
            ("host", boost::program_options::value(&host)->default_value(std::string("::1")), "master host")
            ("port", boost::program_options::value(&port)->default_value(std::string("9999")), "master port")
            ("command", boost::program_options::value(&command), "command to execute: upload, run or stop")
            ("config", boost::program_options::value(&config), "pod config to upload")
            ("pod", boost::program_options::value(&pod), "pod name");
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);
}

std::string optparse::get(std::string optname) {
    if (vm.count(optname.c_str())) {
        return vm[optname.c_str()].as<std::string>();
    }
    else {
        return std::string("");
    }
}