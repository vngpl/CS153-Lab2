#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
  int i, pid;
  volatile int sum = 0;

  pid = fork();
  if (!pid) {
    setpriority(10);
    for (i = 0; i < 10000000; i++) {
      sum += i;
    }
    // exit();
  }
  if (pid) {
    for (i = 0; i < 100000000; i++) {
      sum += i;
    }
  }

  exit();
}