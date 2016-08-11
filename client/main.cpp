#include "main.h"

int main(int argc, char** argv) {
  optparse options(argc, argv);
  read_file file(options.get("json"));
  tcpclient client(options.get("host"), options.get("port"));
  std::string file_str = file.read();
  client.write_string(file_str);
  std::cout << client.read_string() << std::endl;
  return 0;
}
