#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
  int pid = fork();

  if (!pid) {
    printf(1, "in child\n");
    setpriority(11);
  }
  if (pid) {
    wait();
    printf(1, "in parent\n");
    setpriority(9);
  }

  exit();
}