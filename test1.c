#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void) {
  volatile int i, pid;
  volatile int sum = 0;

  pid = fork();
  if (!pid) {
    setpriority(10);
    for (i = 0; i < 10000000; i++) {
      sum += i;
    }
  }
  if (pid) {
    setpriority(1);
    for (i = 0; i < 10000000; i++) {
      sum += i;
    }
  }

  wait();
  exit();
}