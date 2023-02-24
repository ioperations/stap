#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct proc {
  int id;
  char MyProcName[100];
};

__thread proc t_thrd;

void exec_simple_query() {
  for (int j = 0; j < 3; j++) {
    sleep(1);
    t_thrd.id += j;
    printf("%s\n", t_thrd.MyProcName);
  }
}
int main() {
  t_thrd.id = 100;
  strncpy(t_thrd.MyProcName, "test_thread_local", 9);
  exec_simple_query();
  exec_simple_query();
}
