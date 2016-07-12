#include "main.h"

storage store;
confreader conf("../master/master.conf");
logging log_obj(conf.get("log"));

void run_master() {
  master Master;
  Master.listen();
}

void run_watcher() {
  watcher Watcher;
  Watcher.watch();
}

void run_scheduler(){
  scheduler Scheduler;
  Scheduler.schedule();
}

int main(int argc, char **argv) {
  std::thread thread1(run_master);
  std::thread thread2(run_watcher);
  std::thread thread3(run_scheduler);
  thread1.join();
  thread2.join();
  thread3.join();
  return 0;
}
