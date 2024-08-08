#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
  int pid = fork();

  if (!pid) {
    printf(1, "in child\n");
    getprocinfo();
  }
  if (pid) {
    wait();
    printf(1, "in parent\n");
    getprocinfo();
  }

  exit();
}